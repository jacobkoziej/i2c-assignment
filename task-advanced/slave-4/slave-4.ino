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

float temp_f;
uint8_t motor_speed;
uint8_t rgb_color[3];
void *i2c_data[3];
size_t i2c_datasiz[3];

volatile bool refresh = false;


void setup()
{
	lcd.begin(LCD_COL, LCD_ROW);
	lcd.print(F("TEMP:"));
	lcd.setCursor(8, 0);
	lcd.print(F("SPEED:"));
	lcd.setCursor(0, 1);
	lcd.print(F("COL:"));

	i2c_data[0]    = &temp_f;
	i2c_datasiz[0] = sizeof(temp_f);
	i2c_data[1]    = &motor_speed;
	i2c_datasiz[1] = sizeof(motor_speed);
	i2c_data[2]    = rgb_color;
	i2c_datasiz[2] = sizeof(rgb_color);

	Wire.begin(I2C_SLAVE_4);
	Wire.onReceive(i2c_receive_handler);
}

void loop()
{
	// TinkerCAD hangs with sprintf() so we must settle for this hack
	if (refresh) {
		// clear values
		lcd.setCursor(5, 0);
		lcd.print(F("  "));
		lcd.setCursor(14, 0);
		lcd.print(F("  "));
		lcd.setCursor(4, 1);
		lcd.print(F("      "));

		// write updated values
		lcd.setCursor(5, 0);
		lcd.print((temp_f >= 0) ? (int)temp_f : 0, HEX);
		lcd.setCursor(14, 0);
		lcd.print(motor_speed, HEX);
		lcd.setCursor(4, 1);
		lcd.print(rgb_color[0], HEX);
		lcd.setCursor(6, 1);
		lcd.print(rgb_color[1], HEX);
		lcd.setCursor(8, 1);
		lcd.print(rgb_color[2], HEX);

		refresh = false;
	}
}

void i2c_receive_handler(int bytes)
{
	static uint8_t i = 0;
	if (i >= 3) i = 0;
	receive_data(i2c_data[i], i2c_datasiz[i], bytes);
	++i;

	refresh = true;
}
