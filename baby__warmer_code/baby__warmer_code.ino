// defining the variables and pin numbers.
int ThermistorPin = 0;
int Vo;
int relaypin = 10;
float R1 = 10000;
float logR2, R2, Tk, Tc;
int min_temp = 36.3;
int max_temp = 39;
float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07; //stein-hart variables

void setup()
{
Serial.begin(9600);
pinMode(7, OUTPUT);
}

void loop() 
{
  //this block measures the resistance (NTC), and then calculates the temperature based on it.
  Vo = analogRead(ThermistorPin);
  R2 = R1 * (1023.0 / (float)Vo - 1.0); // voltage devide rule to find the thermoister resistance
  logR2 = log(R2);
  Tk = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2)); // stein-hart equation to find the temperature based on the resistance in kelvin
  Tc = Tk - 273.15;  //convert kelvin to celcuis
  
  //print out the temperature onto the serial monitor.
  Serial.print("Temperature: "); 
  Serial.print(Tc);
  Serial.println(" C");   

  //here we run a check on the temperature.
if (Tc <= min_temp)
  {
    //this means that temperature is low, we must turn on the heat source (relay)
    digitalWrite(relaypin, HIGH);
  }
  else if( Tc >= max_temp)
  {
    //this means that the temperature is now optimal, we must turn off the heat source
    digitalWrite(relaypin, LOW);
  }
  
  delay(500);
  /*the 500 is written in ms, it's more than enough for continous monitroing of a baby's temperature
  however, if you're running this sensor in a very small range, it would be best to decrease this delay a little bit.
  (maybe 100 ms or something like that.)*/
  
}
