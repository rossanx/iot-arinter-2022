#!/bin/bash
#
# Author: rossano at gmail dot com
# Timestamp: Thu Jul 21 09:57:03 PM -03 2022

TOKEN="-RGqXfDNOdit4cpCvSarQqCPawRQoC5kuDKdQbrCyLhO_JiXtu1UgQoYhukzXZNUKaHE2-6Fbat8Gnexn0dmuA=="

influx write -o CPS -t=$TOKEN -b 'iot' \
       'airqualityAmericana,node=192.168.15.73 dew=14,h=56,o3=15,p=270,pm10=13,t=18,w=5.7'

