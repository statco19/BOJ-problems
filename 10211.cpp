#include <bits/stdc++.h>

#define ll long long
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vint;
const int INF = 0x3f3f3f3f; const int mINF = 0xc0c0c0c0;
const ll LINF = 0x3f3f3f3f3f3f3f3f; const ll mLINF = 0xc0c0c0c0c0c0c0c0;

int ans;
int T,N;
int arr[1001];
int dp[1001];

void sol() {
	dp[1] = arr[1];
	for(int i=2;i<=N;++i) {
		dp[i] = max(dp[i-1]+arr[i], arr[i]);
	}
	ans = *max_element(dp,dp+(N+1));
	cout << ans << '\n';
}
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	while(T--) {
		cin >> N;
		memset(arr,0,sizeof(arr));
		memset(dp, mINF,sizeof(dp));
		for(int i=1;i<=N;++i) {
			cin >> arr[i];
		}
		sol();
	}

	return 0;
}
