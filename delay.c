#include <lpc21xx.h>
#include "delay.h"

void delay_ms(unsigned int ms) {
    unsigned int i, j;
    for (i = 0; i < ms; i++) {
        for (j = 0; j < 12000; j++) {
            /* Delay loop */
        }
    }
}