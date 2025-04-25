#include <stdlib.h>
#include "list.h"


struct list_node* createlist() {
	struct list_node* new_node = malloc(sizeof(struct list_node));
	new_node->data = NULL;
	new_node->next = NULL;
	return new_node;
}

void lpush(struct list_node* first, void* data) {
	struct list_node* new_node = malloc(sizeof(struct list_node));
	new_node->data = data;
	new_node->next = first->next;
	first->next = new_node;
}

int lpop(struct list_node* first, int index, void (*free_data)(void*)) {
	struct list_node* prev = first;
	struct list_node* curr = first->next;
	for (int i = 0; i < index; i++) {
		prev = curr;
		curr = curr->next;
		if (curr == NULL)
			return -1;
	}
	if (curr->data) {
		free_data(curr->data);
	}
	prev->next = curr->next;
	free(curr);

	return 0;
}

int linsert(struct list_node* first, void* data, int index) {
	struct list_node* curr = first;
	for (int i = 0; i < index; i++) {
		curr = curr->next;
		if (curr == NULL)
			return -1;
	}
	struct list_node* new_node = malloc(sizeof(struct list_node));
	new_node->data = data;
	new_node->next = curr->next;
	curr->next = new_node;

	return 0;
}

void* lget(struct list_node* first, int index) {
	struct list_node* curr = first;
	for (int i = -1; i < index; i++) {
		curr = curr->next;
		if (curr == NULL)
			return NULL;
	}
	return curr->data;
}

int lsize(struct list_node* first) {
	struct list_node* curr = first->next;
	int i = 0;
	while (curr) {
		curr = curr->next;
		i++;
	}
	return i;
}

void lfree(struct list_node* first, void (*free_data)(void*)) {
	struct list_node* curr = first;
	while (curr) {
		struct list_node* next = curr->next;
		if (curr->data) {
			free_data(curr->data);
		}
		free(curr);
		curr = next;
	}
}
