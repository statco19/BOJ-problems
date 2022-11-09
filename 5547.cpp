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

int W,H;
int bd[102][102];
bool v[102][102];
const int de6r[6] = {-1,-1,0,1,1,0}, de6c[6] = {0,-1,-1,-1,0,1}, do6r[6] = {-1,0,1,1,0,-1}, do6c[6] = {0,-1,0,1,1,1};
int ans;

bool check(int r, int c) {
	return 0<=r&&r<=H+1 && 0<=c&&c<=W+1;
}

void count(int r, int c) {
	int cnt = 0;
	if(r&1) {
		if(check(r-1,c) && bd[r-1][c]) cnt++;
		if(check(r,c-1) && bd[r][c-1]) cnt++;
		if(check(r+1,c) && bd[r+1][c]) cnt++;
		if(check(r+1,c+1) && bd[r+1][c+1]) cnt++;
		if(check(r,c+1) && bd[r][c+1]) cnt++;
		if(check(r-1,c+1) && bd[r-1][c+1]) cnt++;
	} else {
		if(check(r-1,c) && bd[r-1][c]) cnt++;
		if(check(r-1,c-1) && bd[r-1][c-1]) cnt++;
		if(check(r,c-1) && bd[r][c-1]) cnt++;
		if(check(r+1,c-1) && bd[r+1][c-1]) cnt++;
		if(check(r+1,c) && bd[r+1][c]) cnt++;
		if(check(r,c+1) && bd[r][c+1]) cnt++;
	}

	ans += cnt;
	return;
}

void bfs(int r, int c) {
	queue<pii> q;
	q.push({r,c});
	v[r][c] = 1;
	while(!q.empty()) {
		pii p = q.front(); q.pop();
		r = p.first;
		c = p.second;

		count(r,c);
		int nr,nc;
		if(r&1) {
			for(int d=0; d<6; ++d) {
				nr = r + do6r[d];
				nc = c + do6c[d];

				if(check(nr,nc) && !bd[nr][nc] && !v[nr][nc]) {
					v[nr][nc] = 1;
					q.push({nr,nc});
				}
			}
		} else {
			for(int d=0; d<6; ++d) {
				nr = r + de6r[d];
				nc = c + de6c[d];

				if(check(nr,nc) && !bd[nr][nc] && !v[nr][nc]) {
					v[nr][nc] = 1;
					q.push({nr,nc});
				}	
			}
		}
	}
	
}

void sol() {
	cin >> W >> H;
	for(int i=1; i<=H; ++i) {
		for(int j=1; j<=W; ++j) {
			cin >> bd[i][j];
		}
	}

	bfs(0,0);

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