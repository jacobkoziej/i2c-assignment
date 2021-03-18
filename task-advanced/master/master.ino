/*
 * Task Advanced (master)
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

#define TEMPERATURE_LIMIT_HIGH_F 100.0
#define TEMPERATURE_LIMIT_LOW_F  32.0


void setup()
{
	Wire.begin();
}

void loop()
{
	float temp_reading;
	request_data(
		&temp_reading,
		sizeof(temp_reading),
		sizeof(temp_reading),
		I2C_SLAVE_1
		);

	uint8_t motor_speed = map(
			constrain(temp_reading,
				TEMPERATURE_LIMIT_LOW_F,
				TEMPERATURE_LIMIT_HIGH_F),
			TEMPERATURE_LIMIT_LOW_F,
			TEMPERATURE_LIMIT_HIGH_F,
			0x00,
			0xFF
			);
	send_data(&motor_speed, sizeof(motor_speed), I2C_SLAVE_2);

	uint8_t color[3];
	if (temp_reading < 65) {
		// white
		memset(color, 0xFF, sizeof(color));
	} else if (temp_reading < 85) {
		// green
		memset(color, 0, sizeof(color));
		color[2] = 0xFF;
	} else {
		// red
		memset(color, 0, sizeof(color));
		color[0] = 0xFF;
	}
	send_data(color, sizeof(color), I2C_SLAVE_3);
}
