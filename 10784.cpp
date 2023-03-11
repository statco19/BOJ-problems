#include <bits/stdc++.h>
#include <quadmath.h>

#define vt vector
#define en '\n'
#define ll long long
#define ull unsigned long long
#define ld long double
#define ioa insert_or_assign
#define umap unordered_map
#define prq priority_queue
#define pb push_back
#define pii pair<int,int>
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rev(c) (c).rbegin(), (c).rend()
#define mset(ar, val) memset(ar, val, sizeof(ar))

using namespace std;
const int d4r[4] = {-1,0,1,0}; const int d4c[4] = {0,1,0,-1};
const int d8r[8] = {-1,-1,0,1,1,1,0,-1}; const int d8c[8] = {0,1,1,1,0,-1,-1,-1};
const int INF = 0x3f3f3f3f; const int mINF = 0xc0c0c0c0;
const ll LINF = 0x3f3f3f3f3f3f3f3f; const ll mLINF = 0xc0c0c0c0c0c0c0c0;
int T = 1;

int p,a,b,c,d,n;
double price(int k) {
	return p*(sin(a*k+b) + cos(c*k+d) + 2);
}

void sol() {
	cin >> p >> a >> b >> c >> d >> n;

	double ans = 0.0;
	vt<double> v;
	for(int i=1; i<=n; ++i) v.pb(price(i));

	double mx = v[0];
	for(int i=1; i<n; ++i) {
		if(v[i] <= mx) {
			ans = max(ans, mx-v[i]);
		} else {
			mx = v[i];
		}
	}

	cout << fixed; cout.precision(12);
	cout << ans << en;

	return;
}


int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);

	while(T--) {
		sol();
	}

   return 0;
}