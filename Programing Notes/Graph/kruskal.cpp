const int N = 1e5, M=1e6;
Disjoint D;
tuple<int, int, int> edge[M];

ll kruskal(int n, int m){
  sort(edge, edge+m);
  
  ll ans = 0, cnt = 0;
  for(int i=0; i<m && cnt<n-1; i++){
    int w, a, b;
    tie(w, a, b) = edge[i];
      
    if(D.find(a) != D.find(b)){
      D.union(a, b);
      ans += w;
      cnt++;
    }
  }
    
  return ans;
}