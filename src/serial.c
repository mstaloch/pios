#include "serial.h"
void putc(int data){
	int *muio = (int *)0x3F215040;
	*muio = data;
}
