#ifndef LIST_H
#define LIST_H
struct list_element {
	struct list_element *next;
	struct list_element *prev;
	int data;
};

typedef struct list_element list_element;

void list_add(list_element *head_element, list_element *add_element);

void list_remove(list_element *head_element, list_element *remove_element);

#endif 
