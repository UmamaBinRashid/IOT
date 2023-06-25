const int ir = A1;
void setup() {
  
  pinMode(ir, INPUT);  //IR Sensor
  Serial.begin(9600);   //Arduino bode rate
}

void loop() {
  int data = analogRead(ir);  //analog read which form (0 to 1023)
  Serial.println(data);  
}

