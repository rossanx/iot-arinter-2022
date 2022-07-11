#!/bin/bash
#
# Author: rossano at gmail dot com
# Timestamp: Fri Jul 23 08:07:41 AM -03 2021

TOKEN="-RGqXfDNOdit4cpCvSarQqCPawRQoC5kuDKdQbrCyLhO_JiXtu1UgQoYhukzXZNUKaHE2-6Fbat8Gnexn0dmuA=="

influx query -o CPS -t $TOKEN 'from(bucket:"iot")
   |> range(start: 2021-07-19T16:00:00Z)'
