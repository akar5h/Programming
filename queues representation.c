#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Queue{
	unsigned long int head,tail,size,CurrSize;
	int *Arr;

};

struct Queue* addQ(unsigned long int size){

	struct Queue *Q= (struct Queue*)malloc(sizeof(struct Queue));
	Q->size = size;
	Q->CurrSize=0;
	Q->head=0;
	Q->tail= size-1;
	Q->Arr = (int*)malloc((Q->size) *sizeof(unsigned long int));
	return Q;
}

bool isEmpty( struct Queue *Q){
	if (Q->CurrSize==0)
		return true;
	else
		return false;
}
bool isFull( struct Queue *Q){
	if (Q->CurrSize==Q->size)
		return true;
	else
		return false;
}


void Enqueue(struct Queue *Q,unsigned long int data){
	
	if(isFull(Q))
		return;
	Q->tail=(Q->tail+1)%Q->size;
	Q->Arr[Q->tail]= data;
	
	Q->CurrSize=Q->CurrSize+1;
	return; 
}

unsigned long int Dequeue(struct Queue *Q){
	if(isEmpty(Q))
		return -1;

	unsigned long int data= Q->Arr[Q->head];
	Q->head=(Q->head+1)%Q->size;
	Q->CurrSize=Q->CurrSize;

	return data;

}

void MainUtil(){
	int q,OpCode,i;
	unsigned long int temp1,temp2;
	scanf("%d",&q);
	struct Queue *Q= addQ(q);

		for(i=0;i<q;i++){
			scanf("%d",&OpCode);

			switch(OpCode){
				case 1: scanf("%lu", &temp1);
						Enqueue(Q,temp1);
						break;
				case 2: temp2= Dequeue(Q);
						printf("%lu", temp2);
						break;
				case 3: if(isEmpty(Q))
						printf("true");
			}
		}
		return;
}
int main(){
	int t,i ;
	scanf("%d",&t);
	for(i=0;i<t;i++)
		MainUtil();
	return 0;
}