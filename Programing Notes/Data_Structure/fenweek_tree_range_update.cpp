struct FenwickRange{
  Fenwick F[2];

  void update(int a, int b, ll val){
    F[0].update(a, val);
    F[0].update(b+1, -val);
    F[1].update(a, val*(a-1));
    F[1].update(b+1, -val*b);
  }
  
  ll query(int i){
    return F[0].query(i)*i - F[1].query(i);
  }
  
  ll query(int a, int b){
    return query(b) - query(a-1);
  }
}F;