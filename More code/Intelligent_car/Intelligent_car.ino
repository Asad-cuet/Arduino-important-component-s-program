#include<Servo.h>
Servo survo;
           //book 11 ,12,7,2,4,9,10,3,5 0,1
                     //  ,8,13     ,A0,A1,A2,A3,A4,A5
int t=300;
int ahead=100;
int left=250;
int right=0;

int trig = 13;    // sonar sensor
int echo = 12;
float distance=26;
float duration,distance_1,distance_2,duration_1,duration_2;

int MotorA_in1 =2;   //motor driver pin     motor A right side
int MotorA_in2 =3;
int MotorB_in3 =4;     // motor B left side         
int MotorB_in4 =5;
int MotorA_PWM =9;
int MotorB_PWM =10;

int spd= 255;
void setup() {
  survo.attach(6);
  Serial.begin(9600);
       pinMode(trig, OUTPUT);  //ultrasonic sensor
       pinMode(echo, INPUT);
   
  pinMode(MotorA_in1, OUTPUT);
  pinMode(MotorA_in2, OUTPUT);
  pinMode(MotorB_in3, OUTPUT);
  pinMode(MotorB_in4, OUTPUT);
  pinMode(MotorA_PWM, OUTPUT);
  pinMode(MotorB_PWM, OUTPUT);  
}
void loop() {
             // default things
        analogWrite(MotorA_PWM, spd);   //used PWM
        analogWrite(MotorB_PWM, spd);
        survo.write(ahead);
        sonar();
        RobotForward();
        if(distance<25 && distance!=0) {
          RobotStop();
          Survo();
          

        }

}
        
 
 




           
// robot movement function   
void RobotForward() {

  digitalWrite(MotorA_in1, LOW);  //clockwiwse
  digitalWrite(MotorA_in2, HIGH);
  digitalWrite(MotorB_in3, HIGH);
  digitalWrite(MotorB_in4, LOW);

}

void RobotStop() {

  digitalWrite(MotorA_in1, LOW);
  digitalWrite(MotorA_in2, LOW);
  digitalWrite(MotorB_in3, LOW);
  digitalWrite(MotorB_in4, LOW);

}

void RobotBackward() {

  digitalWrite(MotorA_in1, HIGH);
  digitalWrite(MotorA_in2, LOW);
  digitalWrite(MotorB_in3, LOW);
  digitalWrite(MotorB_in4, HIGH);
  
}


void RobotRight() {
  
    digitalWrite(MotorA_in1, HIGH);
  digitalWrite(MotorA_in2, LOW);
  digitalWrite(MotorB_in3, HIGH);
  digitalWrite(MotorB_in4, LOW);

}

void RobotLeft() {

    digitalWrite(MotorA_in1, LOW);
  digitalWrite(MotorA_in2, HIGH);
  digitalWrite(MotorB_in3, LOW);
  digitalWrite(MotorB_in4, HIGH);   
}

void sonar() {
            digitalWrite(trig, LOW);
        delay(2);
        digitalWrite(trig, HIGH);
        delayMicroseconds(10);
        digitalWrite(trig,LOW);
        duration =pulseIn(echo, HIGH); 
        distance=(duration*0.0332)/2;  // calculated in cm
        Serial.print("distance                                is=");
        Serial.print(distance);
        Serial.print("cm\n");
}
void sonar_1() {
         survo.write(left);
         delay(t);
            digitalWrite(trig, LOW);
        delay(2);
        digitalWrite(trig, HIGH);
        delayMicroseconds(10);
        digitalWrite(trig,LOW);
        duration_1 =pulseIn(echo, HIGH); 
        distance_1=(duration_1*0.0332)/2;  // calculated in cm
        Serial.print("distance_1                     is=");
        Serial.print(distance_1);
        Serial.print("cm\n");
        
}
void sonar_2() {
        survo.write(right);
        delay(t);
            digitalWrite(trig, LOW);
        delay(2);
        digitalWrite(trig, HIGH);
        delayMicroseconds(10);
        digitalWrite(trig,LOW);
        duration_2 =pulseIn(echo, HIGH); 
        distance_2=(duration_2*0.0332)/2;  // calculated in cm
        Serial.print("distance_2            is=");
        Serial.print(distance_2);
        Serial.print("cm\n");
       
}
void Survo() {
  sonar_1();  
  delay(t);
  sonar_2();
  delay(t);
  survo.write(ahead);
  delay(500);
                    if(distance_1>distance_2) {
          RobotLeft();
          delay(500);
        }
        else {
          RobotRight();
          delay(500);
        }
        
}
