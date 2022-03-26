int pin9b = 9;
int pin10g = 10;
int pin11r = 11;
int pin7 = 7;
int pin6 = 6;
float distanta;
void setup()
{
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(7, INPUT);
  pinMode(6, OUTPUT);
  
}

void loop()
{ 
  Serial.begin(9600);
  distanta = (senzor(pin6, pin7)/2) / 29.1;
  Serial.print("Distanta este: (cm) ");
  Serial.println();
  Serial.print(distanta);
  Serial.println();

  if(distanta > 0 && distanta < 30)
    rgb(0,0,255);
  if(distanta >= 30 && distanta <60)
    rgb(255,0,0);
  if(distanta >= 60)
    rgb(0,255,0);
  delay(2000);
}

void rgb(int valb, int valg, int valr)
{
  analogWrite(pin9b, valb);
  analogWrite(pin10g, valg);
  analogWrite(pin11r, valr);
}

unsigned long senzor(int pin6, int pin7 )
{
  digitalWrite(pin6, 0);
  delayMicroseconds(5);
  digitalWrite(pin6, 1);
  delayMicroseconds(10);
  digitalWrite(pin6, 0);

  return pulseIn(pin7, 1);

}