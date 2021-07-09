
//v.0.1 @Marcin
//Circuit:
//LCD:
// VSS - ground b-board
// VDD - + b-board 
// V0 - to 10k potentiometer, middle cable
// RS - 12 Arduino
// RW - groun b-board
// E - 11 Arduino
//
//break
//
//D4 - 5 Arduino
//D5 - 4 Arduino
//D6 - 3 Arduino
//D7 - 2 Arduino
//A - Negative part of resistor, other part connected to + on b-board
//K - negative b-board
//Then A0 to right leg of thermo, left leg going to positive. Right leg row - 10k resistor to negative 
//Ground and 5V from Arduino to breadboard
//10k potentionmeter to +/- on breadboard

//Joystick:
// + and - connected to the same row in breadboard
//Button - A7, X pin - A2, Y pin - A1

//LEDS
//Leds connected to A8-A12 (+) then
//using 300om resistors connected to negative
//additional ground from Arduino 


#include <LiquidCrystal.h>
int tempPin = 0;
//                BS  E  D4 D5  D6 D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
#define joystick_switch_pin  A7
#define joystick_x_pin       A2
#define joystick_y_pin       A1
#define led1       A8
#define led2       A9
#define led3       A10
#define led4       A11
#define led5       A12

int buttonState = 999; //initiating button state. then 0 is clicked and 1 - button not clicked 
int current_main = 1; //current menu position
String option1 = "Temp";
String option2 = "Blink";
String option3 = "Quote";
String option4 = "Crazy";
String randomsentence0 = "GG";
String randomsentence10 = "EZ";
String randomsentence1 = "Random";
String randomsentence11 = "message";
String randomsentence2 = "Hi";
String randomsentence12 = "How are you";
String randomsentence3 = "No idea";
String randomsentence13 = "for a random quote";
String randomsentence4 = "?????";
String randomsentence14 = "Why did you click it";
String randomsentence5 = "I'm not that";
String randomsentence15 = "creative with quotes";
String randomsentence6 = "Oh man";
String randomsentence16 = ";-;";
String randomsentence7 = "I am only";
String randomsentence17 = "testing";
String randomsentence8 = "OK what quotes";
String randomsentence18 = "?";
String randomsentence9 = "Beep ";
String randomsentence19 = "Error";

//creating my own character - arrow, using bitmap
byte arrow[8] = 

              {

                0b00100,

                0b00010,

                0b00001,

                0b11111,

                0b00001,

                0b00010,

                0b00100,

                0b00000

              };

