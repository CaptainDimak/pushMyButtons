// Code to trigger properly debounced key presses over USB.
// USB type must be set to Keyboard.

// Include the Bounce2 library found here:
// https://github.com/thomasfredericks/Bounce2
#include <Bounce2.h>

// Set button pins for use later, diagram of how wiring matches in box included.

#define BUTTON_PIN_0 0
#define BUTTON_PIN_1 1
#define BUTTON_PIN_2 2
#define BUTTON_PIN_3 3
#define BUTTON_PIN_4 4
#define BUTTON_PIN_5 5

/* Physical button layout reference:
 * ┏━━━━━━━━┓
 * ┃ 0 2 4 ┃
 * ┃ 1 3 5 ┃
 * ┗━━━━━━━━┛
 */

// Define LED pin, 13 for Teensy LC
#define LED_PIN 13

// Instantiate Bounce objects for buttons

Bounce button0 = Bounce();
Bounce button1 = Bounce();
Bounce button2 = Bounce();
Bounce button3 = Bounce();
Bounce button4 = Bounce();
Bounce button5 = Bounce();

// Setup press status boolean
bool pressed = false;

// Define length of button bounce interval
int someMilliseconds = 20;

void setup() {

  // Setup the buttons with an internal pull-up
  pinMode(BUTTON_PIN_0, INPUT_PULLUP);
  button0.attach(BUTTON_PIN_0); // setup the Bounce instance
  button0.interval(someMilliseconds); // interval in ms

  pinMode(BUTTON_PIN_1, INPUT_PULLUP);
  button1.attach(BUTTON_PIN_1); // setup the Bounce instance
  button1.interval(someMilliseconds); // interval in ms

  pinMode(BUTTON_PIN_2, INPUT_PULLUP);
  button2.attach(BUTTON_PIN_2); // setup the Bounce instance
  button2.interval(someMilliseconds); // interval in ms

  pinMode(BUTTON_PIN_3, INPUT_PULLUP);
  button3.attach(BUTTON_PIN_3); // setup the Bounce instance
  button3.interval(someMilliseconds); // interval in ms

  pinMode(BUTTON_PIN_4, INPUT_PULLUP);
  button4.attach(BUTTON_PIN_4); // setup the Bounce instance
  button4.interval(someMilliseconds); // interval in ms

  pinMode(BUTTON_PIN_5, INPUT_PULLUP);
  button5.attach(BUTTON_PIN_5); // setup the Bounce instance
  button5.interval(someMilliseconds); // interval in ms

  // Setup the LED:
  pinMode(LED_PIN, OUTPUT);

}

void loop() {
  // Update the Bounce instances

  button0.update();
  button1.update();
  button2.update();
  button3.update();
  button4.update();
  button5.update();

  // Get the updated value
  int value0 = button0.read();
  int value1 = button1.read();
  int value2 = button2.read();
  int value3 = button2.read();
  int value4 = button2.read();
  int value5 = button2.read();

  // Turn on the LED if any button is pressed
  if (button0.fell() ||button1.fell() || button2.fell() || button3.fell() || button4.fell() || button5.fell()) {
    digitalWrite(LED_PIN, HIGH);
    if (!pressed) {
      //Keyboard.press(KEY_TILDE); // for keypress debug
      pressed = true;
    }
  }
  else if (button0.rose() ||button1.rose() || button2.rose() || button3.rose() || button4.rose() || button5.rose()) {
    digitalWrite(LED_PIN, LOW);
    if (pressed) {
      //Keyboard.release(KEY_TILDE); // for keypress debug
      pressed = false;
    }
  }

}
