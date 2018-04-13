const int XN=1<<10, YN=1<<10;
const ll init_val = 0;
struct Segemnt2D{
	ll tree[2*XN+1][2*YN+1];
	ll f(ll a, ll b){return max(a,b);};

	Segemnt2D(){
		for(int i=1; i<=2*XN; i++)
			for(int j=1; j<=2*YN; j++)
				tree[i][j] = init_val;
	}

	void update(int x, int y, ll val){
		tree[x+XN][y+YN] = val;
		for(int i=x+XN; i/2;){
			for(int j=y+YN; j/2;){
				tree[i][j] = init_val;
				tree[i][j] = f(tree[i][j], tree[2*i][2*j]);
				tree[i][j] = f(tree[i][j], tree[2*i][2*j+1]);
				tree[i][j] = f(tree[i][j], tree[2*i+1][2*j]);
				tree[i][j] = f(tree[i][j], tree[2*i+1][2*j+1]);
			}
		}
	}

	ll query(int ax, int ay, int bx, int by){
		ll ans = init_val;
		for(ax+=XN,bx+=XN; ax<=bx; ax=(ax+1)/2,bx=(bx-1)/2){
			for(ay+=YN,by+=YN; ay<=by; ay=(ay+1)/2,by=(by-1)/2){
				if((ax&1) && (ay&1)) ans = f(ans, tree[ax][ay]);
				if((ax&1) && !(by&1)) ans = f(ans, tree[ax][by]);
				if(!(bx&1) && (ay&1)) ans = f(ans, tree[bx][ay]);
				if(!(bx&1) && !(by&1)) ans = f(ans, tree[bx][by]);
			}
		}

		return ans;
	}
}S;