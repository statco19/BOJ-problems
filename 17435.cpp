#include <bits/stdc++.h>

#define vt vector
#define en '\n'
#define ll long long
#define ld long double
#define pb push_back
#define pii pair<int,int>
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rev(c) (c).rbegin(), (c).rend()
#define mid (st+end)/2

using namespace std;
const int INF = 0x3f3f3f3f; const int mINF = 0xc0c0c0c0;
const ll LINF = 0x3f3f3f3f3f3f3f3f; const ll mLINF = 0xc0c0c0c0c0c0c0c0;
int T = 1;

const int mx = 5e5;
int m,Q;
vt<int> v;
int sparse[(int)ceil(log2(mx))+1][mx+1];

void sol() {
	cin >> m;
	v.resize(m+1);
	for(int i=1; i<=m; ++i) cin >> v[i];
	for(int j=1; j<=m; ++j) {
		sparse[0][j] = v[j];
	}

	for(int i=1; i<=ceil(log2(mx)); ++i) {
		for(int j=1; j<=m; ++j) {
			sparse[i][j] = sparse[i-1][sparse[i-1][j]];
		}
	}

	cin >> Q;
	int n,x;
	for(int i=0; i<Q; ++i) {
		cin >> n >> x;
		int r = 0;
		while(n) {
			if(n & 1) {
				x = sparse[r][x];
			}
			r++;
			n >>= 1;
		}
		cout << x << en;
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	while(T--) {
		sol();
	}

	return 0;
}