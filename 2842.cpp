#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <unordered_map>

#define ll long long
#define vt vector
#define pii pair<int,int>
#define en "\n"
#define pb push_back
#define sz(x) (x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

const int INF = 0x3f3f3f3f; const int mINF = 0xc0c0c0c0;
int d8r[8] = {-1,-1,0,1,1,1,0,-1}; int d8c[8] = {0,1,1,1,0,-1,-1,-1};

int T = 1;

char bd[51][51];
int el[51][51];
bool vis[51][51];
unordered_map<int,int> um;
vt<int> h;
int k;
int N;
int ans = INF;
int sr,sc;

bool bfs(int l, int h) {
	if(!(l<=el[sr][sc]&&el[sr][sc]<=h)) return 0;
	queue<pii> q;
	memset(vis, 0, sizeof(vis));
	q.push({sr,sc});
	vis[sr][sc] = 1;
	int cnt = 0;

	while(!q.empty()) {
		pii p = q.front(); q.pop();
		int r = p.first;
		int c = p.second;

		if(bd[r][c] == 'K') {
			if(++cnt == k) {
				return 1;
			}
		}

		for(int d=0; d<8; ++d) {
			int nr = r + d8r[d];
			int nc = c + d8c[d];

			if(1<=nr&&nr<=N && 1<=nc&&nc<=N && !vis[nr][nc] && l<=el[nr][nc]&&el[nr][nc]<=h) {
				vis[nr][nc] = 1;
				q.push({nr,nc});
			}
		}
	}

	return 0;
}

void sol() {
	cin >> N;
	for(int i=1; i<=N; ++i) {
		string s;
		cin >> s;
		for(int j=1;j <=N; ++j) {
			bd[i][j] = s[j-1];
			if(bd[i][j] == 'P') {
				sr = i;
				sc = j;
			}
			if(bd[i][j] == 'K') {
				k++;
			}
		}
	}
	for(int i=1; i<=N; ++i) {
		for(int j=1;j <=N; ++j) {
			cin >> el[i][j];
			if(um.find(el[i][j]) == um.end()) {
				um[el[i][j]]++;
				h.pb(el[i][j]);
			}
		}
	}
	sort(all(h));

	int l = 0, r = 0;
	while(r < sz(h)) {
		if(bfs(h[l],h[r])) {
			ans = min(ans, h[r] - h[l]);
			l++;
		} else {
			r++;
		}
	}

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