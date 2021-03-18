/*
 * Task Advanced (slave-4)
 * Copyright (C) 2021  Jacob Koziej <jacobkoziej@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <LiquidCrystal.h>
#include <Wire.h>

#include "common.h"

#define LCD_RS     2
#define LCD_ENABLE 3
#define LCD_D4     4
#define LCD_D5     5
#define LCD_D6     6
#define LCD_D7     7

#define LCD_COL 16
#define LCD_ROW 2

LiquidCrystal lcd(
		LCD_RS,
		LCD_ENABLE,
		LCD_D4,
		LCD_D5,
		LCD_D6,
		LCD_D7
		);

void *i2c_data;
size_t i2c_datasiz;


void setup()
{
	lcd.begin(LCD_COL, LCD_ROW);
	lcd.print(F("TEMP:"));
	lcd.setCursor(8, 0);
	lcd.print(F("SPEED:"));
	lcd.setCursor(0, 1);
	lcd.print(F("COL:"));

	Wire.begin(I2C_SLAVE_4);
	Wire.onReceive(i2c_receive_handler);
}

void loop()
{
}

void i2c_receive_handler(int bytes)
{
	receive_data(i2c_data, i2c_datasiz, bytes);
}
