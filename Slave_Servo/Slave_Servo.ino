#define rfReceivePin A0  //RF Receiver pin = Analog pin 0
 #define ledPin 13        //Onboard LED = digital pin 13
 #include <Servo.h>

 Servo  servo;

 unsigned int data = 0;   // variable used tostore received data
 const unsigned int upperThreshold = 500;  //upper threshold value
 const unsigned int lowerThreshold = 480;  //lower threshold value

 void setup(){
   pinMode(ledPin, OUTPUT);
   Serial.begin(9600);
   servo.attach(9);
 }

 void loop(){
   data=analogRead(rfReceivePin);    //listen for data on Analog pin 0
   
    if(data<upperThreshold){
     digitalWrite(ledPin, LOW);   //If a LOW signal is received, turn LED OFF
     Serial.println(data);
     servo.write(0);
   }
   
   if(data>lowerThreshold){
     digitalWrite(ledPin, HIGH);   //If a HIGH signal is received, turn LED ON
     Serial.println(data);
     servo.write(90);
   }
 }
