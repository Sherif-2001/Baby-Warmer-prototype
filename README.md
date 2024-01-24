# Baby Warmer Prototype
  **[NTC Thermistor Data sheet](https://www.vishay.com/docs/29154/ntcle213e3.pdf)**

## Summary
The main purpose of this system is to keep the baby's environment at a suitable temperature (which is about 37.8C), this is done by measuring the ambient temperature using the thermistor and then using a heating element to raise this temperature until it reaches this threshold and occasionally turn on again to keep it in that range.

## Circuit Diagram
![circuit schematic](baby_warmer_schematic.jpg)

## Hardware Components:
<ol>
  <li>Thermistor </li>
  <li>Arduino Uno board + cable. </li>
  <li>Fixed 10 KOhm resistor. </li>
  <li>Some jumper cables.</li>
  <li>Bread board </li>
  <li>5v 220V relay module</li>
  <li>100w lightbulb (or other similar heat source)</li>
  <li>Electrical housing to connect the lightbulb into</li>
  <li>Model bed + model baby (optional).</li>

</ol>

## Prototype photo
![Prototype image one](baby_warmer_prototype.jpg)
<center>
<p>The sensor is placed on the baby's abdomen (modeled here by the doll). and the heating element is kept as close as possible to the baby to minimize heat loss.</p>
</center>

## Software Code
1. Measure the resistance of the thermistor (R2 in the code.)
2. Calculate the temperature kelvin and convert to celsius.
3. control the heating element until it reaches desired range.
4. it turns on the heat if temperature is below minimum value of the range and then turn it off when it reaches maximum value of the range. In this case it's called (min_temp and max_temp respectively).

#### Measuring the resistance of the thermistor.
it's a basic voltage divider circuit, the analog pin measures the voltage across the 10k resistor and then we calculate the thermistor resistance (noted R2),

#### Measuring the temperature
The formula used is standard for these types of sensors, called the stein-hart equation, there's a lot of math there, but most of it is boring, for now, this works accurately enough.  
The response time is about 1 to 4 seconds (according to the datasheet.), which is more than fast enough for this application.

## Limitations
- In cold environments, use a suitable heating element to compensate.
- Consider minimizing heat loss to the atmosphere for more effective temperature regulation.
- The prototype's heating element consumes significant power (100 watts), equivalent to 10 LED bulbs.
