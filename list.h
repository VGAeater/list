#ifndef LIST_H_
#define LIST_H_

struct list_node {
	void* data;
	struct list_node* next;
};

struct list_node* createlist();

void lpush(struct list_node* first, void* data);

int lpop(struct list_node* first, int index, void (*free_data)(void*));

int linsert(struct list_node* first, void* data, int index);

void* lget(struct list_node* first, int index);

int lsize(struct list_node* first);

void lfree(struct list_node* first, void (*free_data)(void*));

#endif
