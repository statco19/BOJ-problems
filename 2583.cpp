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

int m,n,k;
int ar[101][101];

int bfs(int r, int c) {
	int sum = 0;
	queue<pii> q;
	ar[r][c] = 1;
	sum++;
	q.push({r,c});

	while(!q.empty()) {
		pii p = q.front(); q.pop();
		r = p.first;
		c = p.second;
		int nr,nc;
		for(int d=0; d<4; ++d) {
			nr = r + d4r[d];
			nc = c + d4c[d];
			if(0<=nr&&nr<m && 0<=nc&&nc<n && !ar[nr][nc]) {
				ar[nr][nc] = 1;
				sum++;
				q.push({nr,nc});
			}
		}
	}

	return sum;
}

void sol() {
	cin >> m >> n >> k;
	for(int i=0; i<k; ++i) {
		int r1,r2,c1,c2;
		cin >> c1 >> r1 >> c2 >> r2;
		int rn = min(r1,r2), rx = max(r1,r2);
		int cn = min(c1,c2), cx = max(c1,c2);

		for(int y=rn; y<rx; ++y) {
			for(int x=cn; x<cx; ++x) {
				ar[y][x] = 1;
			}
		}
	}

	int r,c;
	int ans = 0;
	vt<int> v;
	for(int i=0; i<m; ++i) {
		for(int j=0; j<n; ++j) {
			if(!ar[i][j]) {
				ans++;
				v.pb(bfs(i,j));
			}
		}
	}
	cout << ans << en;
	sort(all(v));
	for(int i=0; i<sz(v); ++i) {
		cout << v[i] << ' ';
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