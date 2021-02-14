#!/usr/bin/env python3

from mako.template import Template
import argparse
import json
import os

def json_output():
    parser = argparse.ArgumentParser(
        description="Given a title, subtitle, x-axis label, y-axis label, chart path")
    parser.add_argument("title")
    parser.add_argument("subtitle")
    parser.add_argument("xlabel")
    parser.add_argument("ylabel")
    parser.add_argument("aspect")
    parser.add_argument("chart_template_path")
    parser.add_argument("output")

    args = parser.parser_args()

    options = {}
    options['TITLE'] = args.title
    options['SUBTITLE'] = args.subtitle
    options['XLABEL'] = args.xlabel
    options['YLABEL'] = args.ylabel
    aspect = args.aspect
    #data = [datum for datum in '${data}'.split(';') json.loads(datum)]
    html = Template(filename=args.chart_template_path)
    os.makedirs(args.output, exist_ok=True)
    html.render(template_args=options)
    
    IO.write(args.output, html)