#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void addLink(vector<pair <int,int> > adj[],int x, int y,int w){

	adj[x].push_back(make_pair(y,w));
	adj[y].push_back(make_pair(x,w));
}
int minIndex(queue<int> Q,int d[],int n){
	int min=999999;
	int index=0;
	int i,temp;

	for( i=0;i<Q.size();i++){
		temp = Q.front();
		if(d[temp]<min){
			min=d[temp];
			index=temp;
		}
		cout<<"her222";
		Q.pop();
		Q.push(temp);
	}
	return index;
}
void updateQueue(queue <int> Q,int u){
	int temp;
	cout<<Q.size()<<"\n";
	temp= Q.front();
	for(int i=0;i<Q.size();i++){
	
		if(temp==u){
			Q.pop();
			break;
		}

		else{
			Q.pop();
			Q.push(temp);
			temp= Q.front();
			cout<<"\n Temp is"<<temp;
		}
	}
}
int min(int x,int y){
	if(x<y)
		return x;
	else
		return y;
}

void Relax(int u,int v,int w,int d[],int p[]){
	int new_d = min (d[v],d[u]+w);
	if(new_d < d[v]){
		d[v]= new_d;
		p[v]=u;
	}
}

int main(){
	int n,m,x,y,w;
	cin>>n;cin>>m;
	vector< pair <int,int > > adj[n];
	int d[n], p[n];


	for(int i=0;i<m;i++){
		cin>>x; cin >>y ;cin >> w;
		addLink(adj,x,y,w);
		cout<<"d";
	}

	for(int i=0;i<n;i++){
		d[i]= 999999;
		p[i]= -1;
	}

	d[0]= 0;// INITIALISE SOURCE DISTANCE AS 0 

	queue <int> Q;
	for(int i=0;i<n;i++)
		Q.push(i);

	int u,v;
	while(!Q.empty()){
		u= minIndex(Q,d,n);
		cout<<u<<"minindex \n";
		updateQueue(Q,u);
		cout<<"f";
		for(int i=0;i<adj[u].size();i++){
			cout<<u<<"here1\n";
			cout<<adj[u].at(i).first<<"adj[u].at(i).first\n";		
			Relax(u,adj[u].at(i).first,adj[u].at(i).second,d,p);
		
	}		
		}

		cout<< d[n-1];
	return 0;
}