void temp(){
  //temperature method
  int tempReading = analogRead(tempPin);
  double tempK = log(10000.0 * ((1024.0 / tempReading - 1)));
  tempK = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * tempK * tempK )) * tempK );       //  Temp Kelvin
  float tempC = tempK - 273.15;            // Convert Kelvin to Celcius

  // Display Temperature in C
  lcd.setCursor(0, 0);
  if(tempC >27){
      lcd.print("SO HOT! ");
      lcd.setCursor(0, 1);
      lcd.print(tempC);
      lcd.setCursor(6, 1);
      lcd.print(" C");
      delay(500);
  }
  else{
      lcd.print("SO COLD! ");
      lcd.setCursor(0, 1);
      lcd.print(tempC);
      lcd.setCursor(6, 1);
      lcd.print("C");
      delay(500);
  }
}
void print_random(){
  //method printing random quote
  int randnumber = random(10);
  switch (randnumber) {
  case 0:
    lcd.setCursor(0, 0);
    lcd.print(randomsentence0);  
    lcd.setCursor(0, 1);
    lcd.print(randomsentence10);
    delay(5000);
          break;
    
  case 1:
    lcd.setCursor(0, 0);
    lcd.print(randomsentence1);
    lcd.setCursor(0, 1);
    lcd.print(randomsentence11);
    delay(5000);
          break;
  case 2:
    lcd.setCursor(0, 0);
    lcd.print(randomsentence2);
    lcd.setCursor(0, 1);
    lcd.print(randomsentence12);
    delay(5000);    break;
  case 3:
    lcd.setCursor(0, 0);
    lcd.print(randomsentence3);
    lcd.setCursor(0, 1);
    lcd.print(randomsentence13);
    delay(5000);    break;
  case 4:
    lcd.setCursor(0, 0);
    lcd.print(randomsentence4);
    lcd.setCursor(0, 1);
    lcd.print(randomsentence14);
    delay(5000);    break;
  case 5:
    lcd.setCursor(0, 0);
    lcd.print(randomsentence5);
    lcd.setCursor(0, 1);
    lcd.print(randomsentence15);
    delay(5000);    break;
  case 6:
    lcd.setCursor(0, 0);
    lcd.print(randomsentence6);
    lcd.setCursor(0, 1);
    lcd.print(randomsentence16);
    delay(5000);    break;
  case 7:
    lcd.setCursor(0, 0);
    lcd.print(randomsentence7);
    lcd.setCursor(0, 1);
    lcd.print(randomsentence17);
    delay(5000);    break;
      case 8:
    lcd.setCursor(0, 0);
    lcd.print(randomsentence8);
    lcd.setCursor(0, 1);
    lcd.print(randomsentence18);
    delay(5000);    break;
      case 9:
    lcd.setCursor(0, 0);
    lcd.print(randomsentence9);
    lcd.setCursor(0, 1);
    lcd.print(randomsentence19);
    delay(5000);    break;

  }
}
void led_on(){
  //method turning on and off all leds in the circuit
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);
  digitalWrite(led5, HIGH);
  delay(5000);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
}
void random_leds(int runtime = 150, int changetime = 70){
  //method turning on and off random leds in the circuit, lasting random time
  //default max runtime is 150 times blink time up to almost a second 
  for (int i = 0; i<runtime; i++){
    int rand1 = random(changetime);
    int rand2 = random(5);
    if (rand2 == 0){
      digitalWrite(led1, HIGH);
      delay(rand1);
      digitalWrite(led1, LOW);
    }
    else if (rand2 == 1){
      digitalWrite(led2, HIGH);
      delay(rand1);
      digitalWrite(led2, LOW);
    }
    else if (rand2 == 2){
      digitalWrite(led3, HIGH);
      delay(rand1);
      digitalWrite(led3, LOW);
    }

    else if (rand2 == 3){
      digitalWrite(led4, HIGH);
      delay(rand1);
      digitalWrite(led4, LOW);
    }

    else if (rand2 == 4){
      digitalWrite(led5, HIGH);
      delay(rand1);
      digitalWrite(led5, LOW);
    }
  }
}
int read_joystick(int current, int b) {
  //method reading current joystick position and returning new position if joystick moved or clicked 
  //reading x and y axis values
  int X_Axis = analogRead(joystick_x_pin);     // read the x axis value
  int Y_Axis = analogRead(joystick_y_pin);     // read the y axis value
  Y_Axis = map(Y_Axis, 0, 1023, 1023, 0);      // invert the input from the y axis so that pressing the stick forward gives larger values
    
  if (b == 0){
    if(current == 1){
    lcd.setCursor(0, 0);
    lcd.print("                     ");       //every time it has to clean the screen 
    lcd.setCursor(0, 1);
    lcd.print("                    ");
      //show temp for around 5 sec then clear the screen
      for(int i = 0; i<10; i++){
         temp();
      }
    lcd.setCursor(0, 0);
    lcd.print("                     ");       //every time it has to clean the screen 
    lcd.setCursor(0, 1);
    lcd.print("                    ");

      
    }
    else if(current == 3){
    lcd.setCursor(0, 0);
    lcd.print("                     ");       //every time it has to clean the screen 
    lcd.setCursor(0, 1);
    lcd.print("                    ");
    print_random();
    lcd.setCursor(0, 0);
    lcd.print("                     ");  
    lcd.setCursor(0, 1);
    lcd.print("                    ");


    }
    else if(current == 2){
    lcd.setCursor(0, 0);
    lcd.print("                     ");       //every time it has to clean the screen 
    lcd.setCursor(0, 1);
    lcd.print("                    ");
    lcd.setCursor(0, 0);
    lcd.print("LEDS ON");  
    led_on();
    lcd.setCursor(0, 0);
    lcd.print("                     ");  
    lcd.setCursor(0, 1);
    lcd.print("                    ");
       

    }
    else if(current == 4){
    lcd.setCursor(0, 0);
    lcd.print("                     ");       //every time it has to clean the screen 
    lcd.setCursor(0, 1);
    lcd.print("                    ");
    lcd.setCursor(0, 0);
    lcd.print("LEDS ON");  
    random_leds();
    lcd.setCursor(0, 0);
    lcd.print("                     ");  
    lcd.setCursor(0, 1);
    lcd.print("                    ");
       
    }
  } 
  else if (X_Axis >= 900) {             //moving right in the menu
    //RIGHT
    if(current == 1){
       current = 2;
    }
    else if (current == 2){
      current = 2;
    }
      else if (current == 3){
      current = 4;
    }
      else if (current == 4){
      current = 4;
    }
  } 
  
  else if (X_Axis <= 100) {             //moving left in the menu
    //LEFT
    if(current == 1){
       current = 1;
    }
    else if (current == 2){
      current = 1;
    }
      else if (current == 3){
      current = 3;
    }
      else if (current == 4){
      current = 3;
    }

      } 
  
  else if (Y_Axis >= 900) {             //moving up in the menu
    //UP
    if(current == 1){
       current = 1;
    }
    else if (current == 2){
      current = 2;
    }
      else if (current == 3){
      current = 1;
    }
      else if (current == 4){
      current = 2;
    }
 } 
      
      
      else if (Y_Axis <= 100) {             //moving down in the menu
    //DOWN
    if(current == 1){
       current = 3;
    }
    else if (current == 2){
      current = 4;
    }
      else if (current == 3){
      current = 3;
    }
      else if (current == 4){
      current = 4;
    }

  }
  return current;
}

