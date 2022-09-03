#include "tock.h"
#include "arithmetic.h"

int add(int lhs, int rhs) {
	uint32_t ret;
  syscall_return_t res = command(ARITHMETIC_DRIVER_NUM, 0, lhs, rhs);
  tock_command_return_u32_to_returncode(res, &ret);
	return ret;
}

int sub(int lhs, int rhs) {
	uint32_t ret;
  syscall_return_t res = command(ARITHMETIC_DRIVER_NUM, 1, lhs, rhs);
  tock_command_return_u32_to_returncode(res, &ret);
	return ret;
}

int mul(int lhs, int rhs) {
	uint32_t ret;
  syscall_return_t res = command(ARITHMETIC_DRIVER_NUM, 2, lhs, rhs);
  tock_command_return_u32_to_returncode(res, &ret);
	return ret;
}

int div(int lhs, int rhs) {
	uint32_t ret;
  syscall_return_t res = command(ARITHMETIC_DRIVER_NUM, 3, lhs, rhs);
  tock_command_return_u32_to_returncode(res, &ret);
	return ret;
}

int mod(int lhs, int rhs) {
	uint32_t ret;
  syscall_return_t res = command(ARITHMETIC_DRIVER_NUM, 4, lhs, rhs);
  tock_command_return_u32_to_returncode(res, &ret);
	return ret;
}