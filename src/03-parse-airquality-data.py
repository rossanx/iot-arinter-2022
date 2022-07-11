#!/usr/bin/python
# -*- coding: latin-1 -*-
# Author: rossano at gmail dot com
# Timestamp: Sun Jul 11 05:38:36 PM -03 2021

import json
import sys

if len(sys.argv) != 2:
   print(f"  Usage: {sys.argv[0]} _FILENAME_")
   print(f"  Example: {sys.argv[0]} ../data/americana-airquality.json")
   exit()
   
with open(sys.argv[1]) as reader:
    airquality=reader.read()

aq = json.loads(airquality)
print(aq["data"]["dominentpol"])
