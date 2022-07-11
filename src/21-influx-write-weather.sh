#!/bin/bash
#
# Author: rossano at gmail dot com
# Timestamp: Fri Jul 23 08:07:41 AM -03 2021

TOKEN="-RGqXfDNOdit4cpCvSarQqCPawRQoC5kuDKdQbrCyLhO_JiXtu1UgQoYhukzXZNUKaHE2-6Fbat8Gnexn0dmuA=="

influx write -o CPS -t $TOKEN -b 'iot' \
       'weather,node=192.168.15.73 temperature=10,humidity=45,luminosity=876'

