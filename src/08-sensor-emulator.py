#!/usr/bin/python
# -*- coding: latin-1 -*-
# Author: rossano at gmail dot com
# Timestamp: Sun Jul 11 05:38:36 PM -03 2021

import paho.mqtt.client as mqtt
import time
from random import seed
from random import uniform

def read_sensor_value():
        value = str(round(uniform(15,20),2))
        return value;

def on_connect(cli, data, flags, result):
	print("Connected: "+str(result))

def on_message(cli, data, msg):
 	print(msg.topic+" "+str(msg.payload))

cli = mqtt.Client()
cli.on_connect = on_connect
cli.on_message = on_message

cli.connect('broker.hivemq.com', 1883, 60)

seed(1)

while True:
	x=read_sensor_value()
	value=x+":c"
	print("Sending",value,"to the broker")
	cli.publish('arinter/americana/rossano/temp', value)
	time.sleep(60)

	