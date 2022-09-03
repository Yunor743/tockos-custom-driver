#include "tock.h"
#include "logic.h"

int and(int lhs, int rhs) {
	uint32_t ret;
  syscall_return_t res = command(LOGIC_DRIVER_NUM, 0, lhs, rhs);
  tock_command_return_u32_to_returncode(res, &ret);
	return ret;
}

int or(int lhs, int rhs) {
	uint32_t ret;
  syscall_return_t res = command(LOGIC_DRIVER_NUM, 1, lhs, rhs);
  tock_command_return_u32_to_returncode(res, &ret);
	return ret;
}