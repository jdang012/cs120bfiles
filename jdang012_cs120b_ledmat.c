/*jdang012_customlab_LCD_Part.c
 *Name:Justin Dang
 *Email:jdang012@ucr.edu
 *Lab Section: 024
 *Assignment: Custom Lab Project
 *Exercise Description: recieve flag and set ledmat
 *
 *I acknowledge all content contained herein, excluding template or example code, is my own original work.
 */ 
#include <avr/io.h>
#include <avr/interrupt.h>
#include "timer.h"
#include "usart1.h"
#include <util/delay.h>

// ====================
// SM1: DEMO LED matrix
// ====================
enum led_draw{col1,col2,col3,col4,col5}led_draw;
void tickE(){
	switch (led_draw){//transitions from col to col
		case col1:
		led_draw =col2;
		break;
		case col2:
		led_draw= col3;
		break;
		case col3:
		led_draw= col4;
		break;
		case col4:
		led_draw =col5;
		break;
		case col5:
		led_draw= col1;
		break;
		default:
		break;
	}
	switch (led_draw){//actions
		case col1:
		transmit_data_col_sel(0xFE);
		transmit_data_col_data(0x3E);
		break;
		
		case col2:
		transmit_data_col_sel(0xFD);
		transmit_data_col_data(0x2A);
		break;
		case col3:
		transmit_data_col_sel(0xFB);
		transmit_data_col_data(0x2A);
		break;
		case col4:
		transmit_data_col_sel(0xF7);
		transmit_data_col_data(0x2A);
		break;
		case col5:
		transmit_data_col_sel(0xFF);
		transmit_data_col_data(0);
		break;
		default:
		break;
	}
}

void tickF(){
	switch (led_draw){//transitions from col to col
		case col1:
		led_draw =col2;
		break;
		case col2:
		led_draw= col3;
		break;
		case col3:
		led_draw= col4;
		break;
		case col4:
		led_draw =col5;
		break;
		case col5:
		led_draw= col1;
		break;
		default:
		break;
	}
	switch (led_draw){//actions
		case col1:
		transmit_data_col_sel(0xFE);
		transmit_data_col_data(0x3E);
		break;
		
		case col2:
		transmit_data_col_sel(0xFD);
		transmit_data_col_data(0x0A);
		break;
		case col3:
		transmit_data_col_sel(0xFB);
		transmit_data_col_data(0x0A);
		break;
		case col4:
		transmit_data_col_sel(0xF7);
		transmit_data_col_data(0x0A);
		break;
		case col5:
		transmit_data_col_sel(0xFF);
		transmit_data_col_data(0);
		break;
		default:
		break;
	}
}

void tickG(){
	switch (led_draw){//transitions from col to col
		case col1:
		led_draw =col2;
		break;
		case col2:
		led_draw= col3;
		break;
		case col3:
		led_draw= col4;
		break;
		case col4:
		led_draw =col5;
		break;
		case col5:
		led_draw= col1;
		break;
		default:
		break;
	}
	switch (led_draw){//actions
		case col1:
		transmit_data_col_sel(0xFE);
		transmit_data_col_data(0x1C);
		break;
		
		case col2:
		transmit_data_col_sel(0xFD);
		transmit_data_col_data(0x22);
		break;
		case col3:
		transmit_data_col_sel(0xFB);
		transmit_data_col_data(0x2A);
		break;
		case col4:
		transmit_data_col_sel(0xF7);
		transmit_data_col_data(0x1A);
		break;
		case col5:
		transmit_data_col_sel(0xFF);
		transmit_data_col_data(0);
		break;
		default:
		break;
	}
}

void tickA(){
	switch (led_draw){//transitions from col to col
		case col1:
		led_draw =col2;
		break;
		case col2:
		led_draw= col3;
		break;
		case col3:
		led_draw= col4;
		break;
		case col4:
		led_draw =col5;
		break;
		case col5:
		led_draw= col1;
		break;
		default:
		break;
	}
	switch (led_draw){//actions
		case col1:
		transmit_data_col_sel(0xFE);
		transmit_data_col_data(0x3C);
		break;
		
		case col2:
		transmit_data_col_sel(0xFD);
		transmit_data_col_data(0x0A);
		break;
		case col3:
		transmit_data_col_sel(0xFB);
		transmit_data_col_data(0x0A);
		break;
		case col4:
		transmit_data_col_sel(0xF7);
		transmit_data_col_data(0x3C);
		break;
		case col5:
		transmit_data_col_sel(0xFF);
		transmit_data_col_data(0);
		break;
		default:
		break;
	}
}

