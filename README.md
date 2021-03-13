# i2c-assignment

> The objective of this activity is to learn the most used synchronous serial
> communication known as I2C bus.  Through this assignment I2C communication
> will be utilized to connect multiple Arduinos that are assigned to monitor
> and control subsystem applications.


## Materials

* 5 Arduinos
* 5 Breadboards
* 1 DC motor
* 1 RGB led
* 1 temperature sensor (Tmp36)
* 1 LCD display


## Theory

I2C is a short distance synchronous communication protocol that connects
multiple devices using only two wires.  The communication consists of two pins,
one for the data and one for the clock.

I2C utilizes master slave programming techniques to control the communication
system.  The master is the one that controls the communication speed, the
initiation, and transceiver communication.  Slaves are always called by the
master to receive data or to deliver data from/to master.  Most of today's
transducers and actuators use I2C to communicate with microcontrollers.


## Procedure

### Task 1 (Transmit)

Create an I2C network of 5 Arduinos:

* One of the five Arduinos will be the master
* The other four will be slaves
* Master will send the following data to slaves:
	* An even numbers buffer from 0 to 10 to slave 1
	* An odd numbers buffer from 1 to 11 to slave 2
	* A 10 characters string of your choice to slave 3
	* A buffer of 2^n where n is a sequence from 0 to 5 to slave 4

Print the received values to the monitor on the slave MCUs

### Task 2 (Transmit)

Create an I2C network of 5 Arduinos:

* One of the five Arduinos will be the master
* The other four will be slaves
* Master will request the following data to slaves:
	* An even numbers buffer from 0 to 10 to slave 1
	* An odd numbers buffer from 1 to 11 to slave 2
	* A 10 characters string of your choice to slave 3
	* A buffer of 2^n where n is a sequence from 0 to 5 to slave 4

Print the received values to the monitor on the slave MCUs

### Task 3 (Transceiver)

Create an I2C network of 3 Arduinos:

* One of the three Arduinos will be the master
* The other two will be slaves
* Master will send the following data to slaves:
	* An even numbers buffer from 0 to 10 from slave 1
	* An odd numbers buffer from 1 to 11 from slave 2

Print the received values to the monitor on the slave MCUs

* Master will request the following data from slaves:
	* Double the value of the received even numbers buffer from the master
	  for slave 1
	* Triple the value of the received odd  numbers buffer from the master
	  for slave 2

Print the requested values upon receiving from slaves.

### Advanced Task

Create an I2C network of 5 Arduinos:

* One of the five Arduinos will be the master
* The other four will be slaves
* Slave 1: Will send a temperature sensor value to master upon request.
* Slave 2: Will control the speed of the fan (DC motor).  The speed of the fan
  will be received from master.
* Slave 3: Will control the color of the RGB LED.  The RGB color value will be
  received from master.
* Slave 4: Will display the temperature sensor, the speed of the fan, and the
  color of the RGB LED using the LCD display.
* Master: Will control the communication, map the value of the temp sensor to
  motor speed from 0 to 255, assign the RGB color based on temperature value.
	* Color suggestions:
		* 32 > white < 65
		* 65 > green < 85
		* 85 > red < 110


---

Credits to Ali Harb for creating this assignment.
