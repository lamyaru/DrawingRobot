// Demonstration code for the Arduino Drawing Robot
// http://www.instructables.com/id/Arduino-Drawing-Robot/
// http://www.makersbox.us/
// 648.ken@gmail.com

#include <Servo.h>

// setup servo
int servoPin = 8;
int PEN_DOWN = 20; // angle of servo when pen is down
int PEN_UP = 80;   // angle of servo when pen is up
Servo penServo;

int scale=12; //   # Scale for letters, 2.5x = 5cm x 10cm 
int debug=false; // # Turns on extra consol output
int wheel_dia=63; //      # mm (increase = spiral out)
int wheel_base=109; //,    # mm (increase = spiral in) 
int steps_rev=128; //,     # 512 for 64x gearbox, 128 for 16x gearbox
int delay_time=6; //            # time between steps in ms
//int ledPin = 13;

// Stepper sequence org->pink->blue->yel
int L_stepper_pins[] = {12, 10, 9, 11};
int R_stepper_pins[] = {4, 6, 7, 5};

int fwd_mask[][4] =  {{1, 0, 1, 0},
                      {0, 1, 1, 0},
                      {0, 1, 0, 1},
                      {1, 0, 0, 1}};

int rev_mask[][4] =  {{1, 0, 0, 1},
                      {0, 1, 0, 1},
                      {0, 1, 1, 0},
                      {1, 0, 1, 0}};


void setup() {
  randomSeed(analogRead(1)); 
  // put your setup code here, to run once:
  Serial.begin(9600);
  //pinMode(ledPin, OUTPUT);
  for(int pin=0; pin<4; pin++){
    pinMode(L_stepper_pins[pin], OUTPUT);
    digitalWrite(L_stepper_pins[pin], LOW);
    pinMode(R_stepper_pins[pin], OUTPUT);
    digitalWrite(R_stepper_pins[pin], LOW);
  }
  penServo.attach(servoPin);
  Serial.println("setup");
}


void spiral(int size, int angle){ // inward spiral
  while(size > 0){
    forward(size);
    right(angle);
    size = size -2;
  }
}


void loopTest(){ // draw a calibration box 4 times
  for(int x=0; x<12; x++){
    forward(100);
    left(90);
  }
  while(1){}
}


void loop() {
  pendown();
  //loopTest();
  //while(1){}
  C();
  A();
  L();
  L();
  I();
  U();
  I();
  N();
  O();

  forward(5.5 * scale);
  left(180);
  while(1);
}

void A(){
      penup();
      left(90);
      pendown();
      forward(3 * scale);
      right(45);
      forward(1.41 * scale);
      right(90);
      forward(1.41 * scale);
      right(45);
      forward(2 * scale);
      right(90);
      forward(2 * scale);
      backward(2 * scale);
      left(90);
      forward(1 * scale);
      penup();
      left(90);
      forward(0.5 * scale);
}

void B(){
  pendown();
  forward(1 * scale);
  left(45);
  forward(1.41 * scale);
  left(90);
  forward(1.41 * scale);
  right(90);
  forward(1.41 * scale);
  left(90);
  forward(1.41 * scale);
  left(45);
  forward(1 * scale);
  left(90);
  forward(4 * scale);
  penup();
  left(90);
  forward(2.5 * scale);    
}

void C(){
  penup();
  left(90 - 33.7);
  forward(3.61 * scale);
  pendown();
  left(78.7);
  forward(1.41 * scale);
  left(90);
  forward(1.41 * scale);
  left(45);
  forward(2 * scale);
  left(45);
  forward(1.41 * scale);
  left(90);
  forward(1.41 * scale);
  penup();
  right(90);
  forward(1.41 * scale);
  left(45);
  backward(0.5 * scale);
}

void D(){
  pendown();
  forward(1 * scale);
  left(45);
  forward(1.41 * scale);
  left(45);
  forward(2 * scale);
  left(45);
  forward(1.41 * scale);
  left(45);
  forward(1 * scale);
  left(90);
  forward(4 * scale);
  penup();
  left(90);
  forward(2.5 * scale);
}

void E(){
  penup();
  left(90);
  forward(4 * scale);
  right(90);
  forward(2 * scale);
  pendown();
  backward(2 * scale);
  right(90);
  forward(2 * scale);
  left(90);
  forward(1 * scale);
  backward(1 * scale);
  right(90);
  forward(2 * scale);
  left(90);
  forward(2 * scale);
  penup();
  forward(0.5 * scale);
}

