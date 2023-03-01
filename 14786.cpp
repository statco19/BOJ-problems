#include <bits/stdc++.h>

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
const int INF = 0x3f3f3f3f; const int mINF = 0xc0c0c0c0;
const ll LINF = 0x3f3f3f3f3f3f3f3f; const ll mLINF = 0xc0c0c0c0c0c0c0c0;
int T = 1;

const double eps = 1e-12;

inline int diff(double lhs, double rhs) {
	if (lhs - eps < rhs && rhs < lhs + eps) return 0;
	return (lhs < rhs) ? -1 : 1;
}

void sol() {
	ld A,B,C;
	cin >> A >> B >> C;

	cout << fixed;
	cout.precision(12);
	ld l = 0, r = 1e5;
	ld x = 0.0;
	bool done = 0;
	while(diff(l,r) == -1) {
		x = (l+r) / 2;

		int d = diff(A*x + B*sin(x), C);
		if(d == 0) {
			done = 1;
			cout << x << en;
			return;
		} else if(d == -1) {
			l = x;
		} else {
			r = x;
		}
	}
	if(!done) {
		cout << x << en;
	}

	return;
}


int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);

	while(T--) {
		sol();
	}

   return 0;
}