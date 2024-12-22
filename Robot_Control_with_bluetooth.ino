#include <SoftwareSerial.h> //Library for serial communication
SoftwareSerial BT(4, 5);  // creates a "virtual" serial port/UART
// connect BT module TX to 3
// connect BT module RX to 5
// connect BT Vcc to 5V, GND to GND

int motor_speed_left = 6;
int motor_speed_right = 7;
int speed = 150;

void setup() {
  pinMode(11, OUTPUT); //Left Motor 
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT); //Right Motor
  pinMode(8, OUTPUT);
  BT.begin(9600);
  BT.println("Bluetooth robot is ready to control");

}
char a; 
void loop() {
  if (BT.available()){
    a=(BT.read());
    if (a=='1'){
      analogWrite(motor_speed_left, speed);
      analogWrite(motor_speed_right, speed);
      digitalWrite(11, HIGH);
      digitalWrite(10, LOW);
      digitalWrite(8, HIGH); 
      digitalWrite(9, LOW); //Forward control
    }
    else if (a=='2'){
      analogWrite(motor_speed_left, speed);
      analogWrite(motor_speed_right, speed);
      digitalWrite(11, LOW);
      digitalWrite(10, HIGH);
      digitalWrite(8, LOW); 
      digitalWrite(9, HIGH); //Backward control
    } 
    else if (a=='3'){
      analogWrite(motor_speed_left, speed);
      analogWrite(motor_speed_right, speed);
      digitalWrite(11, HIGH);
      digitalWrite(10, LOW);
      digitalWrite(8, LOW); 
      digitalWrite(9, HIGH); //Right control
    }
    else if (a=='4'){
      analogWrite(motor_speed_left, speed);
      analogWrite(motor_speed_right, speed);
      digitalWrite(11, LOW);
      digitalWrite(10, HIGH);
      digitalWrite(8, HIGH); 
      digitalWrite(9, LOW); //Left control
    }
    else{
      analogWrite(motor_speed_left, speed);
      analogWrite(motor_speed_right, speed);
      digitalWrite(11, LOW);
      digitalWrite(10, LOW);
      digitalWrite(8, LOW);  
      digitalWrite(9, LOW); //Stop control
    }
  }
}