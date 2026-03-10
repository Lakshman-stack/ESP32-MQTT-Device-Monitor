\# ESP32 MQTT Device Monitoring System



\## Project Overview

This project implements an IoT device monitoring system using ESP32 and MQTT protocol.  

The ESP32 collects system information and publishes it to a cloud MQTT broker, allowing remote monitoring from any network.



\## Features

\- WiFi connectivity using ESP32

\- MQTT communication with cloud broker

\- JSON data publishing

\- Real-time device monitoring

\- Works across different WiFi networks



\## Parameters Monitored

The ESP32 publishes the following system data:



\- IP Address

\- WiFi Signal Strength (RSSI)

\- Free Heap Memory

\- Device Uptime



Example MQTT Message:



{

"IP":"192.168.1.10",

"RSSI":-55,

"Heap":230000,

"Uptime":120

}



\## System Architecture



ESP32 Device  

↓  

WiFi Network  

↓  

Internet  

↓  

MQTT Broker (HiveMQ)  

↓  

Laptop / Dashboard / MQTT Client  



\## Technologies Used

\- ESP32 Microcontroller

\- Arduino IDE

\- MQTT Protocol

\- HiveMQ Public Broker

\- PubSubClient Library



\## Hardware Requirements

\- ESP32 Development Board

\- USB Cable

\- WiFi Connection



\## Software Requirements

\- Arduino IDE

\- ESP32 Board Package

\- PubSubClient Library



\## How It Works

1\. ESP32 connects to WiFi.

2\. ESP32 connects to MQTT broker.

3\. Device information is collected.

4\. Data is sent to MQTT topic every 5 seconds.

5\. A laptop or dashboard subscribes to the topic to monitor data.



\## MQTT Broker Details



Broker:

broker.hivemq.com



Port:

1883



Topic:

esp32/monitor



\## Applications

\- IoT device monitoring

\- Remote system diagnostics

\- Smart infrastructure monitoring

\- Embedded device health monitoring



\## Author

Lakshman

