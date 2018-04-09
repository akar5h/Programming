#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


struct Node {
	int data;
	struct Node* next;
};

struct Node *InsertNoode(int data){
	struct Node *new_node= (struct Node*)malloc(sizeof(struct Node));
	new_node->data = data;
	new_node->next = NULL;
	return new_node; 
} 

void push(struct Node** head,int data){
	struct Node *new_node = InsertNoode(data);
	new_node->next = (*head);
	*head= new_node;	
}

void print(struct Node* node){
	if(node ==NULL)
		return;

	print(node->next);
	
	printf("%d",node->data);
	
	return;
}

struct Node* Addition(struct Node* first, struct Node* second){
	struct Node *result= NULL;
	int carry=0,sum,l,m;
	struct Node *temp1=NULL, *tempHead=NULL;

	while( first!=NULL || second != NULL){
	
		if(first != NULL)
			l=first->data;
		else
			l=0;

		if(second !=NULL)
			m=second->data;
		else
			m=0;
		
		sum = carry + l  + m ;
		carry= sum/10;
		sum=sum%10;
		
		
		temp1= InsertNoode(sum);

		if(result ==NULL)
			result=temp1;
		else
			tempHead->next= temp1;

		tempHead= temp1;

		if (first != NULL)
			first=first->next;

		if (second != NULL)
			second=second->next;
	}

	if(carry>0)
		temp1->next= InsertNoode(carry);
	
	return result;

}


struct Node *Subtract(struct Node *first, struct Node *second){
	struct Node *result= NULL;
	int carry=0,sub,l,m,n;
	struct Node *temp1=NULL, *tempHead=NULL;
	bool borrow= false;

	while( first!=NULL || second != NULL){
	
		if(first != NULL)
			l=first->data;
		else
			l=0;

		if(second !=NULL)
			m=second->data;
		else
			m=0;

		if(borrow== true)
		l=l-1;

		if(m>l){
			borrow= true;
			l=l+10;
		}
		else{
			borrow=false;
		}

		sub= l-m;

		temp1= InsertNoode(sub);

		if(result ==NULL)
			result=temp1;
		else
			tempHead->next= temp1;

		tempHead= temp1;

		if (first != NULL)
			first=first->next;

		if (second != NULL)
			second=second->next;
	}

	return result;
	}


struct Node* Multiply(struct Node* first, struct Node* second){
	struct Node *result= NULL;
	int carry=0,product,l,m,pivot=0,i;
	struct Node *temp1=NULL, *tempHead=NULL,*tempResult= NULL,*temp ;
	temp=first;
	push(&result,0);

	while(second !=NULL){	
		
		first=temp;
		carry=0;
		tempResult=NULL;
		while( first!=NULL){
		
			if(first != NULL)
				l=first->data;
			else
				l=0;

			if(second !=NULL)
				m=second->data;
			else
				m=0;
			
			product = carry + l*m ;
			carry= product/10;
			product=product%10;

			temp1= InsertNoode(product);

			if(tempResult ==NULL)
				tempResult=temp1;
			else
				tempHead->next= temp1;

			tempHead= temp1;

			if (first != NULL)
				first=first->next;
			
			if(carry>0)
			temp1->next= InsertNoode(carry);

			}

		for(i=0;i<pivot;i++)
			push(&tempResult,0);
		
		result= Addition(result,tempResult);

		if(second !=NULL)			
		second=second->next;
		pivot++;
	}

	return result;

}

long long int Divide(struct Node* first, struct Node* second){
	long long int temp1,temp2;
	while(first!=NULL)
	return 0;
}

void mainUtil(){
	struct Node* result= NULL;
	struct Node* first= NULL;
	struct Node* second= NULL;

	int i,j,n1,n2;
	
	scanf("%d",&n1);
	scanf("%d", &n2);
	
	char p[n1], q[n2];

	scanf("%s", p);
	scanf("%s", q);
	
		for(i=0;i<n1;i++)
			push(&first, p[i] - '0');
		
		for(j=0;j<n2;j++)
			push(&second, q[j] - '0');
		

		result= Multiply(first, second);
		
		print(result);
		printf("\n");
		
		return;
}


int main(){
	int t,i;
	scanf("%d",&t);
	
	for(i=0;i<t;i++)
		mainUtil();

return 0;
}

