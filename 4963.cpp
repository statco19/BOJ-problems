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

int bd[51][51];
bool vis[51][51];
int w,h;

void bfs(int r, int c) {
	queue<pii> q;
	q.push({r,c});
	vis[r][c] = 1;

	while(!q.empty()) {
		auto p = q.front(); q.pop();

		r = p.first;
		c = p.second;

		int nr,nc;
		for(int d=0; d<8; ++d) {
			nr = r + d8r[d];
			nc = c + d8c[d];

			if(1<=nr&&nr<=h && 1<=nc&&nc<=w && bd[nr][nc] && !vis[nr][nc]) {
				vis[nr][nc] = 1;
				q.push({nr,nc});
			}
		}
	}
	return;
}

void sol() {
	while(1) {
		cin >> w >> h;
		if(!w && !h) break;

		mset(bd,0);
		mset(vis,0);
		int ans = 0;

		for(int i=1; i<=h; ++i) {
			for(int j=1; j<=w; ++j) {
				cin >> bd[i][j];
			}
		}

		for(int i=1; i<=h; ++i) {
			for(int j=1; j<=w; ++j) {
				if(bd[i][j] && !vis[i][j]) {
					ans++;
					bfs(i,j);
				}
			}
		}

		cout << ans << en;
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