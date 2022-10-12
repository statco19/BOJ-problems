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
ll dp[31];
ll ans;

void sol() {
	if(N&1) {
		cout << 0 << '\n';
		return;
	}

	dp[0] = 1;
	dp[2] = 3;
	dp[4] = 11;
	for(int i=6;i<=N;i+=2) {
		dp[i] = dp[i-2] * dp[2];
		for(int j=i-4;j>0;j-=2) {
			dp[i] += dp[j] * 2;
		}
		dp[i] += 2;
	}
	ans = dp[N];
	cout << ans << '\n';

	return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	sol();

	return 0;
}