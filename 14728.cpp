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

int N,T;
int dp[101][10001];
int t[101], s[101];

void sol() {
	for(int i=1;i<=N;++i) {
		for(int j=1;j<=T;++j) {
			if(j-t[i] >= 0) {
				dp[i][j] = max(dp[i-1][j], dp[i-1][j-t[i]] + s[i]);
			} else {
				dp[i][j] = dp[i-1][j];
			}
		}
	}

	cout << dp[N][T] << '\n';

	return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> T;
	for(int i=1;i<=N;++i) {
		cin >> t[i] >> s[i];
	}
	sol();

	return 0;
}