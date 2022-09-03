#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <timer.h>
#include <stdio.h>
#include "pin.h"
#include "locker.h"

// Output pin mapping :
// 1 KO
// 2 KO
// 3 OK
// 4 KO
// 5 OK
// 6 OK
// 7 KO
// 8 KO
// 9 OK
// 10 OK
// 11 OK
// 12 OK
// 13 OK

#define pin1 3
#define pin2 5
#define pin3 6
#define pin4 9
#define pin5 10
#define pin6 11
#define pin7 12

static void app(int iteration) {
    if (iteration == 0) {
        printf(" === PINS STATES ===\n");
        printf("Number of pins : %i\n", pinCount());
        lockerOk();
//        lockerStart();
    }
    // WRONG INPUT
    if (iteration == 1) {
        pinSet(pin4);
        printf("Set pin 4\n");
    }
    if (iteration == 2) {
        pinSet(pin5);
        printf("Set pin 5\n");
    }
    if (iteration == 3) {
        pinSet(pin6);
        printf("Set pin 6\n");
    }
    if (iteration == 4) {
        pinSet(pin7);
        printf("Set pin 7\n");
    }
    // CORRECT INPUT
    if (iteration == 5) {
        pinSet(pin1);
        printf("Set pin 1\n");
    }
    if (iteration == 6) {
        pinSet(pin2);
        printf("Set pin 2\n");
    }
    if (iteration == 7) {
        pinSet(pin3);
        printf("Set pin 3\n");
    }
    if (iteration == 8) {
        pinSet(pin4);
        printf("Set pin 4\n");
    }
    if (iteration == 10) {
        lockerStop();
        printf(" === Service Stopped | Simulation terminated ===\n");
    }
}

static bool same_length(int a, int b) {
    while (a > 0 && b > 0) {
        a /= 10;
        b /= 10;
    }
    if (a == 0 && b == 0)
        return true;
    return false;
}

static void logic(expected) {
    static int code = 0;
    // cannot do a loop here because of the way the macro are defined
    if (pinGet(pin1) == 1) {
        code = 1 + code * 10;
        pinClear(pin1);
    }
    if (pinGet(pin2) == 1) {
        code = 2 + code * 10;
        pinClear(pin2);
    }
    if (pinGet(pin3) == 1) {
        code = 3 + code * 10;
        pinClear(pin3);
    }
    if (pinGet(pin4) == 1) {
        code = 4 + code * 10;
        pinClear(pin4);
    }
    if (pinGet(pin5) == 1) {
        code = 5 + code * 10;
        pinClear(pin5);
    }
    if (pinGet(pin6) == 1) {
        code = 6 + code * 10;
        pinClear(pin6);
    }
    if (pinGet(pin7) == 1) {
        code = 7 + code * 10;
        pinClear(pin7);
    }

    if (expected == code) {
        printf("Succeed\r\n");
    } else if (!same_length(expected, code)) {
    } else {
        printf("Failed | Reset\r\n");
        code = 0;
    }
}

int main(void) {
    int iteration = 0;
    while (1) {
        app(iteration);
        //uncomment below to have a more fonctionnal secure code (exact check of the code) but it only use the pin without creating any driver
//        logic(1234);
        delay_ms(100); // 100ms => 1sec because of emulation slowness
        iteration++;
    }
    return 0;
}
