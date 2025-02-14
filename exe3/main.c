#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int BTN_PIN = 26;
const int BTN_PIN2 = 28;
const int LED_PIN_R = 6;
const int LED_PIN_G = 4;


int main() {
  stdio_init_all();

  gpio_init(LED_PIN_R);
  gpio_set_dir(LED_PIN_R, GPIO_OUT);
  gpio_init(LED_PIN_G);
  gpio_set_dir(LED_PIN_G, GPIO_OUT);


  gpio_init(BTN_PIN);
  gpio_set_dir(BTN_PIN, GPIO_IN);
  gpio_pull_up(BTN_PIN);

  gpio_init(BTN_PIN2);
  gpio_set_dir(BTN_PIN2, GPIO_IN);
  gpio_pull_up(BTN_PIN2);


  while (true) {

    if (!gpio_get(BTN_PIN)) {
      sleep_ms(50);
        if(gpio_get(LED_PIN_R)){
          gpio_put(LED_PIN_R, 0);
        }
        else {
          gpio_put(LED_PIN_R, 1);
        }

    }
    if (!gpio_get(BTN_PIN2)) {
      sleep_ms(50);
        if(gpio_get(LED_PIN_G)){
          gpio_put(LED_PIN_G, 0);
        }
        else {
          gpio_put(LED_PIN_G, 1);
        }
    } 
  }
}








