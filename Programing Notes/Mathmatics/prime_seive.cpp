const int N = 1e7;
bool prime[N];


void prime_seive(int n){
	for(int i=2; i<=n; i++)
		prime[i] = true;

	for(int i=2; i<=sqrt(n); i++)
		if(prime[i])
			for(int j=2; i*j<=n; j++)
				prime[i*j] = false;
}