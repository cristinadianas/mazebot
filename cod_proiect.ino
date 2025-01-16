#define IR_SENSOR_FAR_LEFT 8
#define IR_SENSOR_LEFT 9
#define IR_SENSOR_CENTER 10
#define IR_SENSOR_RIGHT 11
#define IR_SENSOR_FAR_RIGHT 12
#define MOTOR_SPEED 180

//Right motor
int enableRightMotor=3;
int rightMotorPin1=2;
int rightMotorPin2=4;

//Left motor
int enableLeftMotor=6;
int leftMotorPin1=5;
int leftMotorPin2=7;

void setup()
{
  TCCR0B = TCCR0B & B11111000 | B00000010 ;

  pinMode(enableRightMotor, OUTPUT);
  pinMode(rightMotorPin1, OUTPUT);
  pinMode(rightMotorPin2, OUTPUT);
  
  pinMode(enableLeftMotor, OUTPUT);
  pinMode(leftMotorPin1, OUTPUT);
  pinMode(leftMotorPin2, OUTPUT);

  pinMode(IR_SENSOR_RIGHT, INPUT);
  pinMode(IR_SENSOR_LEFT, INPUT);
  rotateMotor(0,0);   

  Serial.begin(9600);
}


void loop()
{
  int farLeftIRSensorValue = digitalRead(IR_SENSOR_FAR_LEFT);
  int leftIRSensorValue = digitalRead(IR_SENSOR_LEFT);
  int centerIRSensorValue = digitalRead(IR_SENSOR_CENTER);
  int rightIRSensorValue = digitalRead(IR_SENSOR_RIGHT);
  int farRightIRSensorValue = digitalRead(IR_SENSOR_FAR_RIGHT);

  Serial.print("far left value: ");
  Serial.print(farLeftIRSensorValue);
  Serial.print('\n');

  Serial.print("left value: ");
  Serial.print(leftIRSensorValue);
  Serial.print('\n');

  Serial.print("center value: ");
  Serial.print(centerIRSensorValue);
  Serial.print('\n');

  Serial.print("right value: ");
  Serial.print(rightIRSensorValue);
  Serial.print('\n');

  Serial.print("far right value: ");
  Serial.print(farRightIRSensorValue);
  Serial.print('\n');

  //If none of the far sensors detect black line, then go straight
  if (farLeftIRSensorValue == HIGH && farRightIRSensorValue == HIGH)
  {
    rotateMotor(MOTOR_SPEED, MOTOR_SPEED);
    Serial.print("STRAIGHT");
    Serial.print('\n');
  }
  //If far right sensor detects black line, then turn right
  else if (farRightIRSensorValue == LOW && farLeftIRSensorValue == HIGH)
  {
      rotateMotor(-MOTOR_SPEED, MOTOR_SPEED); 
      Serial.print("RIGHT");
      Serial.print('\n');
  }
  //If far left sensor detects black line, then turn left  
  else if (farRightIRSensorValue == HIGH && farLeftIRSensorValue == LOW)
  {
      rotateMotor(MOTOR_SPEED, -MOTOR_SPEED); 
      Serial.print("LEFT");
      Serial.print('\n');
  } 
  //If both far right and far left sensors detect black line, then stop 
  else 
  {
    rotateMotor(0, 0);
    Serial.print("STOP");
    Serial.print('\n');
  }
  Serial.print('\n');
}


void rotateMotor(int rightMotorSpeed, int leftMotorSpeed)
{
  
  if (rightMotorSpeed < 0)
  {
    digitalWrite(rightMotorPin1,LOW);
    digitalWrite(rightMotorPin2,HIGH);    
  }
  else if (rightMotorSpeed > 0)
  {
    digitalWrite(rightMotorPin1,HIGH);
    digitalWrite(rightMotorPin2,LOW);      
  }
  else
  {
    digitalWrite(rightMotorPin1,LOW);
    digitalWrite(rightMotorPin2,LOW);      
  }

  if (leftMotorSpeed < 0)
  {
    digitalWrite(leftMotorPin1,LOW);
    digitalWrite(leftMotorPin2,HIGH);    
  }
  else if (leftMotorSpeed > 0)
  {
    digitalWrite(leftMotorPin1,HIGH);
    digitalWrite(leftMotorPin2,LOW);      
  }
  else 
  {
    digitalWrite(leftMotorPin1,LOW);
    digitalWrite(leftMotorPin2,LOW);      
  }
  analogWrite(enableRightMotor, abs(rightMotorSpeed));
  analogWrite(enableLeftMotor, abs(leftMotorSpeed));    
}