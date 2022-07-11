#!/bin/bash
#
# Author: rossano at gmail dot com
# Timestamp: Sun Jul 11 05:38:36 PM -03 2021

mosquitto_pub -h broker.hivemq.com -p 1883 -t 'arinter/americana/rossano/temp' -m '19.0:c'
