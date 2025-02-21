#include <iostream>
#include <queue>
using namespace std;

void DFS(int);
void BFS(int);

int G[100][100], visited[100],n,edge,start;

int main(){
	int i,j;
	cin>>n>>edge>>start;
	
	int u,v;
	for(int i = 0;i<edge;i++){
		cin>>u>>v;
		G[u][v] = 1;
		G[v][u] = 1;
	}
	
	for(int i = 0;i<n;i++){
		visited[i] = 0;
	}
//	DFS(start);
	BFS(start);
}

void DFS(int i){
	int j;
	cout<<i<<" ";
	visited[i] = 1;
	for(int j = 0;j<n;j++){
		if(G[i][j] == 1 && !visited[j]){
			DFS(j);
		}
	}
}

void BFS(int start){
	queue<int> q;
	
	q.push(start);
	visited[start] = 1;
	while(!q.empty()){
		int current = q.front();
		q.pop();
		cout<<current<<" ";
		
		for(int i = 0;i<n;i++){
			if(G[current][i] && !visited[i]){
				q.push(i);
				visited[i] = 1;
			}
		}
	}
}

/*
6 6 2
0 1
0 2
1 3
2 3
3 4
4 5

8 10 0
0 1
0 2
0 3
0 4
1 5
2 5
3 6
4 6
5 7
6 7
*/
