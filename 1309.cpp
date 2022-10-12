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
int dp[100001][3];
const int mod = 9901;

void sol() {
	dp[1][0] = dp[1][1] = dp[1][2] = 1;
	for(int i=2;i<=N;++i) {
		dp[i][0] = dp[i-1][0] % mod + dp[i-1][1] % mod + dp[i-1][2] % mod;
		dp[i][1] = dp[i-1][0] % mod + dp[i-1][2] % mod;
		dp[i][2] = dp[i-1][0] % mod + dp[i-1][1] % mod;
	}
	
	int ans = (dp[N][0] % mod + dp[N][1] % mod + dp[N][2] % mod) % mod;
	cout << ans << '\n'; 

	return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	sol();

	return 0;
}