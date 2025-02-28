#include <iostream>
#include <vector>

#define inf 50000
#define V 5

using namespace std;

int minDistance(int dist[],int inTree[]){
	int min = inf;
	int min_index;
	
	for(int v = v;v<V;v++){
		if(inTree[v] == 0 && dist[v] <= min){
			min = dist[v];
			min_index = v;
		}
	}
	return min_index;
}

void dijkstra(vector<vector<int> > G,int src){
	int dist[V], inTree[V], parent[V];
	for(int i = 0;i < V ; i++){
		dist[i] = 50000, parent[i] = -1 , inTree[i] = -1;
	}

	dist[src] = 0;
	for(int i = 0;i<V-1;i++){
		int u = minDistance(dist, inTree);
		inTree[u] = 1;
		for(int v = 0;v<V;v++){
			if(inTree[v] == 0 && dist[u] + G[u][v] < dist[v]){
				dist[v] = dist[u] + G[u][v];
				parent[v] = u;
			}
		}
	}
}
int main(){
	int n,edge,start;
	int i,j;
	cin>>n>>edge>>start;
	vector<vector<int> > G(n,vector<int>(n,0));
	
	int u,v,w;
	for(int i = 0;i<edge;i++){
		cin>>u>>v>>w;
		G[u][v] = w;
		G[v][u] = w;
	}
	
	dijkstra(G,start);
	
}

/*
6 6 1
1 2 5
1 4 9
1 5 1
5 4 2
2 3 2
3 4 6

*/
