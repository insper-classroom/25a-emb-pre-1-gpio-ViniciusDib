#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int BTN_PIN = 28;
const int BTN_PIN2 = 26;
const int LED_PIN_R = 4;
const int LED_PIN_G = 6;


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
  
  bool g = false;
  bool r = false;

  while (true) {
    if (!gpio_get(BTN_PIN)){
      sleep_ms(100);
      while (!gpio_get(BTN_PIN)){
      r = !r;
      gpio_put(LED_PIN_R,r);
      sleep_ms(100);   
      }
    }

    if (!gpio_get(BTN_PIN2)){
        sleep_ms(100);
        while (!gpio_get(BTN_PIN2)){
        g = !g;
        gpio_put(LED_PIN_G,g);
        sleep_ms(100);
        }
    }
  sleep_ms(10);   
  }  

}





