# wendor-task

Link for the Motor : https://zbotic.in/product/25ga-370-24v-26rpm-dc-reducer-gear-motor-with-encoder/ This motor is a great choice for projects that require reliable and precise movement, making it suitable for various automation and robotic applications. Operated at 24V DC.

Microcontroller :STM32G030C8T6 After extensive research, I chose the STM32G030C8T6 microcontroller for this project because it offers an ideal balance of economy and functionality. It provides all the necessary features, such as a 64 MHz Cortex-M0+ core, 64 KB Flash, 8 KB RAM, and multiple communication interfaces, making it a reliable and cost-effective solution.

Motor Driver : DRV8870DDA (6 to 45V upto 3.6A) I selected the DRV8870DDA motor driver for this project because it offers an excellent balance of cost and functionality.Integrated Protection Features – Undervoltage Lockout (UVLO) – Overcurrent Protection (OCP) – Thermal Shutdown (TSD) – Automatic Fault Recovery.

24V to 3V3 BUCK Converter TPMP2359

IR sensor to detect product status.



Code Part Explanation:

Motor Control:

The motor is connected to pin PD0 and PD1.
Functions motor_start() and motor_stop() control the motor.


Sensor Feedback:

A sensor is connected to pin PA3.
The sensor is set up to trigger an interrupt when an item is dispensed.
The ISR function handles the interrupt, stopping the motor and setting a flag.


UART Communication:

UART is initialized with a baud rate of 115200.

Main Control Flow:

The system waits for a 'D' command over UART to start dispensing.
When dispensing starts, the motor runs until the sensor detects an item.
After dispensing, it sends an 'S' confirmation over UART.
