#include <bits/stdc++.h>

#define vt vector
#define en '\n'
#define ll long long
#define ld long double
#define pb push_back
#define pii pair<int,int>
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rev(c) (c).rbegin(), (c).rend()
#define mid (st+end)/2

using namespace std;
const int INF = 0x3f3f3f3f; const int mINF = 0xc0c0c0c0;
const ll LINF = 0x3f3f3f3f3f3f3f3f; const ll mLINF = 0xc0c0c0c0c0c0c0c0;
int T = 1;


void sol() {
	int N;
	cin >> N;
	int a[1001], dp[1001];
	memset(a,0,sizeof(a));
	memset(dp,INF,sizeof(dp));
	dp[0] = 0; dp[1] = 0;
	for(int i=1; i<=N; ++i) cin >> a[i];
	for(int i=1; i<=N; ++i) {
		for(int j=i+1; j<=i+a[i]; ++j) {
			if(j > N) break;
			dp[j] = min(dp[j], dp[i]+1);
		}
	}

	if(dp[N] == INF) cout << -1 << en;
	else cout << dp[N] << en;

	return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	while(T--) {
		sol();
	}

	return 0;
}