#include <Arduino.h>
#define rpm_max 1000.0
#define rpm_min 0

void pwm_stop()
{
  TCCR4A &= ~(1<<COM4C1); // Disable PWM. Output voltage is zero.
}

void pwm_init()
{    
  // Configure variable PWM and enable pin, if required.
  DDRH |= (1<<DDH5); // Configure as PWM output pin 8.
  TCCR4A = ((1<< WGM40 ) | (1 << WGM41)); // Configure PWM output compare timer
  TCCR4B = ((1<<WGM42) | (1<<WGM43) | (1<<CS41));

  OCR4A = 2000 ; // Set the top value for fast PWM mode
  pwm_stop();
}

void setup() {
  // put your setup code here, to run once:
  pwm_init();
  OCR4C = 1000; // Set PWM output level.
  // pinMode(8,1);
}

void loop() {
    TCCR4A |= (1<<COM4C1); // Ensure PWM output is enabled.
}