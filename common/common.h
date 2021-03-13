/*
 * common.h -- common header for common.cpp
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

#ifndef COMMON_H
#define COMMON_H

#include <Arduino.h>
#include <Wire.h>


// addresses
#define I2C_SLAVE_1 0x01
#define I2C_SLAVE_2 0x02
#define I2C_SLAVE_3 0x03
#define I2C_SLAVE_4 0x04

void receive_data(void *buffer, size_t bufsiz, int recsiz);
void request_data(void *buffer, size_t bufsiz, uint8_t reqsiz, uint8_t addr);
void send_data(void *data, size_t datasiz, uint8_t addr);

#endif /* COMMON_H */
