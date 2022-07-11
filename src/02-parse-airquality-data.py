#!/usr/bin/python
# -*- coding: latin-1 -*-
# Author: rossano at gmail dot com
# Timestamp: Sun Jul 11 05:38:36 PM -03 2021

import json

# JSON content
airquality='{"status":"ok","data":{"aqi":24,"idx":329,"attributions":[{"url":"http://www.cetesb.sp.gov.br/","name":"CETESB - Companhia Ambiental do Estado de São Paulo","logo":"Brazil-CETESB.png"},{"url":"https://waqi.info/","name":"World Air Quality Index Project"}],"city":{"geo":[-22.724506902,-47.347456368],"name":"Americana, São Paulo, Brazil","url":"https://aqicn.org/city/brazil/sao-paulo/americana"},"dominentpol":"pm10","iaqi":{"dew":{"v":15},"h":{"v":57},"o3":{"v":24},"p":{"v":1020},"pm10":{"v":24},"t":{"v":24},"w":{"v":3.6}},"time":{"s":"2021-04-15 11:00:00","tz":"-03:00","v":1618484400,"iso":"2021-04-15T11:00:00-03:00"},"forecast":{"daily":{"o3":[{"avg":12,"day":"2021-04-13","max":38,"min":2},{"avg":13,"day":"2021-04-14","max":41,"min":3},{"avg":11,"day":"2021-04-15","max":53,"min":3},{"avg":10,"day":"2021-04-16","max":51,"min":1},{"avg":15,"day":"2021-04-17","max":34,"min":4},{"avg":16,"day":"2021-04-18","max":44,"min":3}],"pm10":[{"avg":25,"day":"2021-04-13","max":35,"min":17},{"avg":28,"day":"2021-04-14","max":40,"min":13},{"avg":27,"day":"2021-04-15","max":40,"min":16},{"avg":41,"day":"2021-04-16","max":64,"min":19},{"avg":30,"day":"2021-04-17","max":63,"min":14},{"avg":45,"day":"2021-04-18","max":89,"min":15}],"pm25":[{"avg":50,"day":"2021-04-13","max":63,"min":44},{"avg":48,"day":"2021-04-14","max":69,"min":27},{"avg":49,"day":"2021-04-15","max":86,"min":23},{"avg":95,"day":"2021-04-16","max":152,"min":43},{"avg":73,"day":"2021-04-17","max":137,"min":34},{"avg":111,"day":"2021-04-18","max":171,"min":48}],"uvi":[{"avg":1,"day":"2021-04-13","max":6,"min":0},{"avg":2,"day":"2021-04-14","max":8,"min":0},{"avg":1,"day":"2021-04-15","max":8,"min":0},{"avg":1,"day":"2021-04-16","max":7,"min":0},{"avg":1,"day":"2021-04-17","max":7,"min":0},{"avg":1,"day":"2021-04-18","max":6,"min":0},{"avg":1,"day":"2021-04-19","max":4,"min":0}]}},"debug":{"sync":"2021-04-15T23:23:28+09:00"}}}'

aq = json.loads(airquality)
print(aq["data"]["dominentpol"])
