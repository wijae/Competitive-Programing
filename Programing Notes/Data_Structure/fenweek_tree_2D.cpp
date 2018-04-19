const int XN=5.1e3, YN=5.1e3;
struct Fenick2D{
	ll tree[XN][YN];

	Fenwick2D(){
		for(int i=1; i<XN; i++)
			for(int j=1; j<YN; j++)
					tree[i][j] = 0;
	}

	void update(int x, int y, ll val){
		for(int i=x; i<XN; i+=(i&-i))
			for(int j=y; j<YN; j+=(j&-j))
				tree[i][j]+=val;
	}

	ll query(int x, int y){
		ll ans = 0;
		for(int i=x; i>0; i-=(i&-i))
			for(int j=y; j>0; j-=(j&-j))
				ans+=tree[i][j];

		return ans;
	}
}F;