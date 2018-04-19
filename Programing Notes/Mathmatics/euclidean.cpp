ll gcd(ll a, ll b){
	if (b==0) return a;
	return  extended_gcd(b, a%b);
}

pair<ll ,ll> extended_gcd(ll a, ll b){
	if (b==0) return make_pair(1,0);
	pair<ll ,ll> t = extended_gcd(b, a%b);
	return make_pair(t.second, t.first - t.second*(a/b));
}

pair<ll ,ll> extended_gcd(ll a, ll b){
	if (b==0) return make_pair(1,0);
	pair<ll ,ll> t = extended_gcd(b, a%b);
	return make_pair(t.second, t.first - t.second*(a/b));
}