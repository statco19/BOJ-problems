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

int n;
int dp[1001];
const int mod = 10007;

void sol() {
	dp[1] = 1;
	dp[2] = 3;
	for(int i=3;i<=n;++i) {
		dp[i] = dp[i-1] % mod + 2 * (dp[i-2] % mod);
	}
	cout << dp[n] % mod << '\n';
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	sol();

	return 0;
}