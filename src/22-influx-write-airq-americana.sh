#!/bin/bash
#
# Author: rossano at gmail dot com
# Timestamp: Fri Jul 23 08:07:41 AM -03 2021

TOKEN="-RGqXfDNOdit4cpCvSarQqCPawRQoC5kuDKdQbrCyLhO_JiXtu1UgQoYhukzXZNUKaHE2-6Fbat8Gnexn0dmuA=="

influx write -o CPS -t $TOKEN -b 'iot' \
   'airq,node=192.168.15.73,city=americana dew=14,h=56,o3=15,p=270,pm10=13,t=18,w=5.7'

