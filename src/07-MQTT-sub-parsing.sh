#!/bin/bash
#
# Author: rossano at gmail dot com
# Timestamp: Sun Jul 11 05:38:36 PM -03 2021

mosquitto_sub -h broker.hivemq.com -p 1883 -t 'arinter/americana/rossano/temp' | while read temp; do
    t=$(echo $temp | cut -d':' -f1);
    s=$(echo $temp | cut -d':' -f2);
    echo TEMP: $t;
    echo SCALE: $s;
done
