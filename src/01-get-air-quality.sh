#!/bin/bash
#
# Author: rossano at gmail dot com
# Timestamp: Sun Jul 11 05:38:36 PM -03 2021

CITY=americana
TOKEN=YOUR_TOKEN_HERE
FILENAME=../data/${CITY}-air-quality.json

if [ ${TOKEN} == "YOUR_TOKEN_HERE" ]; then
   echo "  1 - Go to http://aqicn.org/data-platform/token/#/ and obtain a token."
   echo "  2 - Open this file and replace YOUR_TOKEN with the token you have"
   echo "      received from the site."
else
   curl https://api.waqi.info/feed/${CITY}/?token=${TOKEN} -o ${FILENAME}
   echo "File wrote to ${FILENAME}"
fi
