#!/bin/bash
#
# Author: rossano at gmail dot com
# Timestamp: Fri Jul 23 08:07:41 AM -03 2021

TOKEN="-RGqXfDNOdit4cpCvSarQqCPawRQoC5kuDKdQbrCyLhO_JiXtu1UgQoYhukzXZNUKaHE2-6Fbat8Gnexn0dmuA=="

influx query -o CPS -t=$TOKEN 'import "timezone" option location = timezone.location(name: "America/Sao_Paulo")
   from(bucket:"iot")
   |> range(start: 2022-07-21T23:00:00Z)'
