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
int arr[1001];
int dp[1001];
vint v;
int ans;

void sol() {
	fill(dp,dp+N+1,1);
	for(int i=2;i<=N;++i) {
		for(int j=1;j<i;++j) {
			if(arr[j] < arr[i]) {
				dp[i] = max(dp[j]+1, dp[i]);
			}
		}
	}
	ans = *max_element(dp,dp+N+1);
	int idx = INF;
	for(int i=N;i>0;--i) {
		if(dp[i] == ans) {
			idx = i;
			v.pb(arr[idx]);
			break;
		}
	}

	int cnt = dp[idx];
	int i = idx-1;
	while(cnt > 1 && i > 0) {
		if(dp[i] == cnt-1) {
			v.pb(arr[i]);
			cnt--;
		}
		i--;
	}
	vint rev(v.rbegin(), v.rend());
	cout << ans << '\n';
	for(int x : rev) cout << x << " ";
	cout << '\n';

	return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	for(int i=1;i<=N;++i) {
		cin >> arr[i];
	}
	sol();

	return 0;
}