#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define ioa insert_or_assign
#define umap unordered_map
#define prq priority_queue
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vint;
const int di4[4] = {-1,0,1,0}; const int dj4[4] = {0,1,0,-1};
const int di8[8] = {-1,-1,0,1,1,1,0,-1}; const int dj8[8] = {0,1,1,1,0,-1,-1,-1};
const int INF = 0x3f3f3f3f; const int mINF = 0xc0c0c0c0;
const ll LINF = 0x3f3f3f3f3f3f3f3f; const ll mLINF = 0xc0c0c0c0c0c0c0c0;
int T = 1;

int N;
int arr[501][501];
int dp[501][501];
int ans;

int dfs(int r, int c) {
	if(dp[r][c]) return dp[r][c];

	int cnt = 1;
	for(int d=0;d<4;++d) {
		int tmp = 1;
		int nr = r + di4[d];
		int nc = c + dj4[d];

		if(1<=nr&&nr<=N
			&& 1<=nc&&nc<=N
			&& arr[r][c] < arr[nr][nc]) {
			tmp = max(tmp, dfs(nr,nc)) + 1;
		}

		cnt = max(cnt, tmp);
	}
	dp[r][c] = cnt;

	return cnt;
}

void sol() {
	cin >> N;
	for(int i=1;i<=N;++i) {
		for(int j=1;j<=N;++j) {
			cin >> arr[i][j];
		}
	}

	for(int i=1;i<=N;++i) {
		for(int j=1;j<=N;++j) {
			dfs(i,j);
		}
	}
	
	for(int i=1;i<=N;++i) {
		for(int j=1;j<=N;++j) {
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans << '\n';

	return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	while(T--) {
		sol();
	}

	return 0;
}