int led1=2;
int led2=4;
int direction1=10;  // Pin 2 of L293D
int direction2=11;  // Pin 7 of L293D
int stop1=12;
int stop2=13;

void setup()
{
  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);
  pinMode(stop1, OUTPUT);
  pinMode(stop2, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);

  Serial.begin (9600);
  for (int i = 5 ; i <= 8 ; i++)
    pinMode(i, INPUT) ;
}
 
void loop()
{
    if (digitalRead(5)) {
        Serial.println( "Button A");
        digitalWrite(direction1,LOW);
        digitalWrite(direction2,HIGH);
        digitalWrite(led1,HIGH);
        digitalWrite(led2,LOW);
    } else if (digitalRead(7)) {
        Serial.println( "Button B");
        digitalWrite(direction1,HIGH);
        digitalWrite(direction2,LOW);
        digitalWrite(led1,LOW);
        digitalWrite(led2,HIGH);
    } else if (digitalRead(8)) {
        Serial.println( "Button C");
        digitalWrite(direction1,LOW);
        digitalWrite(direction2,LOW);
        digitalWrite(led1,LOW);
        digitalWrite(led2,LOW);
    }

  if (digitalRead(stop1) == LOW || digitalRead(stop2) == LOW) {
    Serial.println("HOLA");
    digitalWrite(direction1,LOW);
    digitalWrite(direction2,LOW);
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
  }
}
