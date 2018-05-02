const int N = 1e6;
vector<int> comp; //sorted coordinates
inline int getcoord(int idx){return comp[idx];}
inline int getidx(int coord){return lower_bound(comp.begin(), comp.end(), coord) - comp.begin();}