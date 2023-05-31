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

char bd[102][102];
bool vis[102][102];
int N;
int a1,a2;

void bfs1(int r, int c, char ch) {
	queue<pii> q;
	q.push({r,c});
	int nr,nc;
	while(!q.empty()) {
		pii p = q.front(); q.pop();
		r = p.first;
		c = p.second;

		for(int d=0; d<4; ++d) {
			nr = r + d4r[d];
			nc = c + d4c[d];
			if(1<=nr&&nr<=N && 1<=nc&&nc<=N && !vis[nr][nc] && bd[nr][nc] == ch) {
				q.push({nr,nc});
				vis[nr][nc] = 1;
			}
		}
	}
}

void bfs2(int r, int c, char ch) {
	queue<pii> q;
	q.push({r,c});
	int nr,nc;
	while(!q.empty()) {
		pii p = q.front(); q.pop();
		r = p.first;
		c = p.second;

		for(int d=0; d<4; ++d) {
			nr = r + d4r[d];
			nc = c + d4c[d];
			if(1<=nr&&nr<=N && 1<=nc&&nc<=N && !vis[nr][nc]) {
				if(ch == 'R' || ch == 'G') {
					if(bd[nr][nc] == 'R' || bd[nr][nc] == 'G') {
						q.push({nr,nc});
						vis[nr][nc] = 1;
					}
				} else {
					if(bd[nr][nc] == ch) {
						q.push({nr,nc});
						vis[nr][nc] = 1;
					}
				}
				
			}
		}
	}
}

void sol() {
	scanf("%d", &N);
	for(int i=1; i<=N; ++i) {
		for(int j=1; j<=N; ++j) {
			scanf(" %c", &bd[i][j]);
		}
	}

	for(int i=1; i<=N; ++i) {
		for(int j=1; j<=N; ++j) {
			if(!vis[i][j]) {
				a1++;
				vis[i][j] = 1;
				bfs1(i,j,bd[i][j]);
			}
		}
	}

	mset(vis,0);
	for(int i=1; i<=N; ++i) {
		for(int j=1; j<=N; ++j) {
			if(!vis[i][j]) {
				a2++;
				vis[i][j] = 1;
				bfs2(i,j,bd[i][j]);
			}
		}
	}

	printf("%d %d\n", a1, a2);

	return;
}


int main(){
	// ios_base::sync_with_stdio(0); cin.tie(0);

	while(T--) {
		sol();
	}

   return 0;
}