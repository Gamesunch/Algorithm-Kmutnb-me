#include <bits/stdc++.h>
using namespace std;

struct CPU{
	int ID,start,finish,duration;
};

bool longestTime(const CPU &a,const CPU &b){
	return a.duration > b.duration;
}

bool earlistStart(const CPU &a,const CPU &b){
	return a.start < b.start;
}

bool earlistEnd(const CPU &a,const CPU &b){
	return a.finish < b.finish;
}

int findCPU(vector<CPU> &A){
	vector<pair<int,int> > events;
	for(int i = 0;i<A.size();i++){
		events.push_back({A[i].start,1});
		events.push_back({A[i].finish,-1});
	}
	sort(events.begin(),events.end());
	int max = 0;
	int current = 0;
	
	for(int i = 0;i<events.size();i++){
		current += events[i].second;
		if(current > max){
			max = current;
		}
	}
	
	return max;
}

int useStragy(vector<CPU> &A, bool (*cmp)(const CPU &,const CPU &)){
	sort(A.begin(),A.end(), cmp);
	for(int i = 0;i<A.size();i++){
		cout<<A[i].ID<<" ";
	}
	cout<<endl;
	
	int totalCPU = findCPU(A);
	cout<<totalCPU<<endl;
}
int main(){
	int n;
	
	cin>>n;
	vector<CPU> A(n);
	
	for(int i = 0;i<n;i++){
		A[i].ID = i + 1;
		cin>>A[i].start>>A[i].finish;
		
		A[i].duration = A[i].finish - A[i].start;
	}
	
	useStragy(A,longestTime);
	useStragy(A,earlistStart);
	useStragy(A,earlistEnd);
}

/*
10
1 4
3 5
0 6
5 7
3 8
5 9
6 10
8 11
8 12
2 13
*/
