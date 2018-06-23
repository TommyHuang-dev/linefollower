// ports being used
#define LMotorPort 5
#define RMotorPort 6
#define LSensorPort A5
#define MSensorPort A4
#define RSensorPort A3
// sensitivity of sensors
#define boundary 3.2
// speed of motors
#define motorSpeed 150

// variables for voltages of sensors
int sensorL, sensorM, sensorR;
double voltageL, voltageM, voltageR;

void setup() {
//  Serial.begin(9600);
  // setup motors
  pinMode(LMotorPort, OUTPUT);
  pinMode(RMotorPort, OUTPUT);
  // setup IR sensors
  pinMode(LSensorPort, INPUT);
  pinMode(MSensorPort, INPUT);
  pinMode(RSensorPort, INPUT);
  
}


void loop() {
  // get the voltage of all sensors
  sensorL = analogRead(LSensorPort);
  sensorM = analogRead(MSensorPort);
  sensorR = analogRead(RSensorPort);
  voltageL = (double)sensorL * 5.0 / 1023.0;
  voltageM = (double)sensorM * 5.0 / 1023.0;
  voltageR = (double)sensorR * 5.0 / 1023.0;
  
  // keep going straight if the middle sensor is high
  if (voltageM >= boundary - 0.5 && voltageL < boundary && voltageR < boundary) {
    // go forward
    analogWrite(LMotorPort, motorSpeed);
    analogWrite(RMotorPort, motorSpeed);
  }
  // power right wheel to go left if only left sensor is high
  else if (voltageL >= boundary && voltageR < boundary) {
    // turn left
    digitalWrite(LMotorPort, LOW);
    analogWrite(RMotorPort, motorSpeed);
  }
  // power left wheel to go right if only right sensor is high
  else if (voltageL < boundary && voltageR >= boundary) {
    // turn right
    analogWrite(LMotorPort, motorSpeed);
    digitalWrite(RMotorPort, LOW);
  }
  // if all three sensors are high, stop.
  else if (voltageL >= boundary && voltageM >= boundary && voltageR >= boundary) {
    // stahp
    digitalWrite(LMotorPort, LOW);
    digitalWrite(RMotorPort, LOW);
  }
  
//  Serial.print("L: ");
//  Serial.println(voltageL);
  
//  Serial.print("M: ");
//  Serial.println(voltageM);

//  Serial.print("R: ");
//  Serial.println(voltageR);
}





