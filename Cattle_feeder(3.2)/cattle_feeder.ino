#include <DS3231.h>
#include <Servo.h>
#include <LiquidCrystal.h>
#include <Keypad.h>
#include<AFMotor.h>
AF_DCMotor motor1(1, MOTOR12_1KHZ);
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);
#define LEFT_SENSOR A10 // connect the Left sensor with analog pin A0
#define RIGHT_SENSOR A15// connect the Right sensor with analog pin A1

LiquidCrystal lcd(22, 24, 26, 28, 30, 32);
int Contrast = 75;
//const byt e ROWS = 4; // Four rows
//const byte COLS = 4; // Three columns
//
//// Define the Keymap
//
//char keys[ROWS][COLS] = {
//
//  {'1','2','3','A'},
//
//  {'4','5','6','B'},
//
//  {'7','8','9','C'},
//
//  {'*','0','#','D'}
//
//};
//
//// Connect keypad ROW0, ROW1, ROW2 and ROW3 to these Arduino pins.
//
//byte rowPins[ROWS] = { 2, 3, 4, 5 };
//
//// Connect keypad COL0, COL1 and COL2 to these Arduino pins.
//
//byte colPins[COLS] = { 6, 7, 8, 9 };
//
////  Create the Keypad
//  Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
//
//
//
//DS3231  rtc(SDA, SCL);
Servo servo_test;      //initialize a servo object for the connected servo


//int angle = 0;
// int potentio = A0;      // initialize the A0analog pin for potentiometer
int t1, t2, t3, t4, t5, t6;
int f1, f2, f3, f4, f5, f6;


boolean feed = true; // condition for alarm

char key;
int r[6];

void setup()
{ Serial.begin(9600);
  Serial1.begin(9600);
  lcd.begin(16, 2);
  //  rtc.begin();
  servo_test.attach(34);   // attach the signal pin of servo to pin9 of arduino
  analogWrite(23, Contrast);
  servo_test.write(0);

  pinMode(RIGHT_SENSOR, INPUT); // initialize Right sensor as an inut
  pinMode(LEFT_SENSOR, INPUT); // initialize Left sensor as as input
}

void loop()
{
  lcd.setCursor(0, 0);

  if (Serial1.available() > 0)  // Checks whether data is comming from the serial port
  { String f = "";
    f = Serial1.readString(); // Reads the data from the serial port

    f1 = f.charAt(0) - 48;
    f2 = f.charAt(1) - 48;
    f3 = f.charAt(3) - 48;
    f4 = f.charAt(4) - 48;
    //    f5 = f.charAt(6) - 48;
    //    f6 = f.charAt(7) - 48;
    Serial.print(f);
    delay(1000);
    //setFeedingTime();
    delay(1000);
    lcd.println(f);
    delay(1000);
    lcd.clear();


    //Serial.println(buttonPress);

    lcd.print("Time:  ");
    String t = "11:20";
    //    t = rtc.getTimeStr();
    t1 = t.charAt(0);
    t2 = t.charAt(1) ;
    t3 = t.charAt(3) ;
    t4 = t.charAt(4) ;
    //  t5 = t.charAt(6) - 48;
    //    t6 = t.charAt(7) - 48;

    lcd.print(t);
    delay(1000);
    //    Serial.print(rtc.getTimeStr());
    lcd.setCursor(0, 1);

    Serial.println(f[0]);
    Serial.println(f[1]);
    Serial.println(f[3]);
    Serial.println(f[4]);
    if ('1' == f[0] && '2' == f[1] && '3' == f[3] && '4' == f[4] )
    {
      Serial.print("sda");
      //if(analogRead(RIGHT_SENSOR)<=50 && analogRead(LEFT_SENSOR)<=50) //compare both sensor value to set the directionc

      //      Serial.print(analogRead(RIGHT_SENSOR));
      motor1.run(FORWARD); // run motor1 clockwise
      motor1.setSpeed(255); // set motor1 speed 50 percent
      motor2.run(FORWARD); // run motor2 clockwise
      motor2.setSpeed(255); // set motor2 speed 50 percent
      motor3.run(FORWARD); // run motor3 clockwise
      motor3.setSpeed(255); // set motor3 speed 50 percent
      motor4.run(FORWARD); // run motor4 clockwise
      // set motor4 speed 50 percent
      for (int pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        servo_test.write(pos);              // tell servo to go to position in variable 'pos'
        delay(15);                       // waits 15ms for the servo to reach the position
      }
      for (int pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
        servo_test.write(pos);              // tell servo to go to position in variable 'pos'
        delay(15);                       // waits 15ms for the servo to reach the position
      }


      //      if (!analogRead(RIGHT_SENSOR) <= 50 && !analogRead(LEFT_SENSOR) <= 50) //compare both sensor value to set the direction
      //      {
      //        //stop all the motors
      //        motor1.run(RELEASE);
      //        motor2.run(RELEASE);
      //        motor3.run(RELEASE);
      //        motor4.run(RELEASE);
      //
      //        servo_test.write(55);
      //
      //      }

    }
  }
}




//void setFeedingTime()
//{
//  feed = true;
//  int i = 0;
//
//  lcd.clear();
//  lcd.setCursor(0, 0);
//  lcd.print("Set feeding Time");
//  lcd.clear();
//  lcd.print("HH:MM");
//  lcd.setCursor(0, 1);
//
//
//
//}