void f(){
  penup();
  left(90);
  pendown();
  forward(4 * scale);
  right(90);
  forward(2 * scale);
  penup();
  left(90 - 26.6);
  backward(1.41 * scale);
  right(90 - 26.6);
  backward(1 * scale);
  pendown();
  forward(1 * scale);
  penup();
  right(45);
  forward(2.83 * scale);
  left(45);
  backward(0.5 * scale);
}

void G(){
  penup();
  left(90 - 33.7);
  forward(3.61 * scale);
  pendown();
  left(78.7);
  forward(1.41 * scale);
  left(90);
  forward(1.41 * scale);
  left(45);
  forward(2 * scale);
  left(45);
  forward(1.41 * scale);
  left(90);
  forward(1.41 * scale);
  left(45);
  forward(1 * scale);
  right(90);
  backward(1 * scale);
  penup();
  right(45);
  forward(2.83 * scale);
  left(45);
  backward(0.5 * scale);
}

void H(){
  penup();
  left(90);
  pendown();
  forward(4 * scale);
  backward(2 * scale);
  right(90);
  forward(2 * scale);
  left(90);
  forward(2 * scale);
  backward(4 * scale);
  penup();
  right(90);
  forward(0.5 * scale);
}

void I(){
  penup();
  left(90 - 7.13);
  forward(4.03 * scale);
  left(7.13);
  pendown();
  backward(4 * scale);
  penup();
  right(90);
  forward(1 * scale);
}

void J(){
  penup();
  left(90);
  forward(1 * scale);
  pendown();
  backward(1 * scale);
  left(90);
  backward(2 * scale);
  left(90);
  backward(4 * scale);
  penup();
  left(14);
  forward(4.12 * scale);
  left(90 - 14);
  backward(0.5 * scale);
}

void K(){
  penup();
  left(90);
  pendown();
  forward(4 * scale);
  backward(2 * scale);
  right(45);
  forward(2.83 * scale);
  backward(2.83 * scale);
  right(90);
  forward(2.83 * scale);
  penup();
  left(45);
  forward(0.5 * scale);
}

void L(){
  penup();
  left(90);
  forward(4 * scale);
  pendown();
  backward(4 * scale);
  right(90);
  forward(2 * scale);
  penup();
  forward(0.5 * scale);
}

void M(){
  penup();
  left(90);
  pendown();
  forward(4 * scale);
  left(26.6);
  backward(1.41 * scale);
  right(26.6 + 26.6);
  forward(1.41 * scale);
  left(26.6);
  backward(4 * scale);
  penup();
  right(90);
  forward(0.5 * scale);
}

void N(){
  penup();
  left(90);
  pendown();
  forward(4 * scale);
  left(26.6);
  backward(4.47 * scale);
  right(26.6);
  forward(4 * scale);
  penup();
  backward(4 * scale);
  right(90);
  forward(0.5 * scale);
}

void O(){
  penup();
  forward(1 * scale);
  left(45);
  pendown();
  forward(1.41 * scale);
  left(45);
  forward(2 * scale);
  left(45);
  forward(1.41 * scale);
  left(90);
  forward(1.41 * scale);
  left(45);
  forward(2 * scale);
  left(45);
  forward(1.41 * scale);  
  penup();
  left(45);
  forward(1.5 * scale);
}

void P(){
  penup();
  right(90);
  pendown();
  backward(4 * scale);
  right(90);
  backward(1 * scale);
  right(45);
  backward(1.41 * scale);
  right(90);
  backward(1.41 * scale);
  right(45);
  backward(1 * scale);
  penup();
  right(33.7);
  forward(3.61 * scale);
  left(33.7);
  backward(0.5 * scale);
}

void Q(){
  penup();
  forward(1 * scale);
  left(45);
  pendown();
  forward(1.41 * scale);
  left(45);
  forward(2 * scale);
  left(45);
  forward(1.41 * scale);
  left(90);
  forward(1.41 * scale);
  left(45);
  forward(2 * scale);
  left(45);
  forward(1.41 * scale);  
  penup();
  left(45);
  forward(1 * scale);
  right(45);
  pendown();
  backward(1.41 * scale);
  penup();
  forward(1.41 * scale);
  left(45);
  forward(0.5 * scale);
}

