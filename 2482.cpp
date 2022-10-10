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

int N,K;
const int mod = 1e9 + 3;
int dp[1001][1001];

void sol() {
	for(int i=1;i<=N;++i) {
		dp[i][1] = i;
	}
	for(int i=4;i<=N;++i) {
		for(int j=2;j<=N/2;++j) {
			dp[i][j] = dp[i-2][j-1] % mod + dp[i-1][j] % mod;
		}
	}
	cout << dp[N][K] % mod << '\n';

	return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> K;
	sol();

	return 0;
}