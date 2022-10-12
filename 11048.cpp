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

int N,M;
int dp[1001][1001], arr[1001][1001];

void sol() {
	for(int i=1;i<=N;++i) {
		for(int j=1;j<=M;++j) {
			dp[i][j] = max({dp[i-1][j], dp[i-1][j-1], dp[i][j-1]}) + arr[i][j];
		}
	}
	cout << dp[N][M] << '\n';

	return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	for(int i=1;i<=N;++i) {
		for(int j=1;j<=M;++j) {
			cin >> arr[i][j];
		}
	}
	sol();

	return 0;
}