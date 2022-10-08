#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define ioa insert_or_assign
#define umap unordered_map
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vint;
const int INF = 0x3f3f3f3f; const int mINF = 0xc0c0c0c0;
const ll LINF = 0x3f3f3f3f3f3f3f3f; const ll mLINF = 0xc0c0c0c0c0c0c0c0;

int N;
int dp[1000001];

void sol() {
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;
	for(int i=4;i<=N;++i) {
		if(i % 3 == 0 && i % 2 == 0) {
			dp[i] = min({dp[i-1], dp[i/2], dp[i/3]}) + 1;
		} else if(i % 3 == 0) {
			dp[i] = min(dp[i-1], dp[i/3]) + 1;
		} else if(i % 2 == 0) {
			dp[i] = min(dp[i-1], dp[i/2]) + 1;
		} else {
			dp[i] = dp[i-1] + 1;
		}
	}
	cout << dp[N] << '\n';

	return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	sol();

	return 0;
}