void tickB(){
	switch (led_draw){//transitions from col to col
		case col1:
		led_draw =col2;
		break;
		case col2:
		led_draw= col3;
		break;
		case col3:
		led_draw= col4;
		break;
		case col4:
		led_draw =col5;
		break;
		case col5:
		led_draw= col1;
		break;
		default:
		break;
	}
	switch (led_draw){//actions
		case col1:
		transmit_data_col_sel(0xFE);
		transmit_data_col_data(0x3E);
		break;
		
		case col2:
		transmit_data_col_sel(0xFD);
		transmit_data_col_data(0x2A);
		break;
		case col3:
		transmit_data_col_sel(0xFB);
		transmit_data_col_data(0x2A);
		break;
		case col4:
		transmit_data_col_sel(0xF7);
		transmit_data_col_data(0x36);
		break;
		case col5:
		transmit_data_col_sel(0xFF);
		transmit_data_col_data(0);
		break;
		default:
		break;
	}
}
void tickC(){
	switch (led_draw){//transitions from col to col
		case col1:
		led_draw =col2;
		break;
		case col2:
		led_draw= col3;
		break;
		case col3:
		led_draw= col4;
		break;
		case col4:
		led_draw =col5;
		break;
		case col5:
		led_draw= col1;
		break;
		default:
		break;
	}
	switch (led_draw){//actions
		case col1:
		transmit_data_col_sel(0xFE);
		transmit_data_col_data(0x1C);
		break;
		
		case col2:
		transmit_data_col_sel(0xFD);
		transmit_data_col_data(0x22);
		break;
		case col3:
		transmit_data_col_sel(0xFB);
		transmit_data_col_data(0x22);
		break;
		case col4:
		transmit_data_col_sel(0xF7);
		transmit_data_col_data(0x14);
		break;
		case col5:
		transmit_data_col_sel(0xFF);
		transmit_data_col_data(0);
		break;
		default:
		break;
	}
}
void tickD(){
	switch (led_draw){//transitions from col to col
		case col1:
		led_draw =col2;
		break;
		case col2:
		led_draw= col3;
		break;
		case col3:
		led_draw= col4;
		break;
		case col4:
		led_draw =col5;
		break;
		case col5:
		led_draw= col1;
		break;
		default:
		break;
	}
	switch (led_draw){//actions
		case col1:
		transmit_data_col_sel(0xFE);
		transmit_data_col_data(0x3E);
		break;
		
		case col2:
		transmit_data_col_sel(0xFD);
		transmit_data_col_data(0x22);
		break;
		case col3:
		transmit_data_col_sel(0xFB);
		transmit_data_col_data(0x22);
		break;
		case col4:
		transmit_data_col_sel(0xF7);
		transmit_data_col_data(0x1C);
		break;
		case col5:
		transmit_data_col_sel(0xFF);
		transmit_data_col_data(0);
		break;
		default:
		break;
	}
}

void transmit_data_col_data(unsigned char data) {
	int i;
	for (i = 0; i < 8 ; ++i) {
		// Sets SRCLR to 1 allowing data to be set
		// Also clears SRCLK in preparation of sending data
		PORTC = 0x08;
		// set SER = next bit of data to be sent.
		PORTC |= ((data >> i) & 0x01);
		// set SRCLK = 1. Rising edge shifts next bit of data into the shift register
		PORTC |= 0x02;
	}
	// set RCLK = 1. Rising edge copies data from “Shift” register to “Storage” register
	PORTC |= 0x04;
	// clears all lines in preparation of a new transmission
	PORTC = 0x00;
}

void transmit_data_col_sel(unsigned char data) {
	int i;
	for (i = 0; i < 8 ; ++i) {
		// Sets SRCLR to 1 allowing data to be set
		// Also clears SRCLK in preparation of sending data
		PORTA = 0x08;
		// set SER = next bit of data to be sent.
		PORTA |= ((data >> i) & 0x01);
		// set SRCLK = 1. Rising edge shifts next bit of data into the shift register
		PORTA |= 0x02;
	}
	// set RCLK = 1. Rising edge copies data from “Shift” register to “Storage” register
	PORTA |= 0x04;
	// clears all lines in preparation of a new transmission
	PORTA = 0x00;
}




int main(void)
{
    /* Replace with your application code */
	unsigned char col_sel;
	unsigned char col_data;
	unsigned char a;
		DDRA = 0xFF; PORTA = 0x00;
		DDRB = 0xFF; PORTB = 0x00;
		DDRC = 0xFF; PORTC= 0x00;
	TimerOn();
	TimerSet(1);
	initUSART(0);
	led_draw = col1;
    while (1) 
    {
		a = USART_Receive(0);
		if (a == 0x00 ||a==0x07)
		{
			tickE();
		}
		else if (a== 0x01|| a== 0x08)
		{
			tickF();
		}
		else if (a==0x02){
			tickG();
		}
		else if(a==0x03){
			tickA();
		}
		else if (a==0x04){
			tickB();
		}
		else if (a==0x05)
		{
			tickC();
		}
		else if (a==0x06){
			tickD();
		}
		
		while (!TimerFlag);
		TimerFlag = 0;

		
    
	}
}

