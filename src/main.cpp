#include <iostream>
#include <unistd.h>

// lib pigpio refer to http://abyz.me.uk/rpi/pigpio/
#include <pigpio.h>
#include <glog/logging.h>

#define PWM_PIN 21

int main(int argc, char **argv)
{
  int status = gpioInitialise();
  LOG(INFO) << "gpio init = " << status;

  // set gpio mode = pwm
  gpioSetMode(PWM_PIN, PI_ALT0);
  // set pwm frq
  gpioSetPWMfrequency(PWM_PIN, 500);
  // set pwm duty range
  gpioSetPWMrange(PWM_PIN, 100);
  // start pwm by duty
  gpioPWM(PWM_PIN, 50);

  while (true)
  {
  }

  return 0;
}
