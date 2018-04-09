#include<iostream>

using namespace std;

struct Node{
		string word;
		int ht,Lex;
		struct Node *left, *right;
	};
//adds a node to the tree
struct Node *addNode(string data)
	{	
		struct Node *temp =new Node;
		temp->word= data;
		temp->left= temp->right =NULL;
		temp->ht=1;
		temp->Lex=1;
		return temp;
	}
//returns the height of the given Node(subtree)
int Height(Node *T){
		int lh,rh;

		if(T==NULL)
			return 0;
		if(T->left==NULL)
			lh=0;
		else
			lh= T->left->ht;
		
		if(T->right==NULL)
		 rh=0;
		else
			rh= T->right->ht;

		lh++;
		rh++;
		if(lh>rh)
			return (lh);
		else
			return (rh);
}
//Returns balance factor of the node
int BalFac(Node *T){

	int lh,rh;		
		if(T==NULL)
			return 0;


		if(T->left==NULL)
			lh=0;

		else
			lh= T->left->ht;



		if(T->right==NULL)
			rh=0;

		else
			rh= T->right->ht;
		return (lh-rh);
	
	}
//returns the minimum value (lexiographically) node
Node *minValue(Node* node)
{
    Node* n = node;
    while(n->left!=NULL)
        n=n->left;
    return n;
}
//returns the maximum value (lexiographically) node

Node *maxValue(Node* node)
{
    Node* n = node;
    while(n->right!=NULL)
        n=n->right;
    return n;
}

Node *rotateLeft(Node* x){
		Node *y;
		y=x->right;
		x->right=y->left;
		y->left=x;
		
		x->ht= Height(x);
		y->ht= Height(y);
		
		return y;
	}


	Node *rotateRight(Node* x){
		Node *y;

		y=x->left;
		x->left=y->right;
		y->right=x;
		
		x->ht= Height(x);
		y->ht= Height(y);
		
		return y;
	}

	Node *LL_rotation(Node *T){
		T= rotateRight(T);
		return T;
	}
	Node *RR_rotation(Node *T){
		T= rotateLeft(T);
		return T;
	}
	Node *LR_rotation(Node *T){
		T->left = rotateLeft(T->left);
		T= rotateRight(T);
		return T;
	}
	Node *RL_rotation(Node *T){
		T->right = rotateRight(T->right);
		T= rotateLeft(T);
		return  T;
	}
//insertion/learn here
Node *insert(struct Node *T,string data){
		int temp1;
		if(T==NULL){
			return addNode(data);
		}

		if(data>T->word){
			Node *Rchild = insert(T->right,data);
			T->right = Rchild;
			
			temp1=BalFac(T);
			if(temp1==-2){//Rebalance
				if(data>T->right->word)//right skew
					T=RR_rotation(T);

				else
					T= RL_rotation(T);
			}
		}
		
		else if(data<T->word){
			Node *Lchild = insert(T->left,data);
			T->left = Lchild;
			temp1=BalFac(T);
			
			if(temp1==2)//Rebalance
				if(data<T->left->word)
					T=LL_rotation(T);
				else
					T= LR_rotation(T);

			
		}
		
		T->ht = Height(T);
		
		return T;
	}
//delete a node/entry
	Node *deletion(Node* T, string data){
		if(T==NULL)
			return T;

		if(data < T->word)
			T->left = deletion(T->left,data);

		else if(data > T->word){
			T->right = deletion(T->right,data);		
		}

		else{
			if(T->left ==NULL|| T->right ==NULL){
				Node *temp = T->left ? T->left : T->right;

				if(temp ==NULL){
					temp= T;
					T=NULL;
				}
				else
					*T=*temp;

				delete (temp);
			}
			else{
				Node *temp = minValue(T->right);
				T->word = temp ->word;
				T->right = deletion(T->right,temp->word);
			}
		}

		if(T==NULL)
			return T;

		T->ht = Height(T);
		int bal= BalFac(T);

		if(bal > 1 && BalFac(T->left)>=0)
			T= RR_rotation(T);

		else if(bal < -1 && BalFac(T->left)<0)
			T= LR_rotation(T);
		else if(bal < -1 && BalFac(T->right) <=0)
			T= RR_rotation(T);
		else if(bal>-1 && BalFac(T->right) > 0)
			T= RL_rotation(T);

		return T;
		
}
//returns the rank of searched input
int Rank(Node *T,string s){
	string temp = T->word;
			
	while (temp != s) {
			
		if(T==NULL)
			return 0;

		if (T->word > s )
			T = T->left;

		else if (T->word < s) 
			T = T->right;
		temp = T->word;
	}

	return (T->Lex);
	
}

/*
void printInorder(struct Node* x)
{
     if(x==NULL)
       return;
    printInorder(x->left);
  	cout<<"Word:\t"<< x->word<<"\n";

  	cout<<"Height:"<<x->ht<<"\n";  

  	cout<<"Lex:"<<x->Lex<<"\n";  
 	printInorder(x->right);
}
*/
Node *Successor(Node *T,Node *x){

	if(x->right!=NULL){
       return minValue(x->right);
 	}
    
        Node *y =  NULL;

        while(T != NULL)
        {
            if(x->word < T->word){
            	y = T;
            	T = T->left;
            }
            else if(x->word > T->word)
            	T= T->right;
            else
            	break;
        }
        
        return y;
 }

void LexUtil(Node *T,Node *succ,int i){
	string temp1 = T->word;
	string temp2 = succ->word;
	
	while (temp1 != temp2) {
			
		if(T==NULL)
			return;

		if (T->word > temp2 )
			T = T->left;

		else if (T->word < temp2) 
			T = T->right;

		temp1 = T->word;
	}

	T->Lex = i + 1 ;
	
	return;
}

void Lex(Node *T){
	Node *succ = new Node;
	succ = NULL;
	Node *temp1 = minValue(T);
	Node *temp2 =  maxValue(T);
	int i =1;
	string s1, s2;
	s1 = temp1->word;
	s2 = temp2->word;
	while(s1!=s2){
		succ =   Successor(T,temp1);
		temp1 = succ ; 
		LexUtil(T,temp1,i);
		i++;
		s1= temp1->word;
	}
	return;
}
int main(){
	int n,i,x;
	string temp1,temp2,temp3;

	Node *root= new Node;
	root=NULL;
	Node *temp = new Node;
	temp=NULL;
	cin>>n;
  for(int i=0;i<n;i++){
		cin>>temp1;
		
		if(temp1=="learn"){
		 	cin>>temp2; 
		  	root=insert(root,temp2);
		  	Lex(root);
		  
		}

		else if(temp1=="forget"){
		 	cin>>temp2; 
		 	x = Rank(root,temp2);
			
			cout<<x;

			root= deletion(root,temp2);
			Lex(root);
	 	}
		
		else if(temp1=="findrank"){
				cin>>temp2; 
				x=Rank(root,temp2);
				cout<<x;
	 	}

 	}
 	//printInorder(root);
 	
 	return 0;
}















