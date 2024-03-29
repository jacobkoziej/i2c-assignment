/*
 * Task Advanced (slave-3)
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

#include <Wire.h>

#include "common.h"

#define RGB_LED 9  // base index for RGB LED

uint8_t color[3];
void *i2c_data;
size_t i2c_datasiz;


void setup()
{
	for (uint8_t i = 0; i < 3; i++)
		pinMode(RGB_LED + i, OUTPUT);

	i2c_data    = color;
	i2c_datasiz = sizeof(color);

	Wire.begin(I2C_SLAVE_3);
	Wire.onReceive(i2c_receive_handler);
}

void loop()
{
	for (uint8_t i = 0; i < 3; i++)
		analogWrite(RGB_LED + i, color[i]);
}

void i2c_receive_handler(int bytes)
{
	receive_data(i2c_data, i2c_datasiz, bytes);
}
