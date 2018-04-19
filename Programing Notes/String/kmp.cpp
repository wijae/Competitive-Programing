vector<int> KMP(const string &T, const string &P){
	//find failure function
	vector<int> fail(P.size(), 0);
	for(int i=1, k=0; i<P.size(); i++){
		while(k > 0 && P[k] != P[i]) k = fail[k-1];
		if(P[k] == P[i]) k++;
		fail[i] = k;
	}

	//run matching
	vector<int> ans;
	for(int i=0, k=0; i<T.size(); i++){
		while(k > 0 && P[k] != T[i]) k = fail[k-1];
		if(P[k] == T[i]) k++;
		if(k == P.size()) ans.push_back(i-k+1); //matched point
	}

	return ans;
}