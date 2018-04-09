#include<iostream>
#include<vector>
#include<stack>

using namespace std;

void addNode(vector<int> adj[],int x){
	adj[x].push_back(0);
	adj[0].push_back(x);
	
}
void remLink(vector<int> adj[],int x,int y){  // removes x from list of  y

	int temp=0,temp2;
	stack<int> S;
		
	while(temp!=x){
		temp= adj[y].back();
		S.push(temp);
		adj[y].pop_back();
		
	}
	if(S.top()==x)
		S.pop();

	while(!S.empty()){	
		temp2=S.top();
		S.pop();
		adj[y].push_back(temp2);
	}
	if(adj[y].size()==0){
		adj[y].push_back(0);
	}

	return;
}
void deleteNode(vector<int> adj[],int x){
	int temp;
	for(int i= 1; i<adj[x].size(); i++){
		temp = adj[x].at(i);
		remLink(adj,x,temp);

	}
	adj[x].clear();
	return;
}

void addLink(vector<int> adj[],int x, int y){

	adj[x].push_back(y);
	adj[y].push_back(x);
}
void printGraph(vector<int> adj[], int V)
{
    for (int v = 0; v < V; ++v)
    {
        cout << "\n Adjacency list of vertex "
             << v << "\n head ";
        for (int i=0;i<adj[v].size();i++)
           cout << "-> " << adj[v].at(i);
        cout<<"\n";
    }
}
int main(){
	int n,op,k;
	string temp;
	cin>>n;
	cin>>op;
	vector<int> adj[n+1];
	bool ntwrk[n+1];
	for(int i=0;i<n+1;i++)
		ntwrk[i]= false;


	int index=0;
	
	int x;
			
	for (int i = 0; i < op; i++){
		cin>>temp;
		if(temp=="addnode"){
			cin>>x;
			addNode(adj,x);
			ntwrk[x]=true;
		}
		else if(temp=="delnode"){
			int x;
			cin>>x;
			deleteNode(adj,x);
			ntwrk[x]= false;
		}
		else if(temp=="addlink"){
			int x,y;
			cin>>x;
			cin>>y;
			addLink(adj,x,y);
		}
		else if(temp=="remlink"){
			int x,y;
			cin>>x; cin>>y;
			remLink(adj,x,y);
			remLink(adj,y,x);
		
		}
		temp.clear();
	}
	cin>>k;
	int s;
	for(int i=0;i<k;i++){
		cin>>s;
		

		if(ntwrk[s]==false){
			cout<<"not in network";
		}

		else if(ntwrk[s]==true){
			if(adj[s].size()==1){
				cout<<"no connections";
				}

			else{
				for(int j=1;j<adj[s].size();j++)
					cout<<adj[s].at(j)<<" ";
			}

		}
		cout<<"\n";
	}
	/*
		printGraph(adj,n+1);
		for(int i =0;i<index;i++)
			cout<<ntwrk[i]<<" ";
	*/
}