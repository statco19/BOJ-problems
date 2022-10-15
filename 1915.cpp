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

int n,m;
int arr[1001][1001];
int dp[1001][1001];
int ans;

void sol() {
	scanf("%d %d", &n, &m);
	for(int i=1;i<=n;++i) {
		for(int j=1;j<=m;++j) {
			scanf("%1d", &arr[i][j]);
			if(arr[i][j]) dp[i][j] = 1;
		}
	}

	for(int i=1;i<=n;++i) {
		for(int j=1;j<=m;++j) {
			if(dp[i][j] && dp[i][j-1] && dp[i-1][j] && dp[i-1][j-1]) {
				dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
			}
		}
	}

	for(int i=1;i<=n;++i) {
		for(int j=1;j<=m;++j) {
			printf("%d ", dp[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	for(int i=1;i<=n;++i) {
		for(int j=1;j<=m;++j) {
			ans = max(ans, dp[i][j]);
		}
	}
	printf("%d\n", ans*ans);

	return;
}

int main() {
	// ios_base::sync_with_stdio(0); cin.tie(0);

	while(T--) {
		sol();
	}

	return 0;
}