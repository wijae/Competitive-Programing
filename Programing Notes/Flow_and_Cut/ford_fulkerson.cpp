const int N = 1000;

struct maxflow{
	vector<int> edge[N];
	int cap[N][N];
	int back[N];

	void add_edge(int a, int b, int c){
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

	int calc(int s, int t){		
		int ans = 0;
		while(true){
			//run bfs
			fill(back, back+N, -1);
			bfs(s,t);
			if(back[t]<0) break;

			//calculate flow
			int f = 1<<30;
			for(int now=t; now!=s; now=back[now])
				f = min(f, cap[back[now]][now]);

			//push flow
			ans += f;
			for(int now=t; now!=s; now=back[now]){
				cap[back[now]][now] -= f;
				cap[now][back[now]] += f;
			}
		}
		return ans;
	}
}mf;