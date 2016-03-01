# Copyright Louis Dionne 2016
# Distributed under the Boost Software License, Version 1.0.
# (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

require 'benchmark'
require 'open3'
require 'pathname'
require 'ruby-progressbar'
require 'tempfile'
require 'tilt/erb'


# This function is meant to be called inside a ERB-based `chart.json` file.
# `erb_template` should be the name of the `.cpp` file containing the
# benchmark to run.
def measure(erb_template, range, cxx: ENV['CXX'], cxxflags: ENV['CXXFLAGS'], env: {})
  raise "invalid `cxx` parameter (#{cxx})" if not cxx
  range = range.to_a

  # if ENV["BOOST_HANA_JUST_CHECK_BENCHMARKS"] && range.length >= 2
  #   range = [range[0], range[-1]]
  # end

  progress = ProgressBar.create(format: '%p%% %t | %B |', title: erb_template,
                                total: range.size,        output: STDERR)
  range.each do |n|
    # Evaluate the ERB template with the given environment, and save the
    # result in a temporary file.
    code = Tilt::ERBTemplate.new(erb_template).render(nil, n: n, env: env)
    Tempfile.create(['tmp', '.cpp'], Dir.pwd) do |cpp_file|
      begin
        # We create exe_file and close it explicitly because if the compilation
        # fails and the exe_file is deleted by the compiler, we'll raise an
        # error but Tempfile.create will re-raise an error while trying to
        # remove the nonexistent file.
        exe_file = Tempfile.new(['tmp', '.o'], Dir.pwd)
        cpp_file.write(code) && cpp_file.flush
        data = {n: n}

        # Compile the file and gather timing statistics. The timing statistics
        # are output to stdout when we compile the file.
        data[:time] = Benchmark.realtime {
          command = "#{cxx} #{cxxflags} -o #{exe_file.path} #{cpp_file.path}"
          stdout, stderr, status = Open3.capture3(command)

          error_string = <<-EOS
compilation error: #{command}

stdout
#{'-'*80}
#{stdout}

stderr
#{'-'*80}
#{stderr}

code
#{'-'*80}
#{code}
EOS
          raise error_string if not status.success?
        }

        # Size of the generated executable in KB
        data[:size] = exe_file.size.to_f / 1000

        progress.increment
        yield data

      ensure
        exe_file.close!
      end
    end
  end
ensure
  progress.finish if progress
end

def measure_compile_time(relative_path_to_erb_template, range, **options)
  result = []
  measure(relative_path_to_erb_template, range, **options) do |data|
    result << [data[:n], data[:time]]
  end
  return result
end

def measure_exe_size(relative_path_to_erb_template, range, **options)
  result = []
  measure(relative_path_to_erb_template, range, **options) do |data|
    result << [data[:n], data[:size]]
  end
  return result
end