void menu1(){
  //method for menu layout when cursor is at position 1
    lcd.setCursor(0, 0);
    lcd.print("\001");  
    lcd.print(option1);
    lcd.setCursor(9, 0);
    lcd.print(option2);
    lcd.setCursor(0, 1);
    lcd.print(option3);
    lcd.setCursor(9, 1);
    lcd.print(option4);

}
void menu2(){
    //method for menu layout when cursor is at position 2
    lcd.setCursor(0, 0);
    lcd.print(option1);
    lcd.setCursor(9, 0);
    lcd.print("\001");  
    lcd.print(option2);
    lcd.setCursor(0, 1);
    lcd.print(option3);
    lcd.setCursor(9, 1);
    lcd.print(option4);

}
void menu3(){
  //method for menu layout when cursor is at position 3
    lcd.setCursor(0, 0);
    lcd.print(option1);
    lcd.setCursor(9, 0);
    lcd.print(option2);
    lcd.setCursor(0, 1);
    lcd.print("\001");  
    lcd.print(option3);
    lcd.setCursor(9, 1);
    lcd.print(option4);

}
void menu4(){
  //method for menu layout when cursor is at position 4
    lcd.setCursor(0, 0);
    lcd.print(option1);
    lcd.setCursor(9, 0);
    lcd.print(option2);
    lcd.setCursor(0, 1);
    lcd.print(option3);
    lcd.setCursor(9, 1);
    lcd.print("\001");  
    lcd.print(option4);
}

void test(int b){
  //testing sensitivity of new joystick/buttons
  lcd.setCursor(0, 0);
  int X_Axis = analogRead(joystick_x_pin);     // read the x axis value
  int Y_Axis = analogRead(joystick_y_pin);     // read the y axis value
  Y_Axis = map(Y_Axis, 0, 1023, 1023, 0);      // invert the input from the y axis so that pressing the stick forward gives larger values
   if (b == 0){
    lcd.print("Clicked");
    delay(500);
  } else if (X_Axis >= 900) {
    lcd.print("Right");
        delay(500);
  } else if (X_Axis <= 100) {
    lcd.print("Left");
        delay(500);
  } else if (Y_Axis >= 900) {
    lcd.print("Up");
        delay(500);
  } else if (Y_Axis <= 100) {
    lcd.print("Down");
        delay(500);
  }
}

void setup()
{
  lcd.createChar ( 1, arrow );  //creating my custom character 
  lcd.begin(16, 2);
  pinMode(joystick_switch_pin, INPUT_PULLUP); 
  pinMode(led1, OUTPUT);          //setting A8-A12 to outputs, default is negative
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);

}
void loop()
{
  buttonState = digitalRead(joystick_switch_pin);
  int b = buttonState;
  //displaying correct menu for each current state 
  if(current_main == 1){
    menu1();
  }
  else if(current_main == 2){
    menu2();
  }
  else if(current_main == 3){
    menu3();
  }
  else if(current_main == 4){
    menu4();
  }
  current_main = read_joystick(current_main, b);
  //some tests below if needed 
//test(b);
//  lcd.print(current_main);
}