const int N = 1e6;
bool b[N+5];
int c[N+5];
vector<int> p;

void init(){
	for(int i=2; i<=N; i++)
		b[i] = true;

	for(int i=2; i<=sqrt(N); i++)
		if(b[i])
			for(int j=2; i*j<=N; j++)
				b[i*j] = false;
				
	for(int i=2; i<=N; i++){
		if(b[i])
			p.push_back(i);
		
		c[i] = c[i-1] + b[i];
	}
}

ll count(ll n, ll k){
	if(n<=1 || k<0) return 0;
	if(n<=p[k]) return n-1;

	return  n/p[k] - count(n/p[k], k-1) + count(n, k-1);
}

ll count_primes(ll n){
	ll k = c[(int)sqrt(n)+1];
	return n - count(n, k) + k;
}
