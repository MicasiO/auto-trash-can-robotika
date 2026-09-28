# Problem
As we age, various tasks that require back/spine maneuvers inflict more and more pain. Some tasks are so simple, that, in this day and age, there is no reason not to automate and simplify them. One of the these tasks being - trashcan opening to get rid of rubbish.

# Design
The design of the automatic trashcan is straightforward. It contains an ultrasonic sensor, which can detect and report the distance between itself and an object. When the sensor reports a short enough distance, the signal is sent to a servo motor, which rotates 90 degrees, forcing the lid open that is connected to it. When the ultrasonic sensor detects the user walking away from the trashcan, the lid automatically closes. There is a second ultrasonic sensor attached to the back of the lid, looking down into the rubbish inside the trashcan. Its purpose is to detect how close the rubbish is to the top, sending a signal to three LEDs based on the fullness of the trashcan - green (empty or almost empty), orange (half full) and red (full or almost full).

# Parts list
- 2 x Ultrasonic Distance Sensor (4-pin)
- 3 x 220 ohm resistors for LEDs
- 1 x Micro Servo motor
- 19 x jump wires
- 1 x Arduino UNO R3
- 1 x Small Breadboard

# Schemmatic
