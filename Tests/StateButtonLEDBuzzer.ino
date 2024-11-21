/*
  Button + LED + change state + Buzzer
  Turns an LED on and off button pressed
*/

int led = 13;
int button = 2;

int buttonState = 0;       // وضعیت فعلی کلید
int lastButtonState = 0;   // وضعیت قبلی کلید
int buttonFlag = 0;        // 0 = خاموش، 1 = روشن

unsigned long lastDebounceTime = 0;  // زمان آخرین تغییر وضعیت کلید
unsigned long debounceDelay = 50;    // تأخیر برای بانس (در میلی‌ثانیه)

void setup() {
  pinMode(led, OUTPUT);
  pinMode(button, INPUT);
}

void loop() {
  int reading = digitalRead(button);

  // بررسی تغییر وضعیت کلید با تأخیر بانس
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;
      
      if (buttonState == HIGH) {
        // تغییر حالت LED
        if(buttonFlag == 0) {
          digitalWrite(led, HIGH);
          buttonFlag = 1;
        }
        else {
          digitalWrite(led, LOW);
          buttonFlag = 0;
        }
      }
    }
  }

  // ثبت وضعیت فعلی کلید به عنوان وضعیت قبلی
  lastButtonState = reading;
}
