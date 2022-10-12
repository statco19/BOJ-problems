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

const int mod = 1e9;
int N,K;
int dp[201][201];

void sol() {
	for(int i=0;i<=N;++i) {
		dp[i][1] = 1;
		dp[i][2] = i+1;
	}
	for(int j=1;j<=K;++j) {
		dp[0][j] = 1;
	}

	for(int i=1;i<=N;++i) {
		for(int j=3;j<=K;++j) {
			for(int l=0;l<=i;++l) {
				dp[i][j] = dp[i][j] % mod + dp[l][j-1] % mod;
			}
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