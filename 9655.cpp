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
int dp[1001];  // 0: sk, 1: cy

void sol() {
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 0;

	for(int i=4;i<=N;++i) {
		if(!dp[i-1] && !dp[i-3]) {  
			// dp[i-1] == 0 : take 1, start == winner && dp[i-3] == 0 : take 3, start == winner
			dp[i] = 1;
		} else {
			dp[i] = 0;
		}
	}
	if(!dp[N]) cout << "SK" << '\n';
	else cout << "CY" << '\n';

	return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	sol();

	return 0;
}