void R(){
  penup();
  right(90);
  pendown();
  backward(4 * scale);
  right(90);
  backward(1 * scale);
  right(45);
  backward(1.41 * scale);
  right(90);
  backward(1.41 * scale);
  right(45);
  backward(1 * scale);
  right(45);
  forward(2.83 * scale);
  penup();
  left(45);
  forward(0.5 * scale);
}

void S(){
  penup();
  pendown();
  forward(1 * scale);
  left(45);
  forward(1.41 * scale);
  left(90);
  forward(2.83 * scale);
  right(90);
  forward(1.41 * scale);
  right(45);
  forward(1 * scale);
  penup();
  right(76);
  forward(4.123 * scale);
  left(76);
  backward(0.5 * scale);
}

void T(){
  penup();
  forward(1 * scale);
  left(90);
  pendown();
  forward(4 * scale);
  right(90);
  backward(1 * scale);
  forward(2 * scale);
  penup();
  right(76);
  forward(4.123 * scale);
  left(76);
  backward(0.5 * scale);
}

void U(){
  penup();
  left(90);
  forward(4 * scale);
  pendown();
  backward(4 * scale);
  left(90);
  backward(2 * scale);
  left(90);
  backward(4 * scale);
  penup();
  left(14);
  forward(4.123 * scale);
  left(76);
  backward(0.5 * scale);
}

void V(){
  penup();
  left(90);
  forward(4 * scale);
  pendown();
  backward(3 * scale);
  left(45);
  backward(1.41 * scale);
  left(90);
  backward(1.41 * scale);
  left(45);
  backward(3 * scale);
  penup();
  left(14);
  forward(4.123 * scale);
  left(76);
  backward(0.5 * scale);
}

void W(){
  penup();
  right(90);
  backward(4 * scale);
  pendown();
  forward(4.123 * scale);
  right(26.6);
  backward(1.41 * scale);
  left(26.6 + 26.6);
  forward(1.41 * scale);
  right(26.6);
  backward(4 * scale);
  penup();
  left(14);
  forward(4.123 * scale);
  left(76);
  backward(0.5 * scale);
}

void X(){
  penup();
  left(90 - 26.6);
  pendown();
  forward(4.47 * scale);
  penup();
  right(90 - 26.6);
  backward(2 * scale);
  right(90 - 26.6);
  pendown();
  forward(4.47 * scale);
  penup();
  left(90 - 26.6);
  forward(0.5 * scale);
}

void Y(){
  penup();
  right(90);
  backward(4 * scale);
  left(27);
  pendown();
  forward(1.41 * scale);
  right(27 + 27);
  backward(1.41 * scale);
  forward(1.41 * scale);
  left(27);
  forward(2 * scale);
  penup();
  left(90);
  forward(1.5 * scale);
}

void Z(){
  penup();
  left(90);
  forward(4 * scale);
  right(90);
  pendown();
  forward(2 * scale);
  left(90 - 26.6);
  backward(4.47 * scale);
  right(90 - 26.6);
  forward(2 * scale);
  penup();
  forward(0.5 * scale);
}

void spc(){
  // Create a space equal to one character. //
  penup();
  forward(2.5 * scale);
}

void N0(){
  //Numeral zero//
  pendown();
  forward(2 * scale);
  left(90);
  forward(4 * scale);
  left(90);
  forward(2 * scale);
  left(90);
  forward(4 * scale);
  penup();
  left(90);
  forward(2.5 * scale);
}

void N1(){
  //Numeral 1//
  penup();
  left(90 - 14);
  forward(4.123 * scale);
  left(14);
  pendown();
  backward(4 * scale);
  penup();
  right(90);
  forward(1.5 * scale);
}

void N2(){
  //Numeral 2//
  penup();
  left(90);
  forward(4 * scale);
  right(90);
  pendown();
  forward(2 * scale);
  right(90);
  forward(2 * scale);       
  right(90);
  forward(2 * scale);
  left(90);
  forward(2 * scale);         
  left(90);
  forward(2 * scale);
  penup();
  forward(0.5 * scale);
}

void N3(){
  //Numeral 3//
  penup();
  left(90);
  forward(4 * scale);
  right(90);
  pendown();
  forward(2 * scale);
  right(90);
  forward(2 * scale);
  right(90);
  forward(2 * scale);
  backward(2 * scale);
  left(90);
  forward(2 * scale);
  left(90);
  backward(2 * scale);
  penup();
  forward(2.5 * scale);
}
  
