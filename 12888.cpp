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
	int H;
	cin >> H;
	ll dp[61] = {0};
	dp[0] = 1; dp[1] = 1; dp[2] = 3;
	for(int i=3; i<=H; ++i) {
		dp[i] = dp[i-1] + 2*dp[i-2];
	}
	cout << dp[H] << en;

	return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	while(T--) {
		sol();
	}

	return 0;
}