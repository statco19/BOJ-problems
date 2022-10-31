#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define vt vector
#define ll long long
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define en '\n'
// const int d4r[4] = {-1,0,1,0}; const int d4c[4] = {0,1,0,-1};
const int d4r[4] = {0,0,1,-1}; const int d4c[4] = {1,-1,0,0};
const int d8r[8] = {-1,-1,0,1,1,1,0,-1}; const int d8c[8] = {0,1,1,1,0,-1,-1,-1};
const int INF = 0x3f3f3f3f; const int mINF = 0xc0c0c0c0;
const ll LINF = 0x3f3f3f3f3f3f3f3f; const ll mLINF = 0xc0c0c0c0c0c0c0c0;
int T = 1;

int N;
double ans;
bool v[30][30];
vt<double> p;

void dfs(int r, int c, int depth, double prob) {
	if(depth == N) {
		ans += prob;
		return;
	}

	int nr,nc;
	for(int d=0; d<4; ++d) {
		nr = r + d4r[d];
		nc = c + d4c[d];

		if(1<=nr&&nr<=29 && 1<=nc&&nc<=29 && !v[nr][nc]) {
			v[nr][nc] = 1;
			dfs(nr,nc,depth+1,prob * p[d]);
			v[nr][nc] = 0;
		}
	}

	return;
}

void sol() {
	cin >> N;
	double x;
	for(int i=0; i<4; ++i) {
		cin >> x;
		x /= 100;
		p.pb(x);  // E, W, S, N
	}

	v[15][15] = 1;
	dfs(15,15,0,1.0);

	cout << fixed;
	cout.precision(10);
	cout << ans << en;

	return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	while(T--) {
		sol();
	}

	return 0;
}