void N4(){
  //Numeral 4//
  penup();
  left(90);
  forward(4 * scale);
  pendown();
  backward(2 * scale);
  right(90);
  forward(2 * scale);
  left(90);
  forward(2 * scale);
  backward(4 * scale);
  penup();
  right(90);
  forward(0.5 * scale);
}

void N5(){
  //Numeral 5//
  pendown();
  forward(2 * scale);        
  left(90);                    
  forward(2 * scale);   
  left(90);  
  forward(2 * scale);   
  right(90);
  forward(2 * scale);   
  right(90);
  forward(2 * scale);
  penup();
  right(76);
  forward(4.123 * scale);
  left(76);
  backward(0.5 * scale);
}

void N6(){
  //Numeral 6//
  penup();
  left(90);
  forward(4 * scale);
  pendown();
  backward(4 * scale);
  right(90);
  forward(2 * scale);
  right(90);        
  backward(2 * scale);
  left(90);
  backward(2 * scale);
  penup();
  right(38.66);
  forward(3.20 * scale);
  left(38.66);
}

void N7(){
  //Numeral 7//
  penup();
  left(90);
  forward(4 * scale);
  right(90);
  pendown();
  forward(2 * scale);
  left(90 - 26.6);
  backward(4.47 * scale);
  penup();
  right(90 - 26.6);
  forward(2.5 * scale);
}

void N8(){
  //Numeral 8//
  pendown();
  forward(2 * scale);        
  left(90);
  forward(4 * scale);        
  left(90);
  forward(2 * scale); 
  left(90);
  forward(2 * scale);
  left(90);
  forward(2 * scale);        
  backward(2 * scale);
  right(90);
  forward(2 * scale);
  penup();
  left(90);
  forward(2.5 * scale);
}

void N9(){
  //Numeral 9//
  penup();
  forward(2 * scale);        
  left(90);
  pendown();
  forward(4 * scale);        
  left(90);
  forward(2 * scale); 
  left(90);
  forward(2 * scale);
  left(90);
  forward(2 * scale);
  penup();
  right(75.96);
  forward(2.06* scale);
  left(75.96);
}

void period(){
  //Period//
  penup();
  forward(0.5 * scale);
  pendown();
  for(int i=0; i<4; i++){
    forward(0.5 * scale);
    left(90);
  }
  penup();
  forward(1.0 * scale);
}

void comma(){
  //Comma//
  penup();
  forward(0.5 * scale);
  left(45);
  pendown();
  forward(0.707 * scale);
  left(90 - 45);
  forward(0.5 * scale);
  right(90);
  backward(0.5 * scale);
  left(90);
  backward(0.5 * scale);
  right(90);
  forward(0.5 * scale);
  penup();
  right(26.56);
  forward(1.12 * scale);
  left(26.56);
}

void qm(){
  //Question mark//
  penup();
  forward(1 * scale);       
  pendown();       
  for(int i=0; i<4; i++){
    forward(0.5 * scale);
    left(90);
  }
  penup();
  left(90 - 14.03);
  forward(1.03 * scale);
  left(14.03);
  pendown();
  forward(1 * scale);
  right(90);        
  forward(1 * scale);
  left(90); 
  forward(2 * scale);
  left(90); 
  forward(2 * scale);
  left(90); 
  forward(0.5 * scale);
  penup();
  left(35.54);
  forward(4.30 * scale);
  left(90 - 35.54);
}

void apost(){
  //Apostrophe//
  penup();
  left(90 - 18.43);
  forward(3.16 * scale);
  right(90 - 18.43 - 45);
  pendown();
  forward(0.707 * scale);
  left(45);
  forward(0.5 * scale);
  left(90);
  forward(0.5 * scale);
  left(90);
  forward(0.5 * scale);
  left(90);
  forward(0.5 * scale);
  penup();
  right(90 - 15.95);
  forward(3.64 * scale);
  left(90 - 15.95);
}

void cq(){
  //Close quote//
  penup();
  left(90 - 9.46);
  forward(3.04 * scale);
  right(90 - 9.46 - 45);
  pendown();
  forward(0.707 * scale);
  left(45);
  forward(0.5 * scale);
  left(90);
  forward(0.5 * scale);
  left(90);
  forward(0.5 * scale);
  left(90);
  forward(0.5 * scale);
  penup();
  right(45);
  forward(0.707 * scale);
  left(90);
  pendown();
  forward(0.707 * scale);
  left(45);
  forward(0.5 * scale);
  left(90);
  forward(0.5 * scale);
  left(90);
  forward(0.5 * scale);
  left(90);
  forward(0.5 * scale);
  penup();
  right(90 - 15.95);
  forward(3.64 * scale);
  left(90 - 15.95);
}

