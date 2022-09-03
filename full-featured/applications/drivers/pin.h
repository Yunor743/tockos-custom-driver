#pragma once

#define GPIO_DRIVER_NUM	0x00004

int pinCount();
int pinEnableOutput(int pin);
int pinSet(int pin);
int pinClear(int pin);
int pinToggle(int pin);
int pinGet(int pin);
