#!/bin/bash
#
# Author: rossano at gmail dot com
# Timestamp: Fri Jul 23 08:07:41 AM -03 2021

TOKEN="-RGqXfDNOdit4cpCvSarQqCPawRQoC5kuDKdQbrCyLhO_JiXtu1UgQoYhukzXZNUKaHE2-6Fbat8Gnexn0dmuA=="

influx query -o CPS -t $TOKEN 'from(bucket:"iot")
     |> range(start:-10d, stop:-8m)
     |> filter(fn: (r) => r._measurement == "airqualityAmericana" and
                          r.node == "192.168.15.73" and
                          r._field == "pm10" and r._value == 60)'

