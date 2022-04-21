/**
 * @file Digital_lock.h
 * @author Somayya N Hugar
 * @Design and Simulate Digital door lock System using atmega32
 *
 */
#include<avr/io.h>
#include<avr/eeprom.h>
#include<util/delay.h>
/**
*Defining the ports of the microcontroller to lcd pins and signals
**/

#define lcdport PORTA

#define signal PORTB

#define en PB2

#define rw PB1

#define rs PB0
char password[1];
char lock[0];
char key;
/**
*It checks whether the entered password is correct or not
**/
char keycheck();

char scankey();

void lcdcmd(unsigned char cmd);
/**
*calls the lcd command and prints the data given in the pre-defined code
**/
void lcdint();
