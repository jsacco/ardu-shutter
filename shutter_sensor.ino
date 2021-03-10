// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// variable to hold sensor value
int sensorValue;
// variable to calibrate low value
int sensorLow = 1023;
// variable to calibrate high value
int sensorHigh = 0;
// LED pin
const int ledPin = 13;
unsigned long
startMillis; // some global variables available anywhere in the program
unsigned long currentMillis;
const unsigned long max_time = 5000; // the value is a number of milliseconds
const unsigned long s1 = 1000;       // the value is a number of milliseconds
const unsigned long s2 = 500;        // the value is a number of milliseconds
const unsigned long s4 = 250;        // the value is a number of milliseconds
const unsigned long s8 = 125;        // the value is a number of milliseconds
const unsigned long s15 = 66;        // the value is a number of milliseconds
const unsigned long s30 = 33;        // the value is a number of milliseconds
const unsigned long s60 = 16;        // the value is a number of milliseconds
const unsigned long s125 = 8;        // the value is a number of milliseconds
const unsigned long s250 = 4;        // the value is a number of milliseconds
const unsigned long s500 = 2;        // the value is a number of milliseconds
const unsigned long s1000 = 1;       // the value is a number of milliseconds

void setup() {
  Serial.begin(115200);
  while (!Serial) {

    ; // wait for serial port to connect. Needed for native USB port only
  }

  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Ardur Shutter M.");
  lcd.setCursor(0, 1);
  lcd.print("by Juan Sacco");b  bzb  bz
  // Make the LED pin an output and turn it on
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
  Serial.println("Starting calibration, please wait..");

  // calibrate for the first five seconds after program runs
  while (millis() < 5000) {
    // record the maximum sensor value
    sensorValue = analogRead(A0);
    if (sensorValue > sensorHigh) {
      sensorHigh = sensorValue;
    }
    // record the minimum sensor value
    if (sensorValue < sensorLow) {
      sensorLow = sensorValue;
    }
  }
  Serial.println("Calibration succeded!");
  Serial.print("Lowest: ");
  Serial.println(sensorLow);
  Serial.print("Highest: ");
  Serial.println(sensorHigh);
  // turn the LED off, signaling the end of the calibration period
  digitalWrite(ledPin, LOW);
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 0);

  int backLight = 13;
  pinMode(backLight, HIGH);
  while (analogRead(A0) > sensorHigh) {
    // Serial.write(13);

    Serial.println("Shutter open");
    Serial.print("Current: ");
    Serial.println(analogRead(A0));
    Serial.print("Higher: ");
    Serial.println(sensorHigh);

    // ElapsedTime
    currentMillis = millis(); // get the current "time" (actually the number of
                              // milliseconds since the program started)

    if (currentMillis - startMillis >= max_time) // Reset every 1 sec
    {
      startMillis = currentMillis;
    }
    if ((currentMillis - startMillis >= s1000) &&
        (currentMillis - startMillis <= s500)) // Reset every 1 sec
    {
      lcd.println("Shutter time 1/1000: "+currentMillis - startMillis);
      Serial.print("Shutter time 1/1000: ");
      Serial.println(currentMillis - startMillis);
    }
    if ((currentMillis - startMillis >= s500) &&
        (currentMillis - startMillis <= s250)) // Reset every 1 sec
    {
            lcd.println("Shutter time 1/500: "+currentMillis - startMillis);

      Serial.print("Shutter time 1/500: ");
      Serial.println(currentMillis - startMillis);
    }
    if ((currentMillis - startMillis >= s250) &&
        (currentMillis - startMillis <= s125)) // Reset every 1 sec
    {
                  lcd.println("Shutter time 1/250: "+currentMillis - startMillis);

      Serial.print("Shutter time 1/250: ");
      Serial.println(currentMillis - startMillis);
    }
    if ((currentMillis - startMillis >= s125) &&
        (currentMillis - startMillis <= s60)) // Reset every 1 sec
    {
                  lcd.println("Shutter time 1/125: "+currentMillis - startMillis);

      Serial.print("Shutter time 1/125: ");
      Serial.println(currentMillis - startMillis);
    }
    if ((currentMillis - startMillis >= s60) &&
        (currentMillis - startMillis <= s30)) // Reset every 1 sec
    {
                  lcd.println("Shutter time 1/60: "+currentMillis - startMillis);

      Serial.print("Shutter time 1/60: ");
      Serial.println(currentMillis - startMillis);
    }
    if ((currentMillis - startMillis >= s30) &&
        (currentMillis - startMillis <= s15)) // Reset every 1 sec
    {
                  lcd.println("Shutter time 1/30: "+currentMillis - startMillis);

      Serial.print("Shutter time 1/30: ");
      Serial.println(currentMillis - startMillis);
    }
    if ((currentMillis - startMillis >= s15) &&
        (currentMillis - startMillis <= s8)) // Reset every 1 sec
    {
                  lcd.println("Shutter time 1/15: "+currentMillis - startMillis);

      Serial.print("Shutter time 1/15: ");
      Serial.println(currentMillis - startMillis);
    }
    if ((currentMillis - startMillis >= s8) &&
        (currentMillis - startMillis <= s4)) // Reset every 1 sec
    {
                  lcd.println("Shutter time 1/8: "+currentMillis - startMillis);

      Serial.print("Shutter time 1/8: ");
      Serial.println(currentMillis - startMillis);
    }
    if ((currentMillis - startMillis >= s4) &&
        (currentMillis - startMillis <= s2)) // Reset every 1 sec
    {
                        lcd.println("Shutter time 1/4: "+currentMillis - startMillis);

      Serial.print("Shutter time 1/4: ");
      Serial.println(currentMillis - startMillis);
    }
    if ((currentMillis - startMillis >= s2) &&
        (currentMillis - startMillis <= s1)) // Reset every 1 sec
    {
                        lcd.println("Shutter time 1/2: "+currentMillis - startMillis);

      Serial.print("Shutter time 1/2: ");
      Serial.println(currentMillis - startMillis);
    }
    if (currentMillis - startMillis >= s1) // Reset every 1 sec
    {
                        lcd.println("Shutter time 1 or T: "+currentMillis - startMillis);

      Serial.print("Shutter time 1 or T: ");
      Serial.println(currentMillis - startMillis);
    }
    Serial.write(13);
  }

  // while (analogRead(A0) < sensorLow) {
  //   Serial.println("Menos luz");
  //   Serial.print("Current: ");
  //   Serial.println(analogRead(A0));
  //   Serial.print("Lowest: ");
  //   Serial.println(sensorLow);
  //   Serial.print("Shutter time: ");
  //   Serial.println(ElapsedTime);
  //   delay(2000);
  // }
  // delay(2000);
}
