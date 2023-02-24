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

int dp[100001];
vt<int> adj[100001];
bool vis[100001];

void dfs(int curr, int sum) {
	dp[curr] += sum;
	for(int i=0; i<sz(adj[curr]); ++i) {
		int next = adj[curr][i];
		if(!vis[next]) {
			vis[next] = 1;
			dfs(next, dp[curr]);
		}
	}
	return;
}

void sol() {
	int n,m;
	cin >> n >> m;
	
	int x;
	for(int i=1; i<=n; ++i) {
		cin >> x;
		if(x == -1) continue;
		adj[i].pb(x);
		adj[x].pb(i);
	}

	int i,w;
	for(int j=0; j<m; ++j) {
		cin >> i >> w;
		dp[i] += w;
	}

	vis[1] = 1;
	dfs(1, 0);
	for(int i=1; i<=n; ++i) cout << dp[i] << ' ';
	cout << en;

	return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	while(T--) {
		sol();
	}

	return 0;
}