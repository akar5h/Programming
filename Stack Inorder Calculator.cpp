#include<iostream>
#include <limits.h>
#include <ctype.h>

using namespace std;

struct Node{
	int data;
	struct Node *next;
};

class Stack{
	struct Node *top;
	public:
		Stack(){  //constructor
			top=NULL;
		}
	void Push(int data);
	int Pop();
	int TopShow();
	bool IsEmpty();
};

void Stack::Push(int data){
	struct Node *temp;
	temp= new Node;
	temp->data= data;
	temp->next=NULL;
	if(top!=NULL)
		temp->next=top;
	top=temp;
}

int Stack::Pop(){
	int data;
	struct Node *temp;
	if(top==NULL)
		return INT_MIN;
	temp=top;
	top=top->next;
	data=temp->data;
	delete temp;
	return data;
}

int Stack::TopShow(){
	int data;
	struct Node *temp;
	if(top==NULL)
		return INT_MIN;
	
	data= top->data;
	return data;
}
bool Stack::IsEmpty(){
	if(top==NULL)
		return true;
	else
		return false;
}
int OperatorPrecedence(int op){
 int precedence = 0; 
 if( op == -5 || op == -3)
 	precedence = 1;
 else if(op == -6 || op == -1 )
 	precedence = 2;
 return precedence;
}

void mainUtil(){
	int i=0,len,temp,curr,prev,result,a,b,operation,n2,n1;
	Stack S1,S2; //S1 is for numbers , S2 is for operators 
	string s;
	std::getline(std::cin >> std::ws, s);
	cin>>n1;
	cin>>n2;
	
	len= s.length();
	for(i=0;i<len;i++){
		if(s[i]==' '){
			i++;
		}

		if(isdigit(s[i])){

			temp=s[i]-'0';
			
			while(isdigit(s[i+1])){
				temp=10*temp + (s[i+1]-'0');
				i++;
			}

			S1.Push(temp);
		}
		
		else{

			curr = s[i]-'0';
			prev=S2.TopShow();
			if(s[i] == 'x' || s[i] == 'y'){
				if(s[i-1]=='y' || s[i-1]=='x'){						
							temp=S1.Pop();
							temp=temp*n1;
							S1.Push(temp);
							}

						else if(s[i-1]==' ')	
							S1.Push(n1);
				
									
						else if(isdigit(s[i-1])) {
							temp=S1.Pop();
							temp=n1*temp; 	
							S1.Push(temp);		
						}
			}
			while(OperatorPrecedence(curr)<=OperatorPrecedence(prev)){
				operation=S2.TopShow();
			switch (operation){
		        case -5:  a=S1.Pop();
	        				b=S1.Pop();
				        	S2.Pop();
		        			S1.Push(b + a);

		        case -3:  a=S1.Pop();
	        				b=S1.Pop();
				        	S2.Pop();
		        			S1.Push(b - a);

		        case -6:  a=S1.Pop();
	        				b=S1.Pop();
				        	S2.Pop();
		        			S1.Push(b * a);

		        case -1:  a=S1.Pop();
	        				b=S1.Pop();
				        	S2.Pop();
		        			S1.Push(b / a);
		        		     
			}
				
			}

			S2.Push(curr);
		}

	}

	while( S1.IsEmpty() != true && S2.IsEmpty() != true){
				a=S1.Pop();
	        	b=S1.Pop();
	        	operation = S2.Pop();

			switch (operation){
		        case (-5):  S1.Push(b + a);
		        case (-3):  S1.Push(b - a);
		        case (-6):  S1.Push(b * a);
		        case (-1):  S1.Push(b / a);
		    
	}

	result=S1.Pop();
	cout<<result;
	return;
}
}

int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
		mainUtil();
	return 0;
}