#!/usr/bin/env ruby

$stdout.print("line1")
sleep 2
$stdout.print("\r\rline2")
$stdout.print("\n")
$stdout.print("foo\rbar")
$stdout.print("foobar\b\b\bbaz")
