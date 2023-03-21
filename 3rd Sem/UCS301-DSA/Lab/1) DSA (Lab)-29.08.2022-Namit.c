#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *link;	
};


struct node *delFirst(struct node *head){
	struct node *ptr = head;
	head = head->link;
	free(ptr);
	ptr = NULL;
	return head;
}

struct node *delLast(struct node *head){
	struct node *ptr = head,ptr1;
	while(ptr->link != NULL){
		ptr = ptr->link;
	}
	free(ptr);
	ptr = NULL;
	return head;
}

void print(struct node *head){
	struct node *ptr = head;
	if(ptr == NULL){
		printf("LINKED LIST IS EMPTY!!");
	}
	while(ptr != NULL){
		printf("%d ",ptr->data);
		ptr = ptr->link;
	}
}

int main(){
	struct node *head = malloc(sizeof(struct node));
	head->data = 5;
	head->link = NULL;
	
	struct node *current = malloc(sizeof(struct node));
	current->data = 10;
	current->link = NULL;
	head->link = current;
	
	current = malloc(sizeof(struct node));
	current->data = 15;
	current->link = NULL;
	head->link->link = current;
	
//	head = delFirst(head);
	head = delLast(head);
	print(head);
return 0;
}
