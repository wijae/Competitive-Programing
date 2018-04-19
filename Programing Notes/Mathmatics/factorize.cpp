int factor(int n){
	if(n%2==0)
		return 2;
	
	for(int i=3; i<=sqrt(n); i+=2)
		if(n%i==0)
			return i;
	
	return n;
}

vector<int> factorize(int n){
	vector<int> ans;
	
	while(n>1){
		int r = factor(n);
		ans.push_back(r);
		n /= r;
	}
	
	return ans;
}