// Include the Bounce2 library found here :
// https://github.com/thomasfredericks/Bounce2
#include <Bounce2.h>

// Set button pins for use later, diagram of how wiring matches in box included.
#define BUTTON_PIN_1 0
#define BUTTON_PIN_2 1
#define BUTTON_PIN_3 2
#define BUTTON_PIN_4 3
#define BUTTON_PIN_5 4
#define BUTTON_PIN_6 5

/* Physical Button Layout
 * ---------
 * | 1 2 3 |
 * | 4 5 6 |
 * ---------
 */

#define LED_PIN 13

// Instantiate Bounce objects for buttons
Bounce button1 = Bounce();
Bounce button2 = Bounce();
Bounce button3 = Bounce();
Bounce button4 = Bounce();
Bounce button5 = Bounce();
Bounce button6 = Bounce();


void setup() {

  // Setup the first button with an internal pull-up :
  pinMode(BUTTON_PIN_1, INPUT_PULLUP);
  // After setting up the button, setup the Bounce instance :
  button1.attach(BUTTON_PIN_1);
  button1.interval(5); // interval in ms

  // Setup the second button with an internal pull-up :
  pinMode(BUTTON_PIN_2, INPUT_PULLUP);
  // After setting up the button, setup the Bounce instance :
  button2.attach(BUTTON_PIN_2);
  button2.interval(5); // interval in ms


  //Setup the LED :
  pinMode(LED_PIN, OUTPUT);

}

void loop() {
  // Update the Bounce instances :
  debouncer1.update();
  debouncer2.update();

  // Get the updated value :
  int value1 = debouncer1.read();
  int value2 = debouncer2.read();

  // Turn on the LED if either button is pressed :
  if (button1.fell()) {
    digitalWrite(LED_PIN, HIGH );
    Keyboard.press(KEY_TILDE);
  }
  else {
    digitalWrite(LED_PIN, LOW );
  }
  Keyboard.release(KEY_TILDE);

}


