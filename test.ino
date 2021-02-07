/*
 * RC bluetooth car
 * Author: Mohamed Alaa
 * Date: 07/02/2021
 */

/* Motor A pin 1 */
const int motorA1 = 4;

/* Motor A  pin 2 */
const int motorA2 = 5;

/* Motor B pin 1 */
const int motorB1 = 6;

/* Motor B pin 2 */
const int motorB2 = 7;

/* Motor A enable pin */
const int motorAEn = 8;

/* Motor B enable pin */
const int motorBEn = 9;

/* Variable to store the bluetooth reading value */
char ch;

void setup()
{
  /* Begin serial to print the bluetooth reading value */
  Serial.begin(9600);

  /* Set motor A pin 1 to output */
  pinMode(motorA1, OUTPUT);

  /* Set motor A pin 2 to output */
  pinMode(motorA2, OUTPUT);

  /* Set motor B pin 1 to output */
  pinMode(motorB1, OUTPUT);

  /* Set motor B pin 2 to output */
  pinMode(motorB2, OUTPUT);

  /* Set motor A to output */
  pinMode(motorAEn, OUTPUT);

  /* Set motor B to output */
  pinMode(motorBEn, OUTPUT);

  /* Enable motors */
  turnMotorsOn();
}

/* Enable motors */
void turnMotorsOn(void)
{
  /* Set motor A to high */
  digitalWrite(motorAEn, HIGH);

  /* Set motor B to high */
  digitalWrite(motorBEn, HIGH);
}

/* Move motor A forward */
void forwardMotorA(void)
{
  /* Set motor A pin 1 to high */
  digitalWrite(motorA1, HIGH);

  /* Set motor A pin 2 to low */
    digitalWrite(motorA2, LOW);
}

/* Move motor A backward */
void backwardMotorA(void)
{
  /* Set motor A pin 1 to low */
  digitalWrite(motorA1, LOW);

  /* Set motor A pin 2 to high */
    digitalWrite(motorA2, HIGH);
}

/* Stop motor A */
void stopMotorA(void)
{
  /* Set both motor A pins to low */
  digitalWrite(motorA1, LOW);
    digitalWrite(motorA2, LOW);
}

/* Move motor B forward */
void forwardMotorB(void)
{
  /* Set motor B pin 1 to high */
  digitalWrite(motorB1, HIGH);

  /* Set motor B pin 2 to low */
    digitalWrite(motorB2, LOW);
}

/* Move motor B backward */
void backwardMotorB(void)
{
  /* Set motor B pin 1 to low */
  digitalWrite(motorB1, LOW);

  /* Set motor B pin 2 to high */
    digitalWrite(motorB2, HIGH);
}

/* Stop motor B */
void stopMotorB(void)
{
  /* Set both motor B pins to low */
  digitalWrite(motorB1, LOW);
    digitalWrite(motorB2, LOW);
}

/* Move the car forward */
void forward(void)
{
  /* Move both motors forward */
  forwardMotorA();
  forwardMotorB();
}

/* Move the car backward */
void backward(void)
{
  /* Move both motors backward */
  backwardMotorA();
  backwardMotorB();
}

/* Move the car right */
void right(void)
{
  /* Move motor A forward & motor B backward */
  forwardMotorA();
  backwardMotorB();
}

/* Move the car left */
void left(void)
{
  /* Move motor A backward & motor B forward */
  backwardMotorA();
  forwardMotorB();
}

/* Stop the car */
void stop(void)
{
  /* Stop both motors */
  stopMotorA();
  stopMotorB();
}

void loop(void)
{
  /* If there's an input from the bluetooth */
  if (Serial.available())
  {
    /* Read & store the input value */
    ch = Serial.read();

    /* Switch the input value */
    switch(ch)
    {
      /* Move the car forward */
      case 'F':
        forward();
        break;
      /* Move the car backward */
      case 'B':
        backward();
        break;
      /* Move the car right */
      case 'R':
        right();
        break;
      /* Move the car LEFT */
      case 'L':
        left();
        break;
      /* Stop the car */
      case 'S':
      default:
        stop();
        break;
    }
  }
}
