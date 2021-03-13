/*
 * common.cpp -- common functions for I2C assignment
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

#include "common.h"


void receive_data(void *buffer, size_t bufsiz, int recsiz)
{
	memset(buffer, 0, bufsiz);

	uint8_t *tracer = (uint8_t*) buffer;

	for (uint16_t i = 0; i < bufsiz && i < recsiz; i++) {
		tracer[i] = Wire.read();
	}
}

void request_data(void *buffer, size_t bufsiz, uint8_t reqsiz, uint8_t addr)
{
	Wire.requestFrom(addr, reqsiz);
	receive_data(buffer, bufsiz, reqsiz);

	// drop any data that didn't fit in the buffer
	while (Wire.available()) Wire.read();
}

void send_data(void *data, size_t datasiz, uint8_t addr)
{
	Wire.beginTransmission(addr);
	Wire.write((uint8_t*) data, datasiz);
	Wire.endTransmission();
}
