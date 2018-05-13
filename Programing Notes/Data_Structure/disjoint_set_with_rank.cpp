#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1100000;
int parent[N], rank[N];

void init(int n){
	int i;
	for(i=0; i<n; i++){
		parent[i] = i;
		rank[i] = 0;
	}
}

//path compression
int find(int n){
	if(parent[n] != n) parent[n] = find(parent[n]);
	return parent[n];
}

//union by rank
void merge(int a, int b){
	a = find(a), b = find(b);
	if(a == b) return;
	
	if(rank[a] > rank[b]) parent[b] = a;
	else if(rank[a] > rank[b]) parent[a] = b;
	else{
		parent[b] = a;
		rank[a]++;
	}
}