int        ledUp=2;
int      ledDown=4;

int      buttonA=5;
int      buttonB=7;
int      buttonC=8;

int      motorUp=10; // Pin 2 of L293D
int    motorDown=11; // Pin 7 of L293D

int    switchTop=12;
int switchBottom=13;

void setup()
{
    // Motor, switches & leds
    pinMode(motorUp, OUTPUT);
    pinMode(motorDown, OUTPUT);
    pinMode(switchTop, OUTPUT);
    pinMode(switchBottom, OUTPUT);
    pinMode(ledUp, OUTPUT);
    pinMode(ledDown, OUTPUT);

    // Remote control
    pinMode(buttonA, INPUT);
    pinMode(buttonB, INPUT);
    pinMode(buttonC, INPUT);

    Serial.begin (9600);
}
 
void loop()
{
    if (digitalRead(buttonA)) {
        Serial.println("Button A, door down");
        doorDown();
    }
    if (digitalRead(buttonB)) {
        Serial.println("Button B, door up");
        doorUp();
    }
    if (digitalRead(buttonC)) {
        Serial.println("Button C, door stop");
        doorStop();
    }

    doorAction(motorDown,switchBottom);
    doorAction(motorUp,switchTop);
}

void motorDirection(int directionUp, int directionDown)
{
    digitalWrite(motorUp, directionUp);
    digitalWrite(motorDown, directionDown);
}
void ledSwitch(int directionUp, int directionDown)
{
    digitalWrite(ledUp, directionUp);
    digitalWrite(ledDown, directionDown);
}

void doorUp()
{
    motorDirection(HIGH,LOW);
    ledSwitch(HIGH,LOW);
}
void doorDown()
{
    motorDirection(LOW,HIGH);
    ledSwitch(LOW,HIGH);
}
void doorStop()
{
    motorDirection(LOW,LOW);
    ledSwitch(LOW,LOW);
}

void doorAction(int motorDir, int switchPosition)
{
    if(digitalRead(motorDir) == HIGH) {
        if(digitalRead(motorDown) == HIGH) {
            Serial.println("Door going down");
        } else {
            Serial.println("Door going up");
        }
        while(digitalRead(switchPosition) == LOW && digitalRead(motorDir) == HIGH) {
            Serial.println("Door closed");
            doorStop();
        }
    }
}
