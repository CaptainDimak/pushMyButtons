// Code to trigger properly debounced key presses over USB.
// USB type must be set to Keyboard.

// Include the Bounce2 library found here:
// https://github.com/thomasfredericks/Bounce2
#include <Bounce2.h>

// Set button pins for use later, diagram of how wiring matches in box included.
#define BUTTON_PIN_1 0
#define BUTTON_PIN_2 1
#define BUTTON_PIN_3 2
#define BUTTON_PIN_4 3
#define BUTTON_PIN_5 4
#define BUTTON_PIN_6 5

/* Physical button layout reference:
 * ┏━━━━━━━━┓
 * ┃ 1 2 3 ┃
 * ┃ 4 5 6 ┃
 * ┗━━━━━━━━┛
 */

// Define LED pin, 13 for Teensy LC
#define LED_PIN 13

// Instantiate Bounce objects for buttons
Bounce button1 = Bounce();
Bounce button2 = Bounce();
Bounce button3 = Bounce();
Bounce button4 = Bounce();
Bounce button5 = Bounce();
Bounce button6 = Bounce();

// Setup press status boolean
bool pressed = false;

// Define length of button bounce interval
int someMilliseconds = 20;

void setup() {

  // Setup the buttons with an internal pull-up
  pinMode(BUTTON_PIN_1, INPUT_PULLUP);
  // After setting up the button, setup the Bounce instance
  button1.attach(BUTTON_PIN_1);
  button1.interval(someMilliseconds); // interval in ms

  pinMode(BUTTON_PIN_2, INPUT_PULLUP);
  // After setting up the button, setup the Bounce instance
  button2.attach(BUTTON_PIN_2);
  button2.interval(someMilliseconds); // interval in ms

  pinMode(BUTTON_PIN_3, INPUT_PULLUP);
  // After setting up the button, setup the Bounce instance
  button2.attach(BUTTON_PIN_3);
  button2.interval(someMilliseconds); // interval in ms

  pinMode(BUTTON_PIN_4, INPUT_PULLUP);
  // After setting up the button, setup the Bounce instance
  button2.attach(BUTTON_PIN_4);
  button2.interval(someMilliseconds); // interval in ms

  pinMode(BUTTON_PIN_5, INPUT_PULLUP);
  // After setting up the button, setup the Bounce instance
  button2.attach(BUTTON_PIN_5);
  button2.interval(someMilliseconds); // interval in ms

  pinMode(BUTTON_PIN_6, INPUT_PULLUP);
  // After setting up the button, setup the Bounce instance
  button2.attach(BUTTON_PIN_6);
  button2.interval(someMilliseconds); // interval in ms

  // Setup the LED:
  pinMode(LED_PIN, OUTPUT);

}

void loop() {
  // Update the Bounce instances
  button1.update();
  button2.update();
  button3.update();
  button4.update();
  button5.update();
  button6.update();

  // Get the updated value
  int value1 = button1.read();
  int value2 = button2.read();
  int value3 = button2.read();
  int value4 = button2.read();
  int value5 = button2.read();
  int value6 = button2.read();

  // Turn on the LED if any button is pressed
  if (button1.fell() || button2.fell() || button3.fell() || button4.fell() || button5.fell() || button6.fell()) {
    digitalWrite(LED_PIN, HIGH);
    if (!pressed) {
      //Keyboard.press(KEY_TILDE); // for keypress debug
      pressed = true;
    }
  }
  else {
    digitalWrite(LED_PIN, LOW);
    if (pressed) {
      //Keyboard.release(KEY_TILDE); // for keypress debug
      pressed = false;
    }
  }

  // Prevent some edge case double presses that sneak past bounce2 (I think they're in USB) (oh well)
  delay(someMilliseconds);

}


