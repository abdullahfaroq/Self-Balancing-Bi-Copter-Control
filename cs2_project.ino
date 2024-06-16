#include "Wire.h"
#include "I2Cdev.h"
#include "MPU6050.h"
#include <Servo.h>

MPU6050 mpu;
int16_t ax, ay, az;
int16_t gx, gy, gz;

Servo ESCR;  // First ESC
Servo ESCL;  // Second ESC

#define esc1_pin 3  // Pin for the first ESC
#define esc2_pin 5  // Pin for the second ESC

// PID Constants
double Kp = 1.23;  // Proportional gain
double Ki = 0.0009;  // Integral gain
double Kd = 570;  // Derivative gain

int timeOld;
int time;
int dt;
float error;
float errorOld;
float de;
float derivative = 0;
float setpoint = 0;  // Desired servo angle

float integral = 0;

void setup() {
  ESCR.attach(esc1_pin);
  ESCL.attach(esc2_pin);

  ESCR.writeMicroseconds(1000);
  ESCL.writeMicroseconds(1000);

  Serial.begin(9600);

  Wire.begin();
  mpu.initialize();
  delay(5000);
  time = millis();
}

void loop() {
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  // Map accelerometer values to servo control values
  int servoValue = map(ax, -17000, 17000, -18, 18);
  // Constrain the mapped value to the desired range
  // servoValue = constrain(servoValue, -18, 18);

  // PID control
  timeOld = time;
  time = millis();
  dt = time - timeOld;

  error = (setpoint - servoValue);
  de = error - errorOld;
  derivative = de / dt;

  if (-7 < error && error < 7) {
    integral = integral + error * dt;
  } else {
    integral = 0;
  }

  if (error == 0) {
    integral = 0;
  }

  double PID = Kp * error + Ki * integral + Kd * derivative;
  int velocityR=1055 + PID;
  int velocityL=1292 - PID;

  // Adjust motor velocities based on PID output
  int escrOutput = constrain(velocityR, 1025, 1085);
  int esclOutput = constrain(velocityL, 1250, 1340);

  ESCR.writeMicroseconds(escrOutput);
  ESCL.writeMicroseconds(esclOutput);

  Serial.print(", Servo Value: ");
  Serial.print(servoValue);
  Serial.print(", PID Output: ");
  Serial.println(PID);

  // Print servoValue for plotting
  Serial.println(servoValue);
  errorOld = error;

  delay(50);
}
