const int pir = 2;

void setup() 
{
  pinMode(4,OUTPUT);//DC motor connected to digital pin4
  pinMode(pir, INPUT);//PIR sensor connected to digitalpin2
  Serial.begin(9600);
}

void loop() {
  int pirdata = digitalRead(pir);  //Sensor detection value
  Serial.println(pirdata);    //print pirdata
  if(pirdata==1)        //condition if pirdata==1 ,motor is on
  { 
    digitalWrite(4,HIGH);
    delay(1000);
 
  }
  else        //Otherwise motor is off
  {
    digitalWrite(4,LOW);
    delay(1000);
  }
}
