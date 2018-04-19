const ll N = 10, MOD = 1e9+7;

struct mat{
	int n;
	ll m[N][N];

	mat(){ memset(m, 0, sizeof(m)); }
	mat(int nn){ n = nn; memset(m, 0, sizeof(m)); }
	mat(const mat& a){ n = a.n; memcpy(m, a.m, sizeof(m)); }

	mat operator+(const mat& a){
		mat ret = mat(n);

		int i, j;
		for(i=0; i<n; i++)
			for(j=0; j<n; j++)
				ret.m[i][j] = (m[i][j]+a.m[i][j])%MOD;

		return ret;
	}

	mat operator*(const mat& a){
		mat ret = mat(n);

		int i, j, k;
		for(i=0; i<n; i++)
			for(j=0; j<n; j++)
				for(k=0; k<n; k++)
					ret.m[i][j] = (ret.m[i][j]+m[i][k]*a.m[k][j])%MOD;
					
		return ret;
	}
};

mat pow(mat a, ll n){
	if(n==1)
		return mat(a);

	mat m = pow(a,n/2);
	return n%2==0? m*m: a*m*m;
}