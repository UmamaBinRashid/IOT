const int ir = 2;
void setup() {
  
  pinMode(ir, INPUT);  //IR Sensor
  Serial.begin(9600);   //Arduino bode rate
}

void loop() {
  int data = digitalRead(ir);  //digital read which form (1 AND 0)
  Serial.println(data);  
}

