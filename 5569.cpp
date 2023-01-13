#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define vt vector
#define ll long long
#define pb push_back
#define ioa insert_or_assign
#define umap unordered_map
#define prq priority_queue
#define F first
#define S second
#define all(c) (c).begin(), (c).end()
#define rev(c) (c).rbegin(), (c).rend()
#define sz(x) (int)(x).size()
#define mset(ar, val) memset(ar, val, sizeof(ar))
#define en "\n"

const int d4r[4] = {-1,0,1,0}; const int d4c[4] = {0,1,0,-1};
const int d8r[8] = {-1,-1,0,1,1,1,0,-1}; const int d8c[8] = {0,1,1,1,0,-1,-1,-1};
const int INF = 0x3f3f3f3f; const int mINF = 0xc0c0c0c0;
const ll LINF = 0x3f3f3f3f3f3f3f3f; const ll mLINF = 0xc0c0c0c0c0c0c0c0;
int T = 1;

const int mod = 1e5;
int w,h;
int dp[101][101][2][2];  // {w,h,dir,turn}

void sol() {
	cin >> w >> h;
	for(int i=2; i<=w; ++i) dp[i][1][0][0] = 1;
	for(int j=2; j<=h; ++j) dp[1][j][1][0] = 1;

	for(int i=2; i<=w; ++i) {
		for(int j=2; j<=h; ++j) {
			dp[i][j][0][0] = (dp[i-1][j][0][0] + dp[i-1][j][0][1]) % mod;
			dp[i][j][0][1] = dp[i-1][j][1][0];
			dp[i][j][1][0] = (dp[i][j-1][1][0] + dp[i][j-1][1][1]) % mod;
			dp[i][j][1][1] = dp[i][j-1][0][0];
		}
	}

	int ans = dp[w][h][0][0] + dp[w][h][0][1] + dp[w][h][1][0] + dp[w][h][1][1];
	cout << ans % mod << en;

	return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	while(T--) {
		sol();
	}

	return 0;
}
