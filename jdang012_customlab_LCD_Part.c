/*jdang012_customlab_LCD_Part.c
 *Name:Justin Dang
 *Email:jdang012@ucr.edu
 *Lab Section: 024
 *Assignment: Custom Lab Project
 *Exercise Description: Display lcd and have user move throughout scale. Also sends flag using usart to other atmega
 *
 *I acknowledge all content contained herein, excluding template or example code, is my own original work.
 */ 
#include <avr/io.h>
#include <util/delay.h>
//#include "usart.h"
#include <stdio.h>
#include <math.h>
#include "nokia5110.h"
#include "timer.h"
#include "usart1.h"
#include <util/delay.h>

enum lcd_draw{drawlcd, draw_E, draw_F, draw_G , draw_A, draw_B , draw_C, draw_D , draw_E2, draw_F2}lcd_draw;
unsigned char x= 0;
unsigned char y= 5;
unsigned char A0_new;
unsigned char A0_old;
unsigned char A1_new;
unsigned char A1_old;
//unsigned char A2_old;
//unsigned char A2_new;


void createstaff(){
	nokia_lcd_set_cursor(0,80);

	for (y = 5; y< 42; y+=8)
	{
		for (x=0; x< 84; x++)
		{
			nokia_lcd_set_pixel(x, y, 1);
		}
	}
	return;
}

