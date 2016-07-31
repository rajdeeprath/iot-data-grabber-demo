# iot-data-grabber-demo

Demonstrates grabbing data from an IOT device using Red5pro server api. Temperature and humidity data are captured into your red5 application code via the Red5pro api service.


### RED5 SERVER SIDE PROJECT: - data-grabber

Contains Red5 / Red5pro project for receieving sensor data from arduino client. The project is a simple maven based Red5 project which can be loaded into Eclipse IDE. You can then compile the project into a war or publish to a Red5pro server isntallation on your system to run  / debug.


### ARDUINO CLIENT PROJECT: - red5pro_sensor_client


Contains a standard Arduino sketch for grabbing data from a DHT11 sensor and posting to Red5 pro api service using Ethernet shield and Ethernet library code.


### ARDUINO CLIENT PROJECT: - Arduino/libraries/DHT

DHT11 library has been included (Library is developed by its own developer. Credits to original developer of the library).
**Arduino/libraries/DHT**.The entire DHT folder much be copied to your Arduino/libraries folder. Arduino IDE must be restarted.

