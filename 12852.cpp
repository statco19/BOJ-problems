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

int N;
int dp[1000001];
vint v;

void sol() {
	cin >> N;
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;

	for(int i=4;i<=N;++i) {
		if(i % 3 == 0 && i % 2 == 0) {
			dp[i] = min({dp[i/3], dp[i/2], dp[i-1]}) + 1;
		} else if(i % 3 == 0) {
			dp[i] = min(dp[i/3], dp[i-1]) + 1;
		} else if(i % 2 == 0) {
			dp[i] = min(dp[i/2], dp[i-1]) + 1;
		} else {
			dp[i] = dp[i-1] + 1;
		}
	}
	cout << dp[N] << '\n';

	int cnt = INF;
	int i = N;
	while(i>0) {
		if(dp[i] < cnt) {
			v.pb(i);
			cnt = dp[i];
			if(i % 3 == 0 && i % 2 == 0) {
				if(dp[i/3] == cnt-1) {
					i /= 3;
				} else if(dp[i/2] == cnt-1) {
					i /= 2;
				} else {
					i--;
				}
			} else if(i % 3 == 0) {
				if(dp[i/3] == cnt-1) {
					i /= 3;
				} else {
					i--;
				}
			} else if(i % 2 == 0) {
				if(dp[i/2] == cnt-1) {
					i /= 2;
				} else {
					i--;
				}
			} else {
				i--;
			}
		}
		else {
			i--;
		}
	}

	for(int i=0; i<v.size(); ++i) {
		cout << v[i] << ' ';
	}
	cout << '\n';

	return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	while(T--) {
		sol();
	}

	return 0;
}