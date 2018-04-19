const int N = 1e6;
struct Fenwick{
	ll tree[N];

	Fenwick(){
		for(int i=1; i<N; i++)
			tree[i] = 0;
	}
		
	void update(int i, ll val){
		for(; i<N; i+=(i&-i))
			tree[i] += val;
	}
	
	ll query(int i){
		ll ans = 0;
		for(; i>0; i-=(i&-i))
			ans += tree[i];
			
		return ans;
	}
}F;