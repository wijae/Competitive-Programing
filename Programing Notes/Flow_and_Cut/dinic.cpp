#include <bits/stdc++.h>

#define ll long long
using namespace std;

struct maxflow{
	const static int N = 5000;
	vector<int> edge[N];
	ll cap[N][N];
	ll level[N], back[N];

	void add_edge(int a, int b, ll c){
		cap[a][b] = c;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}

	void lbfs(int s, int t){
		queue<int> que;
		que.push(s);
		level[s] = 0;

		while(!que.empty()){
			int now = que.front();
			que.pop();	

			for(int i: edge[now]){
				if(level[i]<0 && cap[now][i]>0){
					que.push(i);
					level[i] = level[now]+1;
				}
			}
		}
	}

	void dfs(int now, int t){
		if(now == t) return;

		for(int i: edge[now]){
			if(level[now]+1==level[i] && back[i]<0 && cap[now][i]>0){
				back[i] = now;
				dfs(i, t);
			}
		}
	}

	ll calc(int s, int t){
		ll ans = 0;
		while(true){
			//find level
			fill(level, level+N, -1);
			lbfs(s,t);
			if(level[t]<0) break;

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
					cap[back[now]][now] -= f;
					cap[now][back[now]] += f;
				}
			}
		}
		return ans;
	}
}mf;