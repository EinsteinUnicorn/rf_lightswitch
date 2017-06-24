 #define rfTransmitPin 4  //RF Transmitter pin = digital pin 4
 #define buttonPin 2    
 #define led 13    
 
void setup() {
  // put your setup code here, to run once:
pinMode(rfTransmitPin, OUTPUT);     
   pinMode(buttonPin, INPUT);   
   pinMode(led, OUTPUT); 
   Serial.begin(9600);
}

int buttonState = 0; 

void loop() {
  // put your main code here, to run repeatedly:
buttonState = digitalRead(buttonPin);
   if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(rfTransmitPin, HIGH);
    digitalWrite(led, HIGH);
    Serial.println("transmit");
    delay(10);
  } else {
    // turn LED off:
    digitalWrite(rfTransmitPin, LOW);
    digitalWrite(led, LOW);
    Serial.println("no");
  }

}
