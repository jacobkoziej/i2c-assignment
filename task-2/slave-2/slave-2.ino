/*
 * Task 2 (slave-2)
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

uint8_t odd_nums[6]  = {1, 3, 5, 7, 9, 11};
void *i2c_data;
size_t i2c_datasiz;


void setup()
{
	i2c_data    = odd_nums;
	i2c_datasiz = sizeof(odd_nums);

	Wire.begin(I2C_SLAVE_2);
	Wire.onRequest(i2c_request_handler);
}

void loop()
{
}

void i2c_request_handler(void)
{
	Wire.write((uint8_t*) i2c_data, i2c_datasiz);
}
