#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using cdouble = complex<double>;

void fft(vector <cdouble> &a, int sgn)
{
	int n = a.size();
	for (int i=1,j=0,t; i<n; i++){
		for (t=n>>1; j>=t; j-=t, t>>=1);
		j += t;
		if (i < j) swap(a[i],a[j]);
	}

	for (int i=2; i<=n; i<<=1){
		double ang = sgn*2*acos(-1)/i;
		cdouble wi(cos(ang),sin(ang));

		for (int j=0; j<n; j+=i){
			cdouble w(1);
			for (int k=0; k<i/2; k++){
				cdouble u = a[j+k];
				cdouble v = a[j+k+i/2]*w;
				a[j+k] = u+v;
				a[j+k+i/2] = u-v;
				w *= wi;
			}
		}
	}
}

vector<double> multiply(vector<double> &v, vector<double> &w)
{
	int n;
	for(n=1; n<v.size()+w.size(); n<<=1);

	vector<cdouble> fv(v.begin(), v.end());
	vector<cdouble> fw(w.begin(), w.end());
	fv.resize(n);
	fw.resize(n);
	fft(fv, 1);
	fft(fw, 1);

	for (int i=0; i<n; i++) 
		fv[i] *= fw[i];
	
	fft(fv, -1);
	
	vector<double> res(n);
	for (int i=0;i<n;i++) 
		res[i] = fv[i].real()/n;

	return res;
}