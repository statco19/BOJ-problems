#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define vt vector
#define ll long long
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define en '\n'
int T = 1;

int n;
int bd[11][11];
int ans;
int vr[21], vl[20];
int N;
vt<vt<pii>> diag;

void dfs(int depth, int cnt) {
	if(depth == N) {
		ans = max(ans, cnt);
		return;
	}
	bool move = false;
	for(int i=0; i<sz(diag[depth]); ++i) {
		int r = diag[depth][i].first;
		int c = diag[depth][i].second;
		if(!vl[depth] && !vr[r+c]) {
			move = true;
			vl[depth] = 1;
			vr[r+c] = 1;
			dfs(depth+1, cnt+1);
			vr[r+c] = 0;
			vl[depth] = 0;
		}
	}
	if(!move) {
		dfs(depth+1, cnt);
	}
	
	return;
}

void sol() {
	cin >> n;
	N = 2*(n-1)+1;
	diag.resize(N);
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=n; ++j) {
			cin >> bd[i][j];
			if(bd[i][j]) {
				diag[j-i+(n-1)].pb({i,j});
			}
		}
	}

	dfs(0,0);
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