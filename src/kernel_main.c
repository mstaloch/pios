#include <stdint.h>
#include "rprintf.h"
#include "serial.h"
#include "page.h"
#include "list.h"

extern long __bss_start;
extern long __bss_end;

extern struct ppage* free_list;//for HW 7

void clear_bss(){
	int x=0;
	while(&__bss_start +x != &__bss_end){
		(&__bss_start)[x]=0;
		x++;
	}
}

void kernel_main() {

	init_pfa_list();

	struct ppage* test = free_list->next;
	esp_printf(putc, "Physical addr: %x \n", test->physical_addr);
	test = allocate_physical_pages(2);
	esp_printf(putc, "Physical addr (test) after npages: %x \n", test);
	esp_printf(putc, "Physical addr (->physical_addr) after npages: %x \n", test->physical_addr);
	free_physical_pages(test);
	test = free_list->next;
	esp_printf(putc, "Post free addr: %x \n", test->physical_addr);	
	while(1){
	    }
}
