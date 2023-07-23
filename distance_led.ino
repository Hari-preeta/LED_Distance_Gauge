//pin declarations for ultrasonic sensor
const int trig = 6;
const int echo = 7;
//pin decleration of led pins
const int LED1 = 2;
const int LED2 = 3;
const int LED3 = 4;
const int LED4 = 5;
const int LED5 = 8;
const int LED6 = 9;
const int LED7 = 10;
//variable for distance cal.
int duration = 0;
int distance = 0;

void setup()
{
  //initialising pins as input or output
  pinMode(trig , OUTPUT);
  pinMode(echo , INPUT);
 
  pinMode(LED1 , OUTPUT);
  pinMode(LED2 , OUTPUT);
  pinMode(LED3 , OUTPUT);
  pinMode(LED4 , OUTPUT);
  pinMode(LED5 , OUTPUT);
  pinMode(LED6 , OUTPUT);
  pinMode(LED7 , OUTPUT);
 //serial monitor is initialised
  Serial.begin(9600);

}

void loop()
{
  
  //distance calcultaed
  distance = distance_cal();
  //serial monitor prints distance
  Serial.print("distance is:");
  Serial.println(distance);
 
  //if conditions at various distance 
  if ( distance <= 6)
  {
    digitalWrite(LED1, HIGH);
    
  }
  else
  {
    digitalWrite(LED1, LOW);
  }
  if ( distance <= 25 )
  {
    digitalWrite(LED2, HIGH);
  }
  else
  {
    digitalWrite(LED2, LOW);
  }
  if ( distance <= 45 )
  {
    digitalWrite(LED3, HIGH);
  }
  else
  {
    digitalWrite(LED3, LOW);
  }
  if ( distance <= 55 )
  {
    digitalWrite(LED4, HIGH);
  }
  else
  {
    digitalWrite(LED4, LOW);
  }
  if ( distance <= 67 )
  {
    digitalWrite(LED5, HIGH);
  }
  else
  {
    digitalWrite(LED5, LOW);
  }
  if ( distance <= 88 )
  {
    digitalWrite(LED6, HIGH);
  }
  else
  {
    digitalWrite(LED6, LOW);
  }
  if ( distance <= 110 )
  {
    digitalWrite(LED7, HIGH);
  }
  else
  {
    digitalWrite(LED7, LOW);
  }
  //measure at every half second
  delay(500);
}

//function.. to return distance
int distance_cal()
{
  digitalWrite(trig , HIGH);
  delayMicroseconds(1000);
  digitalWrite(trig , LOW);


  duration = pulseIn(echo , HIGH);
   distance = duration *0.034/2 ;
  return distance;
}
