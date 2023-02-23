#include <iostream>
#include <unistd.h>

// lib pigpio refer to http://abyz.me.uk/rpi/pigpio/
#include <pigpio.h>
#include <glog/logging.h>

#define PWM_PIN        21U
#define PWM_FRQ        500U  // Hz
#define PWM_DUTY_RANGE 100U
#define PWM_DUTY       50U

int main(int argc, char **argv)
{
  if (gpioInitialise() < 0)
  {
    LOG(INFO) << " gpio init failed.";
  }
  else
  {
    LOG(INFO) << " gpio init success.";
  }

  // set gpio mode = pwm
  gpioSetMode(PWM_PIN, PI_ALT0);
  // set pwm frq
  gpioSetPWMfrequency(PWM_PIN, PWM_FRQ);
  // set pwm duty range
  gpioSetPWMrange(PWM_PIN, PWM_DUTY_RANGE);
  // start pwm by duty
  gpioPWM(PWM_PIN, PWM_DUTY);

  LOG(INFO) << " PWM is on ,"
            << " Frequency = " << PWM_FRQ << "Hz ,"
            << " Duty = " << PWM_DUTY << "/" << PWM_DUTY_RANGE;

  while (true)
  {
  }

  return 0;
}
