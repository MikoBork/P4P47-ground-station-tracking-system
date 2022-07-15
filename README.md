# P4P47-ground-station-tracking-system
Software implemented in Satellite Antenna Ground Station Tracking System for XY pedestal mount to allow directional antenna pointing. Takes input Az-El data and converts it into X, Y axis rotation with PID controller for position and velocity.

# Software Required:
- AccelStepper library (http://www.airspayce.com/mikem/arduino/AccelStepper/index.html)
- PID_v1 library (https://github.com/br3ttb/Arduino-PID-Library)
- Wire library 
- Gpredict (Az-El coords)
- Hamlib (interface PC to Arduino)

# Code:
- Base file: "p4p47-ground-station-tracking-system.ino"

# References:
https://wiki.satnogs.org/SatNOGS_Arduino_Uno/CNC_Shield_Based_Rotator_Controller
(https://gitlab.com/Quartapound/satnogs-rotator-firmware/-/blob/master/README.md)

https://wiki.satnogs.org/SatNOGS_Rotator_Controller
