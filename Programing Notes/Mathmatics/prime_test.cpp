bool is_prime(int n){
	if(n%2==0||n%3==0)
		return (n<=3);
	
	for(int i=6; i<=sqrt(n); i+=6)
		if(n%(i-1)==0 || n%(i+1)==0)
			return false;
	
	return true;
}