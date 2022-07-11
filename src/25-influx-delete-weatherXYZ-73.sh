#!/bin/bash
#
# Author: rossano at gmail dot com
# Timestamp: Fri Jul 23 08:07:41 AM -03 2021

TOKEN="-RGqXfDNOdit4cpCvSarQqCPawRQoC5kuDKdQbrCyLhO_JiXtu1UgQoYhukzXZNUKaHE2-6Fbat8Gnexn0dmuA=="

echo "Deleting _measurement=\"weatherXYZ\" and node=\"192.168.15.73\""

influx delete -o CPS -t $TOKEN --bucket 'iot' \
   --start 2021-07-22T00:00:00Z --stop 2021-07-24T23:59:59Z \
   --predicate '_measurement="weatherXYZ" and node="192.168.15.73"'



