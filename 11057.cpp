#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define ioa insert_or_assign
#define umap unordered_map
#define prq priority_queue
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vint;
const int INF = 0x3f3f3f3f; const int mINF = 0xc0c0c0c0;
const ll LINF = 0x3f3f3f3f3f3f3f3f; const ll mLINF = 0xc0c0c0c0c0c0c0c0;

int N;
int dp[1002][12];
int ans;
const int mod = 10007;

void sol() {
	int cnt = 0;
	for(int j=1;j<=10;++j) {
		dp[1][j] = 1;
		cnt += dp[1][j];
	}
	dp[1+1][1] = cnt;

	for(int i=2;i<=N;++i) {
		cnt = dp[i][1] % mod;
		for(int j=2;j<=10;++j) {
			dp[i][j] = dp[i][j-1] % mod - dp[i-1][j-1] % mod;
			cnt += dp[i][j] % mod + mod;
		}
		dp[i+1][1] = cnt % mod;
	}
	ans = dp[N+1][1];
	cout << ans << '\n';

	return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	sol();

	return 0;
}