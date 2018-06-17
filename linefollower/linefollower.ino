#define LMotorPort 5
#define RMotorPort 6
#define LSensorPort A5
#define MSensorPort A4
#define RSensorPort A3
#define boundary 4


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  // setup motors
  pinMode(LMotorPort, OUTPUT);
  pinMode(RMotorPort, OUTPUT);
  // setup IR sensors
  pinMode(LSensorPort, INPUT);
  pinMode(MSensorPort, INPUT);
  pinMode(RSensorPort, INPUT);
  
}

float sensorValues[3];
void loop() {
  // put your main code here, to run repeatedly:
  // get the voltage of all sensors
  int sensorL = analogRead(LSensorPort);
  int sensorM = analogRead(MSensorPort);
  int sensorR = analogRead(RSensorPort);
  float voltageL = (float)sensorL * 5.0 / 1023.0;
  float voltageM = (float)sensorM * 5.0 / 1023.0;
  float voltageR = (float)sensorR * 5.0 / 1023.0;
  
  // keep going straight if the middle sensor is high
  if (voltageM >= boundary && voltageL < boundary && voltageR < boundary) {
    // go forward
    analogWrite(LMotorPort, 128);
    analogWrite(RMotorPort, 128);
  }
  // power right wheel to go left if only left sensor is high
  else if (voltageL >= boundary && voltageR < boundary) {
    // turn left
    analogWrite(LMotorPort, 0);
    analogWrite(RMotorPort, 128);
  }
  // power left wheel to go right if only right sensor is high
  else if (voltageL < boundary && voltageR >= boundary) {
    // turn right
    analogWrite(LMotorPort, 128);
    analogWrite(RMotorPort, 0);
  }
  // if all three sensors are high, stop.
  else if (voltageL >= boundary && voltageM >= boundary && voltageR >= boundary) {
    // stahp
    digitalWrite(LMotorPort, LOW);
    digitalWrite(RMotorPort, LOW);
  }
  /*
  Serial.print("L: ");
  Serial.println(voltageL);
  
  Serial.print("M: ");
  Serial.println(voltageM);

  Serial.print("R: ");
  Serial.println(voltageR);
  delay(100); */
  // only for the serial monitor, delete or comment out if not needed
}





