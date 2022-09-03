#pragma once

#define LOCKER_DRIVER_NUM	0xa0004

#define LOCKER_DRIVER_ACTION_OK         0
#define LOCKER_DRIVER_ACTION_START      1
#define LOCKER_DRIVER_ACTION_STOP       2

void lockerOk(void);
void lockerStart(void);
void lockerStop(void);
