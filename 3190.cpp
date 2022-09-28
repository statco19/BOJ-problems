#include <bits/stdc++.h>

#define ll long long
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vint;
const int INF = 0x3f3f3f3f; const int mINF = 0xc0c0c0c0;
const ll LINF = 0x3f3f3f3f3f3f3f3f; const ll mLINF = 0xc0c0c0c0c0c0c0c0;

int N,K,L;
int ans;
int bd[101][101];
int vi[101][101];
int dr[4] = {-1,0,1,0}, dc[4] = {0,1,0,-1};
int d = 1;  // right
int R = 1, C = 1;
deque<pii> dq;
queue<pair<int,char>> q;

void sol() {
	vi[1][1] = 1;
	dq.push_front({1,1});
	int nr,nc;
	while(1) {
		ans++;

		nr = R + dr[d];
		nc = C + dc[d];

		if(!(1<=nr&&nr<=N && 1<=nc&&nc<=N && !vi[nr][nc])) {
			break;
		}

		dq.push_front({nr,nc});
		if(bd[nr][nc]) {  // eat an apple
			bd[nr][nc] = 0;
		} else {
			if(!dq.empty()) {
				pii p = dq.back(); dq.pop_back();
				vi[p.first][p.second] = 0;
			}
		}
		vi[nr][nc] = 1;

		if(!q.empty() && ans == q.front().first) {
			pair<int,char> p = q.front(); q.pop();
			char c = p.second;

			if(c == 'L') {
				d = (d+3) % 4;
			} else if(c == 'D') {
				d = (d+1) % 4;
			}
		}
		R = nr, C = nc;
	}

	return;
}
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	cin >> K;
	int r,c;
	for(int i=0;i<K;++i) {
		cin >> r >> c;
		bd[r][c] = 1;
	}

	cin >> L;

	int sec;
	char dir;
	for(int i=0;i<L;++i) {
		cin >> sec >> dir;
		q.push({sec,dir});
	}

	sol();
	cout << ans << '\n';
	return 0;
}
