/*
 * Task 3 (slave-2)
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

uint8_t msg_buffer[6];
void *i2c_data;
size_t i2c_datasiz;

volatile bool new_data = false;


void setup()
{
	i2c_data    = msg_buffer;
	i2c_datasiz = sizeof(msg_buffer);

	Serial.begin(9600);

	Wire.begin(I2C_SLAVE_2);
	Wire.onReceive(i2c_receive_handler);
	Wire.onRequest(i2c_request_handler);
}

void loop()
{
	if (new_data) {
		Serial.print("Bytes in:");
		for (uint8_t i = 0; i < sizeof(msg_buffer); i++) {
			Serial.print(" ");
			Serial.print(msg_buffer[i], HEX);
		}
		Serial.println();

		new_data = false;
	}
}

void i2c_receive_handler(int bytes)
{
	receive_data(i2c_data, i2c_datasiz, bytes);
	new_data = true;
}

void i2c_request_handler(void)
{
	// NOTE: this only works for byte arrays
	for (uint8_t i = 0; i < i2c_datasiz; i ++)
		*((uint8_t*) i2c_data + i) *= 3;

	Wire.write((uint8_t*) i2c_data, i2c_datasiz);
}
