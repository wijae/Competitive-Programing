#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1e6;
vector<pair<int, int>> edge[N];
priority_queue<pair<int, int>> q;
bool visit[N];

ll prim(int n, int m){
  ll ans = 0;
  
  int last = 0;
  for(int i=0; i<n-1; i++){
    visit[i] = true;
    for(auto p: edge[i])
      q.push(make_pair(-p.second, p.first));
      
    while(!q.empty()){
      auto p = q.top();
      q.pop();
        
      if(!visit[p.second]){
        last = p.second;
        ans += -p.first;
      }  
    }
  }
  
  return ans;
}