#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct Fenwick{
	const static int N = 1e6;
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
};

struct FenwickRange{
  Fenwick F[2];

  void update(int a, int b, ll val){
    F[0].update(a, val);
    F[0].update(b+1, -val);
    F[1].update(a, val*(a-1));
    F[1].update(b+1, -val*b);
  }
  
  ll query(int i){
    return F[0].query(i)*i - F[1].query(i);
  }
  
  ll query(int a, int b){
    return query(b) - query(a-1);
  }
}F;