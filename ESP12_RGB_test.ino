/*
 * RGB LED test for ESP12 (ESP8266) NodeMCU.
 *  
 * NodeMCU | RGBLED
 * --------+-------  
 * D0      | R
 * D1      | B
 * D2      | G
 * 3.3V      | ANODE (via resistor)
 */

#define RRR D0
#define GGG D1
#define BBB D2

/*
 * Set up pins.
 */
void setup() {
  // Set our pins as outputs.
  pinMode(RRR, OUTPUT);
  pinMode(GGG, OUTPUT);
  pinMode(RRR, OUTPUT); 
}

/*
 * Cycle through the rainbow.
 */
void loop() {
  // Red.
  set_color(255, 0, 0);
  delay(2500);
  // Green.
  set_color(0, 255, 0);
  delay(2500);
  // Blue.
  set_color(0, 0, 255);
  delay(2500);
  // Orange.
  set_color(255, 255, 0);
  delay(2500);
  // Light blue.
  set_color(0, 255, 255);
  delay(2500);
  // Pink.
  set_color(255, 0, 255);
  delay(2500);
}

/*
 * Set a colour given a set of RGB values.
 */
void set_color(unsigned int red, unsigned int green, unsigned int blue)
{
  // Define a max value as we're using a shared anode RGB LED.
  int maxVal = 1023;

  // Define a correction factor so we can always use 0-255 as input values.
  int f = (maxVal + 1) / 256;
  
  // Deduct values from max value.
  red = maxVal - red * f;
  green = maxVal - green * f;
  blue = maxVal - blue * f;

  // Write our values.
  analogWrite(RRR, red);
  analogWrite(GGG, green);
  analogWrite(BBB, blue);  
}
