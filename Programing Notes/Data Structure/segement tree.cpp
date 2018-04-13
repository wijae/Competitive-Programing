const int N = 1<<20;
const ll init_val = 1, MOD=1e9+7;

struct Segment{
	ll tree[2*N+1];
	ll f(ll a, ll b){return (a*b)%MOD;}

	Segment(){
		for(int i=1; i<=2*N; i++)
			tree[i] = init_val;
	}

	void update(int i, ll val){
		tree[i+N] = val;
		for(i+=N; i/=2;)
			tree[i] = f(tree[2*i], tree[2*i+1]);
	}

	ll query(int a, int b){
		ll ans = init_val;
		for(a+=N,b+=N; a<=b; a=(a+1)/2,b=(b-1)/2){
			if(a&1) ans = f(ans, tree[a]);
			if(!(b&1)) ans = f(ans, tree[b]);
		}
		return ans;
	}
}S;