void tickmove()
{
	A0_new = ~PINA & 0x01;
	A1_new = ~PINA & 0x02;

	A1_new = A1_new >>1;
	switch(lcd_draw)
	{
		case drawlcd:
		lcd_draw = draw_E;
		break;
		
		case draw_E:
		if ((A0_new|A0_old)&(A1_new|A1_old))//wait
		{
			lcd_draw = draw_E;
		}
		else if (((A0_new & !A0_old) & (!A1_new & !A1_old)))//goup
		{
			lcd_draw = draw_F;
		}
		else//wait
		{
			lcd_draw = draw_E;
		}
		break;
		
		case draw_F:
		if ((A0_new|A0_old)&(A1_new|A1_old))//wait
		{
			lcd_draw = draw_E;
		}
		else if (((A0_new & !A0_old) & (!A1_new & !A1_old)))//goup
		{
			lcd_draw = draw_G;
		}
		else if (((A1_new & !A1_old) & (!A0_new & !A0_old)))//s2
		{
			lcd_draw = draw_E;
		}
		else//wait
		{
			lcd_draw = draw_F;
		}
		
		break;
		
		case draw_G:
		if ((A0_new|A0_old)&(A1_new|A1_old))//wait
		{
			lcd_draw = draw_E;
		}
		else if (((A0_new & !A0_old) & (!A1_new & !A1_old)))//goup
		{
			lcd_draw = draw_A;
		}
		else if (((A1_new & !A1_old) & (!A0_new & !A0_old)))//s2
		{
			lcd_draw = draw_F;
		}
		else//wait
		{
			lcd_draw = draw_G;
		}
		
		break;
		
		case draw_A:
		if ((A0_new|A0_old)&(A1_new|A1_old))//wait
		{
			lcd_draw = draw_E;
		}
		else if (((A0_new & !A0_old) & (!A1_new & !A1_old)))//goup
		{
			lcd_draw = draw_B;
		}
		else if (((A1_new & !A1_old) & (!A0_new & !A0_old)))//s2
		{
			lcd_draw = draw_G;
		}
		else//wait
		{
			lcd_draw = draw_A;
		}
		
		break;
		
		case draw_B:
		if ((A0_new|A0_old)&(A1_new|A1_old))//wait
		{
			lcd_draw = draw_E;
		}
		else if (((A0_new & !A0_old) & (!A1_new & !A1_old)))//goup
		{
			lcd_draw = draw_C;
		}
		else if (((A1_new & !A1_old) & (!A0_new & !A0_old)))//s2
		{
			lcd_draw = draw_A;
		}
		else//wait
		{
			lcd_draw = draw_B;
		}
		
		break;
		
		case draw_C:
		if ((A0_new|A0_old)&(A1_new|A1_old))//wait
		{
			lcd_draw = draw_E;
		}
		else if (((A0_new & !A0_old) & (!A1_new & !A1_old)))//goup
		{
			lcd_draw = draw_D;
		}
		else if (((A1_new & !A1_old) & (!A0_new & !A0_old)))//s2
		{
			lcd_draw = draw_B;
		}
		else//wait
		{
			lcd_draw = draw_C;
		}
		
		break;
		
		case draw_D:
		if ((A0_new|A0_old)&(A1_new|A1_old))//wait
		{
			lcd_draw = draw_E;
		}
		else if (((A0_new & !A0_old) & (!A1_new & !A1_old)))//goup
		{
			lcd_draw = draw_E2;
		}
		else if (((A1_new & !A1_old) & (!A0_new & !A0_old)))//s2
		{
			lcd_draw = draw_C;
		}
		else//wait
		{
			lcd_draw = draw_D;
		}
		
		break;
		case draw_E2:
		if ((A0_new|A0_old)&(A1_new|A1_old))//wait
		{
			lcd_draw = draw_E;
		}
		else if (((A0_new & !A0_old) & (!A1_new & !A1_old)))//goup
		{
			lcd_draw = draw_F2;
		}
		else if (((A1_new & !A1_old) & (!A0_new & !A0_old)))//s2
		{
			lcd_draw = draw_D;
		}
		else//wait
		{
			lcd_draw = draw_E2;
		}
		
		break;
		
		case draw_F2:
		if ((A0_new|A0_old)&(A1_new|A1_old))//wait
		{
			lcd_draw = draw_E;
		}
		else if (((A0_new & !A0_old) & (!A1_new & !A1_old)))//goup
		{
			lcd_draw = draw_F2;
		}
		else if (((A1_new & !A1_old) & (!A0_new & !A0_old)))//s2
		{
			lcd_draw = draw_E2;
		}
		else//wait
		{
			lcd_draw = draw_F2;
		}
		
		break;
		default:
		break;
	}
	////////////////////
	////////////////////
	//actionss//////////
	////////////////
	//////////////
	
	switch(lcd_draw)//action
	{
		static char j =0;
		static char i = 0;
		case drawlcd:
		A0_old = A0_new;
		A1_old = A1_new;
		//A2_old = A2_new;
		break;
		
		case draw_E:
		nokia_lcd_clear();
		createstaff();
		for(j = 2; j < 9; j++){
			for (i = 38; i < 46; i++)
			{
				nokia_lcd_set_pixel(i, j, 1);
			}
		}
		nokia_lcd_render();
		A0_old = A0_new;
		A1_old = A1_new;
		//A2_old = A2_new;
		USART_Send(0x00,0);//send0
		break;
		
		case draw_F:
		nokia_lcd_clear();
		createstaff();
		for(j = 5; j < 13; j++){
			for (i = 38; i < 46; i++)
			{
				nokia_lcd_set_pixel(i, j, 1);
			}
		}
		nokia_lcd_render();
		A0_old = A0_new;
		A1_old = A1_new;
		//A2_old = A2_new;
		USART_Send(0x01,0);//send1
		break;
		
		case draw_G:
		nokia_lcd_clear();
		createstaff();
		for(j = 10; j < 17; j++){
			for (i = 38; i < 46; i++)
			{
				nokia_lcd_set_pixel(i, j, 1);
			}
		}
		nokia_lcd_render();
		A0_old = A0_new;
		A1_old = A1_new;
		//A2_old = A2_new;
		USART_Send(0x02,0);//send2
		break;
		
		case draw_A:
		nokia_lcd_clear();
		createstaff();
		for(j = 14; j < 21; j++){
			for (i = 38; i < 46; i++)
			{
				nokia_lcd_set_pixel(i, j, 1);
			}
		}
		nokia_lcd_render();
		A0_old = A0_new;
		A1_old = A1_new;
		//A2_old = A2_new;
		USART_Send(0x03,0);
		break;
		
		case draw_B:
		nokia_lcd_clear();
		createstaff();
		for(j = 18; j < 25; j++){
			for (i = 38; i < 46; i++)
			{
				nokia_lcd_set_pixel(i, j, 1);
			}
		}
		nokia_lcd_render();
		A0_old = A0_new;
		A1_old = A1_new;
		//A2_old = A2_new;
		USART_Send(0x04,0);
		break;
		
		case draw_C:
		nokia_lcd_clear();
		createstaff();
		for(j = 22; j < 29; j++){
			for (i = 38; i < 46; i++)
			{
				nokia_lcd_set_pixel(i, j, 1);
			}
		}
		nokia_lcd_render();
		A0_old = A0_new;
		A1_old = A1_new;
		//A2_old = A2_new;
		USART_Send(0x05,0);
		break;
		
		case draw_D:
		nokia_lcd_clear();
		createstaff();
		for(j = 26; j < 33; j++){
			for (i = 38; i < 46; i++)
			{
				nokia_lcd_set_pixel(i, j, 1);
			}
		}
		nokia_lcd_render();
		A0_old = A0_new;
		A1_old = A1_new;
		//A2_old = A2_new;
		USART_Send(0x06,0);
		break;
		
		case draw_E2:
		nokia_lcd_clear();
		createstaff();
		for(j = 30; j < 37; j++){
			for (i = 38; i < 46; i++)
			{
				nokia_lcd_set_pixel(i, j, 1);
			}
		}
		nokia_lcd_render();
		A0_old = A0_new;
		A1_old = A1_new;
		//A2_old = A2_new;
		USART_Send(0x07,0);
		break;
		
		case draw_F2:
		nokia_lcd_clear();
		createstaff();
		for(j = 34; j < 41; j++){
			for (i = 38; i < 46; i++)
			{
				nokia_lcd_set_pixel(i, j, 1);
			}
		}
		nokia_lcd_render();
		A0_old = A0_new;
		A1_old = A1_new;
		//A2_old = A2_new;
		
		USART_Send(0x08,0);
		break;
		
		default:
		break;
	}
}


int main(void)
{
	DDRA = 0x00; PORTA = 0xFF;
	
	nokia_lcd_init();
	nokia_lcd_clear();
	lcd_draw =drawlcd;
	initUSART(0);
	
	lcd_draw= drawlcd;
	TimerSet(1);
	TimerOn();
	while (1)
	{

		tickmove();
		while (!TimerFlag);
		TimerFlag = 0;
		
	}
}
