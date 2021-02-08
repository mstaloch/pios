#include <stdio.h>
#include "list.h"

int main(){
	list_element a = (NULL,NULL, 5);
	list_element b = (NULL,NULL, 10);
	list_element c = (NULL, NULL, 15);
	list_element d = (NULL,NULL, 20);

	list_add(&a, &b);
	list_add(&a, &c);
	list_add(&a, &d);

	list_remove(&a, &b);

	list_remove(&a,&d);	
	list_add(%a,%b);


	return 0;
}
