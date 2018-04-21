const int N = 1<<20;
const ll init_val = 0;

class Segment{
	ll tree[2*N+1], lazy[2*N+1];
	inline ll f(ll a, ll b){return a+b;}
	inline ll fn(ll a, int n){return a*n;}

	void _prop(int n, int ns, int ne){
		tree[n] = f(tree[n], fn(lazy[n], (ne-ns+1)));
		if (ns != ne){
			lazy[2*n] = f(lazy[2*n], lazy[n]);
			lazy[2*n+1] = f(lazy[2*n+1], lazy[n]);
		}
		lazy[n] = init_val;
	}

	void _update(int n, int ns, int ne, int a, int b, ll val){
		if(lazy[n] != init_val) _prop(n, ns, ne);
		if (a > ne || b < ns) return;
		if (a <= ns && ne <= b){
			tree[n] = f(tree[n], fn(val, (ne-ns+1)));
			if (ns != ne){
				lazy[2*n] = f(lazy[2*n], val);
				lazy[2*n+1] = f(lazy[2*n+1], val);
			}
		}
		else{
			_update(2*n, ns, (ns+ne)/2, a, b, val);
			_update(2*n+1, (ns+ne)/2+1, ne, a, b, val);
			tree[n] = f(tree[2*n], tree[2*n+1]);
		}
	}

	ll _query(int n, int ns, int ne, int a, int b){
		if(lazy[n] != init_val) _prop(n, ns, ne);
		if (a > ne || b < ns) return init_val;
		if (a <= ns && ne <= b) return tree[n];
		return f(_query(2*n, ns, (ns+ne)/2, a, b), _query(2*n+1, (ns+ne)/2+1, ne, a, b));
	}

	public:
		Segment(){
			for(int i=1; i<=2*N; i++){
				tree[i] = init_val;
				lazy[i] = init_val;
			}
		}

		inline void update(int a, int b, ll val){
			_update(1, 1, N, a, b, val);
		}

		inline ll query(int a, int b){
			return  _query(1, 1, N, a, b);
		}
}S;