void oq(){
  //Open quote//
  penup();
  left(90 - 18.43);
  forward(3.16 * scale);
  left(18.43 + 45);
  pendown();
  forward(0.707 * scale);
  right(45);        
  forward(0.5 * scale);
  right(90);
  forward(0.5 * scale);
  right(90);
  forward(0.5 * scale);
  left(90);
  backward(0.5 * scale);
  penup();
  right(18.43);
  forward(1.58 * scale);
  right(45 - 18.43);
  pendown();
  backward(0.707 * scale);
  left(45);
  forward(0.5 * scale);
  left(90);
  forward(0.5 * scale);
  left(90);
  forward(0.5 * scale);
  left(90);
  forward(0.5 * scale);
  penup();

  left(23.20);
  forward(3.81 * scale);
  left(90 - 23.20);
}

void ex(){
  // Exclamation point //
  penup();
  forward(0.5 * scale);       
  pendown();       
  for(int i=0; i<4; i++){
    forward(0.5 * scale);
    left(90);
  }
  penup();
  left(63.45);
  forward(1.12 * scale);
  left(90 - 63.45);
  pendown();
  forward(3 * scale);
  left(90);
  forward(0.5 * scale);
  left(90);
  forward(3 * scale);
  left(90);
  forward(0.5 * scale);
  penup();
  right(45);
  forward(1.41 * scale);
  left(45);
}



int step(float distance){
  int steps = distance * steps_rev / (wheel_dia * 3.1412); //24.61
  /*
  Serial.print(distance);
  Serial.print(" ");
  Serial.print(steps_rev);
  Serial.print(" ");  
  Serial.print(wheel_dia);
  Serial.print(" ");  
  Serial.println(steps);
  delay(1000);*/
  return steps;  
}


void forward(float distance){
  int steps = step(distance);
  Serial.println(steps);
  for(int step=0; step<steps; step++){
    for(int mask=0; mask<4; mask++){
      for(int pin=0; pin<4; pin++){
        digitalWrite(L_stepper_pins[pin], rev_mask[mask][pin]);
        digitalWrite(R_stepper_pins[pin], fwd_mask[mask][pin]);
      }
      delay(delay_time);
    } 
  }
}


void backward(float distance){
  int steps = step(distance);
  for(int step=0; step<steps; step++){
    for(int mask=0; mask<4; mask++){
      for(int pin=0; pin<4; pin++){
        digitalWrite(L_stepper_pins[pin], fwd_mask[mask][pin]);
        digitalWrite(R_stepper_pins[pin], rev_mask[mask][pin]);
      }
      delay(delay_time);
    } 
  }
}


void right(float degrees){
  float rotation = degrees / 360.0;
  float distance = wheel_base * 3.1412 * rotation;
  int steps = step(distance);
  for(int step=0; step<steps; step++){
    for(int mask=0; mask<4; mask++){
      for(int pin=0; pin<4; pin++){
        digitalWrite(R_stepper_pins[pin], rev_mask[mask][pin]);
        digitalWrite(L_stepper_pins[pin], rev_mask[mask][pin]);
      }
      delay(delay_time);
    } 
  }   
}


void left(float degrees){
  float rotation = degrees / 360.0;
  float distance = wheel_base * 3.1412 * rotation;
  int steps = step(distance);
  for(int step=0; step<steps; step++){
    for(int mask=0; mask<4; mask++){
      for(int pin=0; pin<4; pin++){
        digitalWrite(R_stepper_pins[pin], fwd_mask[mask][pin]);
        digitalWrite(L_stepper_pins[pin], fwd_mask[mask][pin]);
      }
      delay(delay_time);
    } 
  }   
}


void done(){ // unlock stepper to save battery
  for(int mask=0; mask<4; mask++){
    for(int pin=0; pin<4; pin++){
      digitalWrite(R_stepper_pins[pin], LOW);
      digitalWrite(L_stepper_pins[pin], LOW);
    }
    delay(delay_time);
  }
}


void penup(){
  delay(250);
  Serial.println("PEN_UP()");
  penServo.write(PEN_UP);
  delay(250);
}


void pendown(){
  delay(250);  
  Serial.println("PEN_DOWN()");
  penServo.write(PEN_DOWN);
  delay(250);
}
