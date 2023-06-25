const int pir = A1;//analogpinA1

void setup() 
{
  pinMode(4,OUTPUT);//DC motor connected to digital pin4
  pinMode(pir, INPUT);//PIR sensor connected to analogpinA1 it's our input
  Serial.begin(9600);
}

void loop() {
  int pirdata = analogRead(pir);  //Sensor detection value
  Serial.println(pirdata);    //print pirdata
  if(pirdata>=1000)        //condition if pirdata==1 ,motor is on
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
