# Bluetooth Controlled Robot

This project demonstrates how to control a robot using a Bluetooth module and Arduino. The robot can move forward, backward, left, right, and stop based on commands received via Bluetooth.

## Features
- Bluetooth communication using the `SoftwareSerial` library.
- Motor control for forward, backward, left, and right movements.
- Adjustable motor speed.

## Components Required
- Arduino board
- Bluetooth module (e.g., HC-05/HC-06)
- Motor driver (e.g., L298N)
- DC motors
- Power supply
- Connecting wires

![Project Screenshot]("C:\Users\allah\Downloads\robot_picture.jpg")
![Project Screenshot]("C:\Users\allah\Downloads\hc-06_picture.jpg")
## Circuit Diagram
- **Bluetooth Module**:
  - TX to Arduino pin 4
  - RX to Arduino pin 5
  - VCC to 5V
  - GND to GND
- **Motors**:
  - Left motor connected to pins 11 and 10
  - Right motor connected to pins 9 and 8
- **Motor Speed Control**:
  - Left motor speed on pin 6
  - Right motor speed on pin 7

## How It Works
1. The program initializes a Bluetooth communication channel using the `SoftwareSerial` library.
2. Based on the character received via Bluetooth (`1`, `2`, `3`, `4`, `5`), the robot performs the following actions:
   - `1`: Move forward
   - `2`: Move backward
   - `3`: Turn right
   - `4`: Turn left
   - Any other key: Stop
3. Motor speeds can be adjusted by modifying the `speed` variable.

## Code
```cpp
#include <SoftwareSerial.h> // Library for serial communication
SoftwareSerial BT(4, 5);  // Creates a "virtual" serial port/UART
// connect BT module TX to 4
// connect BT module RX to 5
// connect BT Vcc to 5V, GND to GND

int motor_speed_left = 6;
int motor_speed_right = 7;
int speed = 150;

void setup() {
  pinMode(11, OUTPUT); // Left Motor
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT); // Right Motor
  pinMode(8, OUTPUT);
  BT.begin(9600);
  BT.println("Bluetooth robot is ready to control");
}

char a; 
void loop() {
  if (BT.available()){
    a = BT.read();
    if (a == '1'){
      analogWrite(motor_speed_left, speed);
      analogWrite(motor_speed_right, speed);
      digitalWrite(11, HIGH);
      digitalWrite(10, LOW);
      digitalWrite(8, HIGH); 
      digitalWrite(9, LOW); // Forward control
    }
    else if (a == '2'){
      analogWrite(motor_speed_left, speed);
      analogWrite(motor_speed_right, speed);
      digitalWrite(11, LOW);
      digitalWrite(10, HIGH);
      digitalWrite(8, LOW); 
      digitalWrite(9, HIGH); // Backward control
    } 
    else if (a == '3'){
      analogWrite(motor_speed_left, speed);
      analogWrite(motor_speed_right, speed);
      digitalWrite(11, HIGH);
      digitalWrite(10, LOW);
      digitalWrite(8, LOW); 
      digitalWrite(9, HIGH); // Right control
    }
    else if (a == '4'){
      analogWrite(motor_speed_left, speed);
      analogWrite(motor_speed_right, speed);
      digitalWrite(11, LOW);
      digitalWrite(10, HIGH);
      digitalWrite(8, HIGH); 
      digitalWrite(9, LOW); // Left control
    }
    else {
      analogWrite(motor_speed_left, speed);
      analogWrite(motor_speed_right, speed);
      digitalWrite(11, LOW);
      digitalWrite(10, LOW);
      digitalWrite(8, LOW);  
      digitalWrite(9, LOW); // Stop control
    }
  }
}
```

## How to Use
1. Upload the code to your Arduino board.
2. Connect the Bluetooth module to your mobile device using a Bluetooth terminal app.
3. Send the following commands to control the robot:
   - `1`: Move forward
   - `2`: Move backward
   - `3`: Turn right
   - `4`: Turn left
   - Any other key: Stop

## Customization
- Modify the `speed` variable to adjust the motor speed.
- Update pin numbers if using a different hardware configuration.

## Troubleshooting
- Ensure the Bluetooth module is properly paired with your device.
- Check all wiring connections.
- Verify that the `BT` baud rate matches the one set in the Bluetooth terminal app.

## License
This project is open-source and available under the MIT License.
