// Code to trigger properly debounced key presses over USB.
// USB type must be set to Keyboard.

// Include the Bounce2 library found here
// https://github.com/thomasfredericks/Bounce2
#include <Bounce2.h>

// Setup button pins
#define BUTTON_PIN_0 0
#define BUTTON_PIN_1 1
#define BUTTON_PIN_2 2
#define BUTTON_PIN_3 3
#define BUTTON_PIN_4 4
#define BUTTON_PIN_5 5

/* Physical button layout reference
   ┏━━━━━━━━┓
   ┃ 0 2 4 ┃
   ┃ 1 3 5 ┃
   ┗━━━━━━━━┛

   Buttons that are pressed are CTRL-SHIFT-KEYPAD#, with # being 0 to 5.

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

// Setup press status booleans
bool pressed = false; // uncomment for testing
bool pressed0 = false;
bool pressed1 = false;
bool pressed2 = false;
bool pressed3 = false;
bool pressed4 = false;
bool pressed5 = false;

// Define length of button bounce interval
int bounceInterval = 20;

void setup() {

  // Setup the buttons with an internal pull-up
  pinMode(BUTTON_PIN_0, INPUT_PULLUP);
  button0.attach(BUTTON_PIN_0); // setup the Bounce instance
  button0.interval(bounceInterval); // interval in ms

  pinMode(BUTTON_PIN_1, INPUT_PULLUP);
  button1.attach(BUTTON_PIN_1); // setup the Bounce instance
  button1.interval(bounceInterval); // interval in ms

  pinMode(BUTTON_PIN_2, INPUT_PULLUP);
  button2.attach(BUTTON_PIN_2); // setup the Bounce instance
  button2.interval(bounceInterval); // interval in ms

  pinMode(BUTTON_PIN_3, INPUT_PULLUP);
  button3.attach(BUTTON_PIN_3); // setup the Bounce instance
  button3.interval(bounceInterval); // interval in ms

  pinMode(BUTTON_PIN_4, INPUT_PULLUP);
  button4.attach(BUTTON_PIN_4); // setup the Bounce instance
  button4.interval(bounceInterval); // interval in ms

  pinMode(BUTTON_PIN_5, INPUT_PULLUP);
  button5.attach(BUTTON_PIN_5); // setup the Bounce instance
  button5.interval(bounceInterval); // interval in ms

  // Setup the LED
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
  int value3 = button3.read();
  int value4 = button4.read();
  int value5 = button5.read();

  // Check if a specific button is pressed, and press keys on keyboard
  if (button0.fell() && !pressed0) {
    Keyboard.set_modifier(MODIFIERKEY_ALT | MODIFIERKEY_SHIFT);
    Keyboard.press(KEY_0);
    pressed0 = true;
  } else if (button1.fell() && !pressed1) {
    Keyboard.set_modifier(MODIFIERKEY_ALT | MODIFIERKEY_SHIFT);
    Keyboard.press(KEY_1);
    pressed1 = true;
  } else if (button2.fell() && !pressed2) {
    Keyboard.set_modifier(MODIFIERKEY_ALT | MODIFIERKEY_SHIFT);
    Keyboard.press(KEY_2);
    pressed2 = true;
  } else if (button3.fell() && !pressed3) {
    Keyboard.set_modifier(MODIFIERKEY_ALT | MODIFIERKEY_SHIFT);
    Keyboard.press(KEY_3);
    pressed3 = true;
  } else if (button4.fell() && !pressed4) {
    Keyboard.set_modifier(MODIFIERKEY_ALT | MODIFIERKEY_SHIFT);
    Keyboard.press(KEY_4);
    pressed4 = true;
  } else if (button5.fell() && !pressed5) {
    Keyboard.set_modifier(MODIFIERKEY_ALT | MODIFIERKEY_SHIFT);
    Keyboard.press(KEY_5);
    pressed5 = true;

  // Check if buttons have been released, and release buttons on keyboard
  } else if (button0.rose() && pressed0) {
    Keyboard.set_modifier(0);
    Keyboard.release(KEY_0);
    pressed0 = false;
  } else if (button1.rose() && pressed1) {
    Keyboard.set_modifier(0);
    Keyboard.release(KEY_1);
    pressed1 = false;
  } else if (button2.rose() && pressed2) {
    Keyboard.set_modifier(0);
    Keyboard.release(KEY_2);
    pressed2 = false;
  } else if (button3.rose() && pressed3) {
    Keyboard.set_modifier(0);
    Keyboard.release(KEY_3);
    pressed3 = false;
  } else if (button4.rose() && pressed4) {
    Keyboard.set_modifier(0);
    Keyboard.release(KEY_4);
    pressed4 = false;
  } else if (button5.rose() && pressed5) {
    Keyboard.set_modifier(0);
    Keyboard.release(KEY_5);
    pressed5 = false;
  }

}
