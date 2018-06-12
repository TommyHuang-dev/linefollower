#define LMotorPort = 5;
#define RMotorPort = 6;
#define LSensorPort = A0;
#define MSensorPort = A1;
#define RSensorPort = A2;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  // setup motors
  pinMode(LMotorPort, OUTPUT);
  pinMode(RMotorPort, OUTPUT);
  // setup IR motors
  pinMode(LMotorPort, OUTPUT);
  pinMode(MMotorPort, OUTPUT);
  pinMode(RMotorPort, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

}
