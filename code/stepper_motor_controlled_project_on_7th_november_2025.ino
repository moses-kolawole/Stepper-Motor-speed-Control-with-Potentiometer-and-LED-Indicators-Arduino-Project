#include <Stepper.h>

int StepsPerRevolution = 2048;
float rpm;
int delay_time = 50;

int potpin = A0;
int potvalue;


// indicator led
int led1 = 2;
int led2 = 3;
int led3 = 4;
int led4 = 5;

Stepper mystepper(StepsPerRevolution, 8, 10, 9, 11);

void setup() {
  // put your setup code here, to run once:
pinMode(potpin,INPUT);
Serial.begin(9600);

for(int i = 2; i < 6; i++){
  pinMode(i, OUTPUT);
}

}

void loop() {
  // put your main code here, to run repeatedly:

potvalue = analogRead(potpin);

rpm = ((12 * potvalue) + 5115) / 1023.;
mystepper.setSpeed(rpm);

Serial.print("Current Reading is; \t");
Serial.println(rpm);

if (rpm >= 5 && rpm <= 8){
  digitalWrite(led1, HIGH);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
}

else if (rpm > 8.01 && rpm <= 12){
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
}

else if(rpm > 12.01 && rpm <= 14){
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, LOW);
}

else {
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);
}

mystepper.step(StepsPerRevolution);
mystepper.step(-StepsPerRevolution);

}
