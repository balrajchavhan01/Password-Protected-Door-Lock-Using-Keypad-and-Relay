#include <lpc21xx.h>
#include <string.h>
#include "lcd.h"
#include "keypad.h"
#include "delay.h"

#define RELAY_PIN (1 << 25)

int main(void) {
    char password[] = "1234";
    char entered[5];
    char key;
    unsigned int i, j;

    IODIR0 |= RELAY_PIN;
    IOCLR0 = RELAY_PIN;

    keypad_init();
    lcd_init();
    lcd_cmd(0x80);
    lcd_print("Enter Password:");

    while (1) {
        i = 0;
        while (i < 4) {
            key = get_key();
            if (key) {
                entered[i++] = key;
                lcd_cmd(0xC0 + i - 1);
                lcd_print("*");
                delay_ms(300);
            }
        }
        entered[4] = '\0';

        if (strcmp(entered, password) == 0) {
            lcd_cmd(0xC0);
            lcd_print("Access Granted");
            IOSET0 = RELAY_PIN;
            delay_ms(3000);
            IOCLR0 = RELAY_PIN;
        } else {
            lcd_cmd(0xC0);
            lcd_print("Wrong!");
            delay_ms(1000);
        }

        for (j = 0; j < 5; j++) {
            entered[j] = '\0';
        }
        lcd_cmd(0x01);
        lcd_cmd(0x80);
        lcd_print("Enter Password:");
    }
}