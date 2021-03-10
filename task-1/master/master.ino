/*
 * Task 1 (master)
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

uint8_t even_nums[6] = {0, 2, 4, 6, 8, 10};
uint8_t odd_nums[6]  = {1, 3, 5, 7, 9, 11};
uint8_t some_nums[6] = {0, 1, 2, 3, 4,  5};
const char *unfunny_message = "joe mama!\?";


void setup()
{
	Serial.begin(9600);
	Wire.begin();
}

void loop()
{
}
