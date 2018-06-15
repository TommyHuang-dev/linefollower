#define LMotorPort 5
#define RMotorPort 6
#define LSensorPort A0
#define MSensorPort A1
#define RSensorPort A2


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  // setup motors
  pinMode(LMotorPort, OUTPUT);
  pinMode(RMotorPort, OUTPUT);
  // setup IR sensors
  pinMode(LSensorPort, OUTPUT);
  pinMode(MSensorPort, OUTPUT);
  pinMode(RSensorPort, OUTPUT);
  
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
  if (voltageM >= 3) {
    // go forward
    digitalWrite(LMotorPort, HIGH);
    digitalWrite(RMotorPort, HIGH);
  }
  // power right wheel to go left if only left sensor is high
  else if (voltageL >= 3 && voltageR < 3) {
    // turn left
    digitalWrite(LMotorPort, LOW);
    digitalWrite(RMotorPort, HIGH);
  }
  // power left wheel to go right if only right sensor is high
  else if (voltageL < 3 && voltageR >= 3) {
    // turn right
    digitalWrite(LMotorPort, HIGH);
    digitalWrite(RMotorPort, LOW);
  }
  // if all three sensors are high, stop.
  else if (voltageL >= 3 && voltageM >= 3 && voltageR >= 3) {
    // stahp
    digitalWrite(LMotorPort, LOW);
    digitalWrite(RMotorPort, LOW);
  }
  
  
  // only for the serial monitor, delete or comment out if not needed
  delay(50);
}





