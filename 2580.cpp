#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define vt vector
#define ll long long
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define en '\n'
const int d4r[4] = {-1,0,1,0}; const int d4c[4] = {0,1,0,-1};
const int d8r[8] = {-1,-1,0,1,1,1,0,-1}; const int d8c[8] = {0,1,1,1,0,-1,-1,-1};
const int INF = 0x3f3f3f3f; const int mINF = 0xc0c0c0c0;
const ll LINF = 0x3f3f3f3f3f3f3f3f; const ll mLINF = 0xc0c0c0c0c0c0c0c0;
int T = 1;

int bd[10][10];
bool vr[10][10], vc[10][10], vs[10][10];

void dfs(int r, int c) {
	if(r == 10) {
		for(int i=1; i<=9; ++i) {
			for(int j=1; j<=9; ++j) {
				cout << bd[i][j] << ' ';
			}
			cout << en;
		}

		exit(0);
	}

	int ni, nj;
	if(bd[r][c]) {
		ni = c == 9 ? r+1 : r;
		nj = c == 9 ? 1 : c+1;
		dfs(ni,nj);
	} else {
		int nr = 3*((r-1)/3);
		int nc = 3*((c-1)/3);
		int idx = 3*nr/3 + nc/3 + 1;

		for(int k=1; k<=9; ++k) {
			if(!vr[r][k] && !vc[c][k] && !vs[idx][k]) {
				bd[r][c] = k;
				vr[r][k] = 1; vc[c][k] = 1; vs[idx][k] = 1;
				int nr = c == 9 ? r+1 : r;
				int nc = c == 9 ? 1 : c+1;
				dfs(nr,nc);
				bd[r][c] = 0;
				vr[r][k] = 0; vc[c][k] = 0; vs[idx][k] = 0;
			}
		}
	}

	return;
}

void sol() {
	for(int i=1; i<=9; ++i) {
		for(int j=1; j<=9; ++j) {
			cin >> bd[i][j];
			if(bd[i][j]) {
				vr[i][bd[i][j]] = 1;
				vc[j][bd[i][j]] = 1;

				int nr = 3*((i-1)/3);
				int nc = 3*((j-1)/3);

				int idx = 3*nr/3 + nc/3 + 1;
				vs[idx][bd[i][j]] = 1;
			}
		}
	}

	dfs(1,1);

	return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	while(T--) {
		sol();
	}

	return 0;
}