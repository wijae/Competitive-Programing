ll gcd(ll a, ll b){
	return b==0 ? a : gcd(b, a%b);
}

pair<ll ,ll> extended_gcd(ll a, ll b){
	if (b==0) return {1, 0};
	auto t = extended_gcd(b, a%b);
	return {t.second, t.first - t.second*(a/b)};
}