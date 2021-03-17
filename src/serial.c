#include "serial.h"
#include <stdint.h>
#define MUIO 0x3F215040;
void putc(int data){
	uint32_t *muio = (uint32_t *)MUIO;
	*muio = data;
}
