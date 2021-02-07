# Arduino LDR

LDR (Light Dependent Resistor) is a component that has a (variable) resistance that changes with the light intensity that falls upon it. This allows them to be used in light sensing circuits.

Arduino used: Arduino UNO

## Settings

```c
/* LDR sensor input pin */
#define sen 	A0

/* LED output pin */
#define led 	7

/* Average value between dark & light */
#define avrVal 	10

/* Delay between checking */
#define idelay	30
```