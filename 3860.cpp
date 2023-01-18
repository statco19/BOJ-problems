#include <bits/stdc++.h>

#define ll long long
#define vt vector
#define en '\n'
#define pb push_back
#define pii pair<int,int>
#define prq priority_queue
#define sz(x) (x).size()
#define all(x) (x).begin(), (x).end()
#define rev(x) (x).rbegin(), (x).rend()

using namespace std;

const int INF = 0x3f3f3f3f; const int mINF = 0xc0c0c0c0;
const ll LINF = 0x3f3f3f3f3f3f3f3f; const ll mLINF = 0xc0c0c0c0c0c0c0c0;
const int d4r[4] = { -1,0,1,0 }; const int d4c[4] = { 0,1,0,-1 };
int T = 1;

int W,H,G,E;
vt<vt<int>> adj[31][31];
bool grave[31][31];
bool warp[31][31];
queue<pii> q;
ll d[31][31];
int vis[31][31];
bool inQ[31][31];

void init() {
	memset(grave, 0, sizeof(grave));
	memset(warp, 0, sizeof(warp));
	for(int i=0; i<=30; ++i) {
		for(int j=0; j<=30; ++j) {
			adj[i][j].clear();
		}
	}
	memset(d,LINF,sizeof(d));
	memset(vis,0,sizeof(vis));
	memset(inQ,0,sizeof(inQ));
	q = queue<pii> ();
	
	return;
}

bool spfa() {
	q.push({0,0});
	d[0][0] = 0;
	inQ[0][0] = 1;
	vis[0][0]++;
	while(!q.empty()) {
		pii p = q.front(); q.pop();
		int r = p.first;
		int c = p.second;
		inQ[r][c] = 0;
		
		for(int i=0; i<sz(adj[r][c]); ++i) {
			vt<int> &v = adj[r][c][i];
			int nr = v[0];
			int nc = v[1];
			int w = v[2];
			
			if(d[r][c] + w < d[nr][nc]) {
				d[nr][nc] = d[r][c] + w;
				if(!inQ[nr][nc]) {
					if(++vis[nr][nc] >= W*H) {
						return 0;
					}
					q.push({nr,nc});
					inQ[nr][nc] = 1;
				}
			}
		}
	}
	return 1;
}

void sol() {
	while(1) {
		cin >> W >> H;
		if(!W && !H) break;

		init();
		cin >> G;
		int x,y;
		for(int i=0; i<G; ++i) {
			cin >> x >> y;
			grave[y][x] = 1;			
		}
		
		cin >> E;
		int x1,y1,x2,y2,t;
		for(int i=0; i<E; ++i) {
			cin >> x1 >> y1 >> x2 >> y2 >> t;
			warp[y1][x1] = 1;
			adj[y1][x1].pb({y2,x2,t});
		}
		
		for(int i=0; i<H; ++i) {
			for(int j=0; j<W; ++j) {
				if((i == H-1 && j == W-1) || grave[i][j] || warp[i][j]) continue;
				for(int d=0; d<4; ++d) {
					int nr = i + d4r[d];
					int nc = j + d4c[d];
					
					if(0<=nr&&nr<H && 0<=nc&&nc<W && !grave[nr][nc]) {
						adj[i][j].pb({nr,nc,1});
					}
				}
			}
		}
		
		if(!spfa()) {
			cout << "Never" << en;
		} else if(d[H-1][W-1] == LINF) {
			cout << "Impossible" << en;
		} else {
			cout << d[H-1][W-1] << en;
		}
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	while (T--) {
		sol();
	}

	return 0;
}
