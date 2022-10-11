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

int T,n;
int dp[12];

void sol() {
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	for(int i=4;i<=n;++i) {
		dp[i] = dp[i-3] + dp[i-2] + dp[i-1];
	}
	cout << dp[n] << '\n';

	return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	while(T--) {
		cin >> n;
		memset(dp,0,sizeof(dp));
		sol();
	}

	return 0;
}