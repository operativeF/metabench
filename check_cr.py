#!/usr/bin/env python

import sys

sys.stdout.write("line1")
sys.stdout.write("\rline2")
sys.stdout.write("\n")
sys.stdout.write("foo\rbar")
sys.stdout.write("foobar\b\b\bbaz")
