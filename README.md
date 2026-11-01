# Smart Home Automation System

## Objective
Design a basic smart home automation system using an ESP32 and IoT sensors that monitors the environment and controls appliances automatically.

## Hardware / Software
- ESP32 DevKit (simulated on Wokwi)
- DHT22 temperature and humidity sensor
- LDR (photoresistor) light sensor
- PIR motion sensor
- LEDs (representing relay-controlled Light and Fan)
- Wokwi simulator, DHT sensor library

## Pin Mapping
| Component | ESP32 Pin |
|-----------|-----------|
| DHT22 data | GPIO 15 |
| LDR analog out | GPIO 34 |
| PIR out | GPIO 13 |
| Light (yellow LED) | GPIO 26 |
| Fan (blue LED) | GPIO 27 |

## Workflow
1. Sensors are read every second.
2. If it is dark and motion is detected, the light turns ON (stays on for 10 s after the last motion).
3. If temperature is above 30 C, the fan turns ON.
4. All readings and states are printed to the Serial Monitor.

## How to Run
1. Open Wokwi and create a new ESP32 project.
2. Paste `circuit/diagram.json` and `code/sketch.ino`.
3. Add the DHT sensor library and start the simulation.

## Folder Structure
- `code/` - source code
- `circuit/` - circuit diagram file and screenshot

## Output


![Circuit](circuit/circuit.png)



## Experience and Suggestions
Great hands-on practice with sensor integration, automation logic and simulation.
