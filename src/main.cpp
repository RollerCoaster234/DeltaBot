#include <Arduino.h>
#include <timer.hpp>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  // timer::Timer stepperTimer;
  timer::TimerConfiguration config;
  config.SetTimer(timer::TimerConfiguration::Timer0);
  uint8_t arr[] = {1,3};
  config.SetOutputPins(arr);
    delete[] arr;

  config.SetTimer(timer::TimerConfiguration::Timer1);
  uint8_t arr2[] = {2,4};
  config.SetOutputPins(arr2);
    delete[] arr2;


  config.SetTimer(timer::TimerConfiguration::Timer2);
  uint8_t arr3[] = {3,5};
  config.SetOutputPins(arr3);
    delete[] arr3;

  config.SetTimer(timer::TimerConfiguration::Timer0);
  uint8_t arr4[] = {6,8};
  config.SetOutputPins(arr4);
    delete[] arr4;
}

void loop() {
  // put your main code here, to run repeatedly:
}
