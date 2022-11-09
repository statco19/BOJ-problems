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

int N,M;
int before[31][31], after[31][31];
bool v[31][31];

void bfs(int r, int c) {
	int from = before[r][c];
	int to = after[r][c];
	queue<pii> q;
	q.push({r,c});
	v[r][c] = 1;

	while(!q.empty()) {
		pii p = q.front(); q.pop();
		r = p.first;
		c = p.second;
		before[r][c] = to;

		// cout << "r: " << r << ", c: " << c << en;

		int nr,nc;
		for(int d=0; d<4; ++d) {
			nr = r + d4r[d];
			nc = c + d4c[d];

			if(1<=nr&&nr<=N && 1<=nc&&nc<=M && !v[nr][nc] && before[nr][nc] == from) {
				// cout << "nr: " << nr << ", nc: " << nc << en;
				v[nr][nc] = 1;
				q.push({nr,nc});
			}
		}
	}

	return;
}

void sol() {
	cin >> N >> M;
	for(int i=1; i<=N; ++i) {
		for(int j=1; j<=M; ++j) {
			cin >> before[i][j];
		}
	}
	for(int i=1; i<=N; ++i) {
		for(int j=1; j<=M; ++j) {
			cin >> after[i][j];	
		}
	}

	bool diff = 0;
	for(int i=1; i<=N; ++i) {
		for(int j=1; j<=M; ++j) {
			if(!v[i][j]) {
				if(before[i][j] != after[i][j]) {
					if(!diff) {
						diff = 1;
						bfs(i,j);


						// for(int i=1; i<=N; ++i) {
						// 	for(int j=1; j<=M; ++j) {
						// 		cout << before[i][j] << ' ';
						// 	}
						// 	cout << en;
						// }
						// cout << en;
					} else {
						cout << "NO" << en;
						return;
					}
				}
			}
		}
	}
	for(int i=1; i<=N; ++i) {
		for(int j=1; j<=M; ++j) {
			if(before[i][j] != after[i][j]) {
				cout << "NO" << en;
				return;
			}
		}
	}
	cout << "YES" << en;

	return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	while(T--) {
		sol();
	}

	return 0;
}