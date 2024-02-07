#ifndef __LCD_H__
#define __LCD_H__

#include <LiquidCrystal.h>

static LiquidCrystal lcd(12, 11, 7, 6, 5, 4);

static void lcd_init() {
	lcd.begin(16, 2);
	lcd.clear();
	lcd.setCursor(0, 0);
	lcd.print("Amount:");
}

static void lcd_display(String input) {
	lcd.clear();
	lcd.setCursor(0, 0);
	lcd.print("Amount:");
	lcd.setCursor(0, 1);
	lcd.print(input);
}

#endif //__LCD_H__
