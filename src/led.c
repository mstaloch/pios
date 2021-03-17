
#include <stdio.h>
#include "led.h"

unsigned int *gpset1 = (unsigned int *)0xFE200020;
unsigned int *gpsel4 = (unsigned int *)0xFE200010;
unsigned int *gpclr1 = (unsigned int *)0xFE20002C;



void led_init(){
	int mask = 0xffffff0f;
	*gpsel4 = *gpsel4 & mask;
	*gpsel4 = *gpsel4 | (1 << 6);
}

void led_on(){
	*gpset1 = (1 << 10);
}

void led_off(){
	*gpclr1 = (1 << 10);
}

void delay(){
	for(int i=0; i< 100000; i++){
		asm("NOP");
	}
}
