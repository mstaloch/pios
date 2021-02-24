#include <stdio.h>

extern long __bss_start;
extern long __bss_end;

void clear_bss(){
	int x=0;
	while(&__bss_start +x != &__bss_end){
		(&__bss_start)[x]=0;
		x++;
	}
}

unsigned long get_timer_count(){
	unsigned long *timer_count_register =  0xfe003004;
	return *timer_count_register;
}

void kernel_main() {
    while(1){
	led_init();
    }
}
