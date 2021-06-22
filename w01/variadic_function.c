#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>


typedef struct _node {
	struct _node *next;
	int data;
}node;


int add_node(node** head, int data)
{
	if( !(head != NULL && *head != NULL) ){
		perror("pointer is NULL or point to NULL");
		exit(EXIT_FAILURE);
	}

	node* tmp = NULL;
	if( (tmp = malloc(sizeof(struct _node))) == NULL) {
		perror("Malloc failure");
	}

	tmp->next = (*head)->next;
	(*head)->next = tmp;
	return 0;
}

int add_N_node(node** head,...)
{
	va_list ap;
	for( 
}


