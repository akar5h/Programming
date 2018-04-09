#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <iostream>


struct Stack{
	int data;
	struct Stack* next;
};

struct Stack *newNode(int data){
	struct Stack *stackNode = (struct Stack*)malloc(sizeof(struct Stack));
	stackNode->data=data;
	stackNode->next=NULL;
	return stackNode;
}

int IsEmpty(struct Stack *head){
	if(head==NULL)
		return 1;
	else 
		return 0;
}

void push(struct Stack *head,int data){
	struct Stack *stackNode = newNode(data);
	stackNode->next = (head);
	head = stackNode;
}

int pop(struct Stack *head){
	int data;
	if(IsEmpty(head))
		return INT_MIN;
	struct Stack *temp= head;
	head= (head)->next;
	data= temp->data;
	free(temp);

	return data;
}

int top(struct Stack *head){
	if(IsEmpty(head))
		return INT_MIN;
	return head->data;
}

void mainUtil(){
	struct Stack *S1 =NULL;
	char  input[1000];
	scanf("%[^\n]s",input );
	printf("%s\n",input );
	return;
}
int main(){
	int t,i;
	scanf("%d",&t);
	for(i=0;i<t;i++)
		mainUtil();

}