#include <bits/stdc++.h>

#define ll long long
using namespace std;

struct maxflow{
	const static int N = 2000;
	vector<int> edge[N];
	ll cap[N][N];
	ll back[N];

	void add_edge(int a, int b, ll c){
		cap[a][b] = c;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}

	void bfs(int s, int t){
		queue<int> que;
		que.push(s);

		while(!que.empty() && back[t]<0){
			int now = que.front();
			que.pop();
			for(int i: edge[now]){
				if(back[i]<0 && cap[now][i]>0){
					que.push(i);
					back[i] = now;
				}
			}
		}
	}

	ll calc(int s, int t){
		ll ans = 0;
		while(true){
			//run bfs
			fill(back, back+N, -1);
			bfs(s,t);
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