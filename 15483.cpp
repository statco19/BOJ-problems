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
int T = 1;

string s,t;
int dp[1001][1001];

void sol() {
	cin >> s >> t;
	for(int i=0;i<=s.size();++i) {
		dp[i][t.size()] = s.size() - i;
	}
	for(int j=0;j<=t.size();++j) {
		dp[s.size()][j] = t.size() - j;
	}

	for(int i=s.size()-1; ~i; --i) {
		for(int j=t.size()-1; ~j; --j) {
			if(s[i] ^ t[j]) {
				dp[i][j] = min({dp[i][j+1], dp[i+1][j], dp[i+1][j+1]}) + 1;
			} else {
				dp[i][j] = dp[i+1][j+1];  // no edit
			}
		}
	}
	cout << dp[0][0] << '\n';

	return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	while(T--) {
		sol();
	}

	return 0;
}