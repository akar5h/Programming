#include <bits/stdc++.h>

using namespace std;

void addEdge(vector<int> adj[],int u,int v){
	adj[u].push_back(v);
}

void PrintTraversal(vector<int> adj[],int u, int visited[]){
	int p,temp,temp1,temp2;
	p= adj[u].size();
	
	if(p==0){
		visited[u] = 1;
		cout<<u<<" " ;
		return;
	}

	for(int i=0;i<p/2;i++){
		temp1= adj[u][i];
		if(visited[temp1]==0)
			PrintTraversal(adj,temp1,visited);
	}

	cout<< u << " ";

	for(int j=p/2;j<p;j++){
		temp2= adj[u][j];
		if(visited[temp2]==0)
			PrintTraversal(adj,temp2,visited);
	}
	
	visited[u]=1;
	return;
}

void MainUtil(){
	int V,temp1,temp2;
	cin>>V;
	vector<int> adj[V];
	int visited[V];
	for(int j=1;j<=V;j++){
		visited[j]=0;
	}

	for(int i=0;i<V-1;i++){
		cin>>temp1;
		cin>>temp2;
		addEdge(adj,temp1,temp2);
		temp1=0;
		temp2=0;
	}
	for(int j=0;j<V;j++){
		sort(adj[j].begin(),adj[j].end());
	}
	PrintTraversal(adj,1,visited);
	
}
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		MainUtil();
}