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

int n,k;
int dp[10001];
int c[101];
int ans = INF;

void sol() {
	memset(dp,INF,sizeof(dp));
	dp[0] = 0;
	for(int i=1;i<=n;++i) {
		for(int j=c[i];j<=k;++j) {
			dp[j] = min(dp[j], dp[j-c[i]] + 1);
		}
	}
	ans = dp[k] == INF ? -1 : dp[k];
	cout << ans << '\n';

	return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;
	for(int i=1;i<=n;++i) {
		cin >> c[i];
	}
	sol();

	return 0;
}