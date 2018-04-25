vector<int> suffix_array(string &s){
	int n = s.size();
	vector<int> sa(n, 0), rank(n+1, 0), next(n+1, 0);
	for(int i=0; i<n; i++) sa[i]=i, rank[i]=s[i];

	rank[n]=-1;
	for(int t=1; t<n; t<<=1){
		auto cmp = [&](int i, int j){return rank[i]==rank[j] ?  rank[i+t]<rank[j+t] : rank[i]<rank[j];};
		sort(sa.begin(), sa.end(), cmp);

		next[sa[0]]=0;
		next[n]=-1;
		for(int i=1; i<n; i++){
			if(cmp(sa[i-1],sa[i])) next[sa[i]]=next[sa[i-1]]+1;
			else next[sa[i]]=next[sa[i-1]];
		}
		rank=next;
	}
	return sa;
}

vector<int> lcp(string &s, vector<int> sa){
	int n = s.size();
	vector<int> rev(n, 0), lcp(n, 0);
	for(int i=0; i<n; i++) rev[sa[i]] = i;

	for(int i=0, h=0; i<n; i++){
		if(rev[i]>0){
			int prev = sa[rev[i]-1];
			while(s[prev+h] == s[i+h]) h++;
			lcp[rev[i]] = h;
		}
		h = max(h-1, 0);
	}
	return lcp;
}