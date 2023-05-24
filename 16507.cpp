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
const int d4r[4] = {-1,0,1,0}; const int d4c[4] = {0,1,0,-1};
const int d8r[8] = {-1,-1,0,1,1,1,0,-1}; const int d8c[8] = {0,1,1,1,0,-1,-1,-1};
const int INF = 0x3f3f3f3f; const int mINF = 0xc0c0c0c0;
const ll LINF = 0x3f3f3f3f3f3f3f3f; const ll mLINF = 0xc0c0c0c0c0c0c0c0;
int T = 1;

void sol() {
	int a[1002][1002] = {0};
	int p[1002][1002] = {0};
	int R,C,Q;
	cin >> R >> C >> Q;
	for(int i=1; i<=R; ++i) {
		for(int j=1; j<=C; ++j) {
			cin >> a[i][j];
		}
	}

	for(int i=1; i<=R; ++i) {
		for(int j=1; j<=C; ++j) {
			p[i][j] = p[i][j-1] + a[i][j];
		}
	}

	for(int i=1; i<=R; ++i) {
		for(int j=1; j<=C; ++j) {
			p[i][j] += p[i-1][j];
		}
	}

	int r1,c1,r2,c2;
	int x;
	while(Q--) {
		cin >> r1 >> c1 >> r2 >> c2;
		x = p[r2][c2] - p[r1-1][c2] - p[r2][c1-1] + p[r1-1][c1-1];
		cout << x / ((abs(r1-r2)+1)*(abs(c1-c2)+1)) << en;
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