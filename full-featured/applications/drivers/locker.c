#include "tock.h"
#include "locker.h"

void lockerOk(void) {
	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wunused-result"
    command(LOCKER_DRIVER_NUM, LOCKER_DRIVER_ACTION_OK, 0, 0);
	#pragma GCC diagnostic pop
}

void lockerStart(void) {
	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wunused-result"
    command(LOCKER_DRIVER_NUM, LOCKER_DRIVER_ACTION_START, 0, 0);
	#pragma GCC diagnostic pop
}

void lockerStop(void) {
	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wunused-result"
    command(LOCKER_DRIVER_NUM, LOCKER_DRIVER_ACTION_STOP, 0, 0);
	#pragma GCC diagnostic pop
}
