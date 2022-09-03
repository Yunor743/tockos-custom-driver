#include "tock.h"
#include "pin.h"

int pinCount() {
	uint32_t ret;
    syscall_return_t res = command(GPIO_DRIVER_NUM, 0, 0, 0);
    tock_command_return_u32_to_returncode(res, &ret);
	return ret;
}

int pinEnableOutput(int pin) {
	uint32_t ret;
    syscall_return_t res = command(GPIO_DRIVER_NUM, 1, pin, 0);
    tock_command_return_u32_to_returncode(res, &ret);
	return ret;
}

int pinSet(int pin) {
	uint32_t ret;
    syscall_return_t res = command(GPIO_DRIVER_NUM, 2, pin, 0);
    tock_command_return_u32_to_returncode(res, &ret);
	return ret;
}

int pinClear(int pin) {
	uint32_t ret;
    syscall_return_t res = command(GPIO_DRIVER_NUM, 3, pin, 0);
    tock_command_return_u32_to_returncode(res, &ret);
	return ret;
}

int pinToggle(int pin) {
	uint32_t ret;
    syscall_return_t res = command(GPIO_DRIVER_NUM, 4, pin, 0);
    tock_command_return_u32_to_returncode(res, &ret);
	return ret;
}

int pinGet(int pin) {
	uint32_t ret;
    syscall_return_t res = command(GPIO_DRIVER_NUM, 6, pin, 0);
    tock_command_return_u32_to_returncode(res, &ret);
	return ret;
}

