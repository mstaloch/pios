#include <stdio.h>
#include "list.h"

void list_add(list_element *head_element, list_element *add_element){
	list_element *current = head_element;
	while (current->next != NULL){
		current = current->next;
	}

	current->next = add_element;
	add_element->prev = current;
	}
void list_remove(list_element *head_element, list_element *remove_element){
	list_element *current = head_element;
	while(current != remove_element){
		current = current->next;
	}

	while(current->next != NULL){
		current = current->next;
		current->next->prev = current->prev;
	}
}
