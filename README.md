# HC04---distance-sensor
2 ways to use the HC04 sensor.

HC04_RGB_CHANGES
Key Details
Sensor Connections:

TrigPin (Pin 7): Sends a 10-microsecond pulse to trigger the sensor.
EchoPin (Pin 8): Receives the reflected pulse and calculates the distance.
Distance to Brightness Mapping:

The map() function converts distances (2–37 cm) into LED brightness levels (0–255).
Closer Distance: Brighter LEDs.
Farther Distance: Dimmer LEDs.
Out of Range (less than 2 cm or more than 40 cm): LEDs are off.
Out-of-Range Handling:

Distances outside 2–40 cm are ignored, and brightness is set to 0.


The second file, called "HC04_RGB_LED" will change the the color of ONE RGC LED. it connects with 4 legs (3 colors and GND).
More over, you can use it with 3 differen LEDs that will turn on in different distances.
Key Details

Sensor Connections:
TrigPin (Pin 7): Triggers the ultrasonic sensor.
EchoPin (Pin 8): Receives the reflected pulse to calculate distance.

Distance-Based LED Control:
< 10 cm: LED on FRSled (Pin 9) lights up.
10–20 cm: LED on SCDled (Pin 11) lights up.
20–30 cm: LED on TRDled (Pin 12) lights up.
> 30 cm or no object detected: All LEDs turn off.

Behavior:
LEDs indicate the range in which the detected object is located.
The brightness of each LED is set to 225 when active.


good luck!
