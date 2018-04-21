const int N = 1.1e6;

class Fenwick{
	ll tree[2][N];
		
	void _update(int t, int i, ll val){
		for(; i<N; i+=(i&-i))
			tree[t][i] += val;
	}
	
	ll _query(int t, int i){
		ll ans = 0;
		for(; i>0; i-=(i&-i))
			ans += tree[t][i];
			
		return ans;
	} 
	public:
		Fenwick(){
			for(int i=1; i<2; i++)
				for(int j=1; j<N; j++)
					tree[i][j]= 0;
		}

		void update(int a, int b, ll val){
			_update(0, a, val);
			_update(0, b+1, -val);
			_update(1, a, val*(a-1));
			_update(1, b+1, -val*b);
		}
		
		ll query(int i){
			return _query(0, i)*i - _query(1, i);
		}
		
		ll query(int a, int b){
			return query(b) - query(a-1);
		}
}F;