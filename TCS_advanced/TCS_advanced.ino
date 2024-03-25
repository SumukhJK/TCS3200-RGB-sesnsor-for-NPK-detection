#define S0  6

#define S1  7

#define S2  8

#define S3  9

#define Out 10

int redLed = 11;

int greenLed = 12;

int blueLed = 13;

void setup() {

    Serial.begin(9600); // Change the baud rate to 9600

    pinMode(S0, OUTPUT);

    pinMode(S1, OUTPUT);

    pinMode(S2, OUTPUT);

    pinMode(S3, OUTPUT);

    pinMode(redLed, OUTPUT);

    pinMode(greenLed, OUTPUT);

    pinMode(blueLed, OUTPUT);

    pinMode(Out, INPUT_PULLUP); // Use INPUT_PULLUP to enable the internal pull-up resistor on the input pin

    digitalWrite(S0, HIGH);

    digitalWrite(S1, LOW); // Setting frequency selection to 20%

} 

void loop() {

    digitalWrite(S2, LOW);

    digitalWrite(S3, LOW); // Setting for RED color sensor

    int redFrequency = pulseIn(Out, LOW); // Reading frequency

    Serial.print("K: ");

    Serial.print(redFrequency);

    Serial.print("  ");

    delay(500);

    digitalWrite(S2, LOW);

    digitalWrite(S3, HIGH); // Setting for BLUE color sensor

    int blueFrequency = pulseIn(Out, LOW); // Reading frequency

    Serial.print("N: ");

    Serial.print(blueFrequency);

    Serial.print("  ");

    delay(500);

    digitalWrite(S2, HIGH);

    digitalWrite(S3, HIGH); // Setting for GREEN color sensor

    int greenFrequency = pulseIn(Out, LOW); // Reading frequency

    Serial.print("P: ");

    Serial.print(greenFrequency);

    //Serial.println();

    if (redFrequency < blueFrequency && redFrequency < greenFrequency && redFrequency < 40) {

        Serial.println("  - (Potassium Maximum)");

        digitalWrite(redLed, HIGH);   // Turn RED LED ON

        digitalWrite(greenLed, LOW);

        digitalWrite(blueLed, LOW);

    }

    else if (blueFrequency < redFrequency && blueFrequency < greenFrequency && blueFrequency < 50) {

        Serial.println("  - (Nitrogen Maximum))");

        digitalWrite(redLed, LOW);

        digitalWrite(greenLed, LOW);

        digitalWrite(blueLed, HIGH); // Turn BLUE LED ON

    }

    else if (greenFrequency < redFrequency && greenFrequency < blueFrequency && greenFrequency < 85) {

        Serial.println("  - (Phosphorous maximum)");

        digitalWrite(redLed, LOW);

        digitalWrite(greenLed, HIGH); // Turn GREEN LED ON

        digitalWrite(blueLed, LOW);

    }

    else {

        Serial.println("  - (Low visibility)");

        digitalWrite(redLed, LOW);

        digitalWrite(greenLed, LOW);

        digitalWrite(blueLed, LOW);

    }

    delay(500); // Add a delay before the next reading to reduce rapid changes

}