/*
 * Task 1 (slave-1)
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

char msg_buffer[11];
void *i2c_data;
size_t i2c_datasiz;


void setup()
{
	i2c_data    = msg_buffer;
	i2c_datasiz = sizeof(msg_buffer);

	Serial.begin(9600);
	Wire.begin(I2C_SLAVE_1);
}

void loop()
{
}
