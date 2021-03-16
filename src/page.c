#include "list.h"
#include "page.h"

#define NULL (void*)0
#define NPAGES 128

struct ppage physical_page_array[NPAGES];
struct ppage* free_list = NULL;

void init_pfa_list(void){

}

struct ppage *allocate_physical_pages(unsigned int npages){


}

void free_physical_pages(struct ppage *ppage_list){

}
