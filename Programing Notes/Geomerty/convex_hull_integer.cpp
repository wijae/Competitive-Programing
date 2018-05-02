struct Point{
	ll x, y;
	Point() {}
	Point(ll x_, ll y_): x(x_), y(y_) {}
};

inline int ccw(Point a, Point b, Point c){
	ll rtn = (a.x-b.x)*(a.y-c.y)-(a.x-c.x)*(a.y-b.y);
	return rtn>0 ? 1 : rtn<0 ? -1 : 0;
}

vector<Point> convex_hull(vector<Point> p){
	if(p.size()<3) return p;
	
	sort(p.begin(), p.end(), [&](Point a, Point b){
		return a.x==b.x ? a.y<b.y : a.x<b.x;
	});
	sort(p.begin()+1, p.end(), [&](Point a, Point b){
		int det = ccw(p[0], a, b);
		return det==0 ? a.x<b.x : det<0;
 	});

	vector<Point> ans;
	ans.push_back(p[0]);
	ans.push_back(p[1]);
	for(int i = 2 ; i < p.size() ; i++) {
		while (ans.size() > 1 && ccw(ans[ans.size()-2], ans[ans.size()-1], p[i]) >= 0)
			ans.pop_back();
		ans.push_back(p[i]);
	}

	return ans;
}