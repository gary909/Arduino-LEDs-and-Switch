// Pin definitions
const int redLED = 10;
const int greenLED = 12;
const int buttonPin = 9;

bool isRunning = true;  // Variable to track the state of the LEDs
bool lastButtonState = LOW; // Variable to store the last button state

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pins as outputs.
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP); // initialize the push button pin as an input with an internal pull-up resistor
}

// the loop function runs over and over again forever
void loop() {
  // Read the current state of the button
  bool buttonState = digitalRead(buttonPin);

  // Check if the button was pressed
  if (buttonState == LOW && lastButtonState == HIGH) {
    // Toggle the state of the LEDs
    isRunning = !isRunning;
    // Debounce delay
    delay(50);
  }

  // Update the last button state
  lastButtonState = buttonState;

  if (isRunning) {
    digitalWrite(redLED, HIGH);   // turn the red LED on
    delay(1000);                  // wait for a second
    digitalWrite(redLED, LOW);    // turn the red LED off

    digitalWrite(greenLED, HIGH);  // turn the green LED on
    delay(1000);                   // wait for a second
    digitalWrite(greenLED, LOW);   // turn the green LED off
  } else {
    digitalWrite(redLED, LOW);    // ensure red LED is off
    digitalWrite(greenLED, LOW);  // ensure green LED is off
  }
}
