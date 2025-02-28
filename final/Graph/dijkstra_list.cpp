#include <iostream>
#include <vector>
#include <queue>
#include <stack>

#define INF 50000
using namespace std;

void Dijkstra(vector<pair<int,int> > adj[], int V, int src,int des){
	priority_queue< pair<int, int>, vector <pair<int, int> >, greater<pair<int, int> > > pq;
	stack<int> st;
	
	vector<int> dist(V, INF);
	vector<int> parent(V, -1);
	vector<bool> intree(V, false);
	
	pq.push( {0, src} );
	dist[src] = 0;
	
	while( !pq.empty()){
		cout<<pq.top().first<<"|"<<pq.top().second<<endl;
		int u = pq.top().second;
		intree[u] = true;
		pq.pop();
		for(int j = 0;j<adj[u].size();j++){
			int v = adj[u][j].first;
			int weight = adj[u][j].second;
			
			if(intree[v] == false && dist[u] + weight < dist[v]){
				dist[v] = dist[u] + weight;
				pq.push({dist[v],v});
				parent[v] = u;
			}
		}
	}
	
	int i = des;
	st.push(i);
	while(parent[i] != -1){
		st.push(parent[i]);
		i = parent[i];
	}
	
	while(!st.empty()){
		cout<<st.top()<<" ";
		st.pop();
	}
	cout<<endl;
}

int main(){
	int n,edges,start,des;
	
	
	cin>>n>>edges>>start>>des;
	n++;
	
	vector<pair<int,int> > adj[n];
	
	int u,v,w;
	for(int i = 0;i<edges;i++){
		cin>>u>>v>>w;
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}
	
	Dijkstra(adj, n, start, des);
}

/*
5 6 1 4
1 2 5
1 4 9
1 5 1
5 4 2
2 3 2
3 4 6

*/
