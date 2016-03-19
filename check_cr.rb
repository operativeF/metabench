#!/usr/bin/env ruby

STDERR.print("line1")
sleep 2
STDERR.print("\r\rline2")
STDERR.print("\n")
STDERR.print("foo\\rbar")
