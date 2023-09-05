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

int n;
int ar[101][101];
int vis[101][101];

void bfs(int r, int c, int k) {
	queue<pii> q;
	vis[r][c] = 1;
	q.push({r,c});

	while(!q.empty()) {
		pii p = q.front(); q.pop();
		r = p.first;
		c = p.second;
		int nr,nc;
		for(int d=0; d<4; ++d) {
			nr = r + d4r[d];
			nc = c + d4c[d];
			if(0<nr&&nr<=n && 0<nc&&nc<=n && ar[nr][nc] > k && !vis[nr][nc]) {
				vis[nr][nc] = 1;
				q.push({nr,nc});
			}
		}
	}
}

void sol() {
	cin >> n;
	int h = mINF;
	int mh = INF;
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=n; ++j) {
			cin >> ar[i][j];
			h = max(h, ar[i][j]);
			mh = min(mh, ar[i][j]);
		}
	}

	vt<int> v = {1};
	for(int k=mh; k<h; ++k) {
		int sum = 0;
		mset(vis,0);
		for(int i=1; i<=n; ++i) {
			for(int j=1; j<=n; ++j) {
				if(ar[i][j] > k && !vis[i][j]) {
					bfs(i,j,k);
					sum++;
				}
			}
		}
		v.pb(sum);
	}
	cout << *max_element(all(v)) << en;

	return;
}


int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);

	while(T--) {
		sol();
	}

   return 0;
}