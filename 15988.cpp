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

const int mod = 1e9 + 9;
int n;
int dp[1000001];

void sol() {
	cin >> n;
	memset(dp,0,4*(n+1));
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	for(int i=3;i<=n;++i) {
		for(int j=i-3;j<i;++j) {
			dp[i] = dp[i] % mod + dp[j] % mod;
		}
	}
	cout << dp[n] % mod << '\n';

	return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	while(T--) {
		sol();
	}

	return 0;
}