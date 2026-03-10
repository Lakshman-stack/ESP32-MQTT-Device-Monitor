# ESP32 MQTT Device Monitoring System

## Project Overview
This project implements an IoT device monitoring system using ESP32 and MQTT protocol.  
The ESP32 collects device information and publishes it to a cloud MQTT broker.

## Features
- WiFi connectivity
- MQTT communication
- JSON data publishing
- Real-time device monitoring

## Parameters Monitored
- IP Address
- WiFi RSSI
- Free Heap Memory
- Device Uptime

Example MQTT message:

{
"IP":"192.168.1.10",
"RSSI":-55,
"Heap":230000,
"Uptime":120
}

## System Architecture

ESP32 → WiFi → Internet → MQTT Broker → Laptop Dashboard

## Technologies Used
- ESP32
- Arduino IDE
- MQTT Protocol
- HiveMQ Broker
- PubSubClient Library
