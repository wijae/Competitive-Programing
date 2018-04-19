const int N = 1e6;

struct Disjoint(){
	int parent[N];
		
	disjoint(){
		for(int i=0; i<N; i++)
			parent[i] = i;
	}
		
	int find(int i){
		return parent[i]==i ? i : (parent[i] = find(parent[i]));    
	}
		
	void union(int a, int b){
		a = find(a), b = find(b);
		parent[b] = a;
	}
}D;