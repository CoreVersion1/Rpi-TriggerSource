#include "main.hpp"

#include <iostream>
#include <unistd.h>

#include <pigpio.h>
#include <glog/logging.h>

int main(int argc, char **argv)
{
  int gpio_cfg = gpioCfgGetInternals();
  gpio_cfg |= PI_CFG_NOSIGHANDLER; // (1<<10)
  gpioCfgSetInternals(gpio_cfg);
  int status = gpioInitialise();
  LOG(INFO) << "gpio init = " << status;

  LOG(INFO) << "gpio GPIO_TRIGGER_OUT output    = " << gpioSetMode(27, PI_OUTPUT);
  LOG(INFO) << "gpio GPIO_TRIGGER_OUT pull down = " << gpioSetPullUpDown(27, PI_PUD_DOWN);

  while (true)
  {
    sleep(2);
    LOG(INFO) << "Write GPIO_TRIGGER_OUT High   = " << gpioWrite(27, 1);
    sleep(2);
    LOG(INFO) << "Write GPIO_TRIGGER_OUT Low    = " << gpioWrite(27, 0);
  }

  return 0;
}
