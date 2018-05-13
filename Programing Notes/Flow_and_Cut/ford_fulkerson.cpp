#include <bits/stdc++.h>

#define ll long long
using namespace std;

struct maxflow{
	const static int N = 1000;
	vector<int> edge[N];
	ll cap[N][N];
	ll back[N];

	void add_edge(int a, int b, ll c){
		cap[a][b] = c;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}

	void dfs(int now, int t){
		if(now == t) return;

		for(int i : edge[now]){
			if(back[i]<0 && cap[now][i]>0){
				back[i] = now;
				dfs(i, t);
			}
		}
	}

	ll calc(int s, int t){
		ll ans = 0;
		while(true){
			//run dfs
			fill(back, back+N, -1);
			dfs(s,t);
			if(back[t]<0) break;

			//calculate flow
			ll f = 1LL<<60;
			for(int now=t; now!=s; now=back[now])
				f = min(f, cap[back[now]][now]);

			//push flow
			ans += f;
			for(int now=t; now!=s; now=back[now]){
				int b = back[now];
				cap[b][now] -= f;
				cap[now][b] += f;
			}
		}
		return ans;
	}
}mf;