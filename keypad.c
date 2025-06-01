#include <lpc21xx.h>
#include "keypad.h"

#define ROW_PINS (0x0F << 16)  // P1.16-P1.19
#define COL_PINS (0x0F << 20)  // P1.20-P1.23

void keypad_init(void) {
    IO1DIR &= ~ROW_PINS;  // Rows as input
    IO1DIR |= COL_PINS;   // Columns as output
    IO1SET = COL_PINS;    // Set all columns high
}

char get_key(void) {
    const char keys[4][4] = {
        {'1','2','3','A'},
        {'4','5','6','B'},
        {'7','8','9','C'},
        {'*','0','#','D'}
    };
    unsigned int row, col;

    for (col = 0; col < 4; col++) {
        IO1CLR = (1 << (20 + col));
        for (row = 0; row < 4; row++) {
            if (!(IO1PIN & (1 << (16 + row)))) {
                while (!(IO1PIN & (1 << (16 + row))));  // Wait for release
                IO1SET = (1 << (20 + col));
                return keys[row][col];
            }
        }
        IO1SET = (1 << (20 + col));
    }
    return '\0';
}