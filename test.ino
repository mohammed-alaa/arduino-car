/*
 * LDR sensor
 * Author: Mohamed Alaa
 * Date: 07/02/2021
 */

/* LDR sensor input pin */
#define sen   A0

/* LED output pin */
#define led   7

/* Average value between dark & light */
#define avrVal  10

/* Delay between checking */
#define idelay  30

/* Global variable to store the sensor value */
int reading = 0;

void setup()
{
  /* Set sensor to input */
  pinMode(sen, INPUT);

  /* Set led to output */
  pinMode(led, OUTPUT);

  /* Begin serial in case printing the sensor reading value needed */
  Serial.begin(9600);
}

void loop()
{
  /* Store the sensor value */
  reading = analogRead(sen);

  /* Print the sensor value */
  Serial.println(reading);

  /* Turn the led on if the reading value is higher than the average value */
  digitalWrite(led, (reading <= avrVal));

  /* Delay */
  delay(idelay);
}
