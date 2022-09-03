#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <timer.h>
#include <stdio.h>
#include "hello.h"
#include "arithmetic.h"
#include "logic.h"

// #include <console.h>

// static void nop(
  // int a __attribute__((unused)),
  // int b __attribute__((unused)),
  // int c __attribute__((unused)),
  // void* d __attribute__((unused))) {}

static void app(void) {
  say_hello();
  printf(" === LOGIC ===\n");
  printf("1 and 0 = %i\n", and(1, 0));
  printf("0 and 1 = %i\n", and(0, 1));
  printf("1 and 1 = %i\n", and(1, 1));
  printf("0 and 0 = %i\n", and(0, 0));
  printf("1 or 0 = %i\n", or(1, 0));
  printf("0 or 1 = %i\n", or(0, 1));
  printf("1 or 1 = %i\n", or(1, 1));
  printf("0 or 0 = %i\n", or(0, 0));
  printf(" === ARITHMETIC ===\n");
  printf("22 + 10 = %i\n", add(22, 10));
  printf("22 - 10 = %i\n", sub(22, 10));
  printf("22 * 10 = %i\n", mul(22, 10));
  printf("22 / 10 = %i\n", div(22, 10));
  printf("22 %% 10 = %i\n", mod(22, 10));
}

int main(void) {
  // putnstr_async(hello, strlen(hello), nop, NULL);
  while (1) {
    app();
    printf("Program will restart in 10sec\n");
    delay_ms(1000);
  }
  return 0;
}
