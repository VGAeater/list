#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

int main() {
	struct list_node* list = createlist();
	char* buffer = malloc(sizeof("hello"));
	strcpy(buffer, "hello");
	lpush(list, buffer);
	buffer = malloc(sizeof("goodbye"));
	strcpy(buffer, "goodbye");
	linsert(list, buffer, 1);
	buffer = NULL;
	char* ptr = lget(list, 0);
	printf("%s\n", ptr);
	ptr = lget(list, 1);
	printf("%s\n", ptr);
	int len = lsize(list);
	printf("Length: %d\n", len);
	lfree(list, free);
}
