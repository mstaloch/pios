#include "list.h"
#include "page.h"

#define NULL (void*)0
#define NPAGES 128
extern int __end;


struct ppage physical_page_array[NPAGES];
struct ppage* free_list = NULL;


void init_pfa_list(void){
	void* address_p = (((unsigned long)&__end) & ~(0x200000 -1)) + 0x200000;
	int i;
	for(i = 0; i < NPAGES; i++){
		listAdd(&free_list, &physical_page_array[i]);
		physical_page_array[i].physical_addr = address_p;
		address_p += 0x200000; 
	}
}

struct ppage *allocate_physical_pages(unsigned int npages){
	struct ppage *var  = free_list;
	struct ppage *allocated_list = NULL;
	int i;
	for(i = 0; i < npages; i++) {
		listRemove(var);
		listAdd(&allocated_list, var);
	}
	return allocated_list;

}

void free_physical_pages(struct ppage *ppage_list){
	struct ppage *var = ppage_list;
	while(ppage_list != NULL){
		listRemove(var);
		listAdd(&free_list, var);
	}
}
