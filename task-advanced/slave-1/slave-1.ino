/*
 * Task Advanced (slave-1)
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

#define TMP36 A3

float temp_f;
void *i2c_data;
size_t i2c_datasiz;


void setup()
{
	pinMode(TMP36, INPUT);

	i2c_data    = &temp_f;
	i2c_datasiz = sizeof(temp_f);

	Wire.begin(I2C_SLAVE_1);
	Wire.onRequest(i2c_request_handler);
}

void loop()
{
}

void i2c_request_handler(void)
{
	Wire.write((uint8_t*) i2c_data, i2c_datasiz);
}
