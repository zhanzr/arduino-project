BD99954_CTRL:
	Arduino Uno Control the Rohm BD99954 chip.

LCD1602_t1:
	LCD1602 Module 4bit mode driver.

LCD1602_I2C:
	LCD1602 with PCF8574AT IO Expander driver.

Board		I2C / TWI pins
Uno, Ethernet	A4 (SDA), A5 (SCL)
Mega2560	20 (SDA), 21 (SCL)
Leonardo	2 (SDA), 3 (SCL)
Due		20 (SDA), 21 (SCL), SDA1, SCL1

ENC28J60:
	Simple Webserver.
|	ENC28J60	|	Arduino Uno	|	Notes					|
| --------------------- |:---------------------:| ---------------------------------------------:|
| VCC			| 3.3V			|						|
| GND     		| GND			|						|
| SCK			| Pin 13		|						|
|MISO			| Pin 12		|						|
|MOSI			| Pin 11	|	|						|
|CS			| Pin 10		|Selectable with the ether.begin() function	|
