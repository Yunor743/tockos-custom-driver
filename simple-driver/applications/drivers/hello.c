#include "tock.h"
#include "hello.h"

void say_hello(void) {
	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wunused-result"
  command(HELLO_DRIVER_NUM, 1, 0, 0);
	#pragma GCC diagnostic pop
}