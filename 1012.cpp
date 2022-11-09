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

int N,M,K;
int bd[51][51];
bool v[51][51];
int ans;

void sol() {
	cin >> M >> N >> K;
	memset(bd,0,sizeof(bd));
	memset(v,0,sizeof(v));
	ans = 0;
	int r,c;
	for(int i=0; i<K; ++i) {
		cin >> c >> r;
		bd[r][c] = 1;	
	}

	for(int i=0; i<N; ++i) {
		for(int j=0; j<M; ++j) {
			if(bd[i][j] && !v[i][j]) {
				queue<pii> q;
				q.push({i,j});
				v[i][j] = 1;
				ans++;

				while(!q.empty()) {
					pii p = q.front(); q.pop();
					r = p.first;
					c = p.second;

					int nr,nc;
					for(int d=0; d<4; ++d) {
						nr = r + d4r[d];
						nc = c + d4c[d];
						if(0<=nr&&nr<N && 0<=nc&&nc<M && bd[nr][nc] && !v[nr][nc]) {
							v[nr][nc] = 1;
							q.push({nr,nc});
						}
					}
				}
			}
		}
	}

	cout << ans << en;

	return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	while(T--) {
		sol();
	}

	return 0;
}