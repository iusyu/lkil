#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>


typedef struct _node {
	struct _node *next;
	int data;
}node;


int init_list(node** head)
{
	if( ((*head) = calloc(1, sizeof(node)))==NULL )
	{
		perror("malloc failure");
		exit(EXIT_FAILURE);
	}

	(*head)->next = NULL;
	(*head)->data = -1;
}

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
	tmp->data = data;
	(*head)->next = tmp;
	return 0;
}

int add_N_node(node** head,...)
{
	va_list vl;
	va_start(vl, head);
	int i = 0;
	for( ; i != -1 ; i = va_arg(vl, int)){
		add_node(head, i);
	}
	va_end(vl);
}



void test_VARIABLE_PARAMETER(){
	node* head = NULL;
	init_list(&head);
	add_N_node(&head, 1,3,4,5,6,7,7,-1);
	printf("%d ", head->data);
	printf("%d ", head->next->data);
	printf("%d ", head->next->next->data);
	printf("%d ", head->next->next->next->data);
	printf("%d ", head->next->next->next->next->data);
}


int main(int argc, char* argv[] )
{
	test_VARIABLE_PARAMETER();
}

