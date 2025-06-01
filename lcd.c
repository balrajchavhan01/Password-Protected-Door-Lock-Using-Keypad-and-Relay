#include <lpc21xx.h>
#include "delay.h"
#include "lcd.h"

#define LCD_DATA_DIR IO0DIR
#define LCD_DATA_SET IO0SET
#define LCD_DATA_CLR IO0CLR

#define LCD_CTRL_DIR IO1DIR
#define LCD_CTRL_SET IO1SET
#define LCD_CTRL_CLR IO1CLR

#define RS (1 << 23)
#define EN (1 << 24)

void lcd_cmd(unsigned char cmd) {
    LCD_DATA_CLR = 0x000000FF;
    LCD_DATA_SET = (cmd & 0xF0);
    LCD_CTRL_CLR = RS;
    LCD_CTRL_SET = EN;
    delay_ms(2);
    LCD_CTRL_CLR = EN;
}

void lcd_data(unsigned char data) {
    LCD_DATA_CLR = 0x000000FF;
    LCD_DATA_SET = (data & 0xF0);
    LCD_CTRL_SET = RS;
    LCD_CTRL_SET = EN;
    delay_ms(2);
    LCD_CTRL_CLR = EN;
}

void lcd_init(void) {
    LCD_DATA_DIR |= 0x000000FF;
    LCD_CTRL_DIR |= (RS | EN);
    delay_ms(20);
    lcd_cmd(0x02);
    lcd_cmd(0x28);
    lcd_cmd(0x0C);
    lcd_cmd(0x06);
    lcd_cmd(0x01);
    delay_ms(2);
}

void lcd_print(char *str) {
    while (*str) {
        lcd_data(*str++);
    }
}