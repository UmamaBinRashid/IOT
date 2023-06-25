const int gassensor = A1;

void setup() {
  pinMode(2,OUTPUT);//LED Connected digital pin 2
  pinMode(gassensor, INPUT);  //Gas Sensor
  Serial.begin(9600);   //Arduino bode rate
}

void loop() {
  int data = analogRead(gassensor);  //analog read which form (0 to 1023)
  Serial.println(data); 
  if (data>=500)
  {
    digitalWrite(2,HIGH);
    delay(1000);
  }
  else
  {
      digitalWrite(2,LOW);
      delay(1000);
  } 
}

