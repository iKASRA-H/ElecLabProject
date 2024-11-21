/*
  Button + LED
  Turns an LED on and off button pressed or released
*/

int led = 13;
int button = 2;

int buttonState = 0;  // variable for reading the pushbutton status

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(led, OUTPUT);
  pinMode(button, INPUT);
}

// the loop function runs over and over again forever
void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(button);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(led, HIGH);
  }
  else {
    // turn LED off:
    digitalWrite(led, LOW);
  }
}
