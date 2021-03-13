/*
 * Task 2 (master)
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

uint8_t even_nums[6];
uint8_t odd_nums[6];
uint8_t some_nums[6];
char unfunny_message[11];


void setup()
{
	Serial.begin(9600);

	Wire.begin();
}

void loop()
{
	request_data(
		even_nums,
		sizeof(even_nums),
		sizeof(even_nums),
		I2C_SLAVE_1
		);
	request_data(
		odd_nums,
		sizeof(odd_nums),
		sizeof(odd_nums),
		I2C_SLAVE_2
		);
	request_data(
		unfunny_message,
		sizeof(unfunny_message),
		sizeof(unfunny_message),
		I2C_SLAVE_3
		);
	request_data(
		some_nums,
		sizeof(some_nums),
		sizeof(some_nums),
		I2C_SLAVE_4
		);


	Serial.print("Slave 1:");
	for (uint8_t i = 0; i < sizeof(even_nums); i++) {
		Serial.print(" ");
		Serial.print(even_nums[i], HEX);
	}
	Serial.println();

	Serial.print("Slave 2:");
	for (uint8_t i = 0; i < sizeof(odd_nums); i++) {
		Serial.print(" ");
		Serial.print(odd_nums[i], HEX);
	}
	Serial.println();

	Serial.print("Slave 3: ");
	Serial.println(unfunny_message);

	Serial.print("Slave 4:");
	for (uint8_t i = 0; i < sizeof(some_nums); i++) {
		Serial.print(" ");
		Serial.print(some_nums[i], HEX);
	}
	Serial.println();
}
