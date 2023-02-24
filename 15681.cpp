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

vt<int> adj[100001];
int dp[100001];
bool vis[100001];

void dfs(int root) {
	for(int i=0; i<sz(adj[root]); ++i) {
		int next = adj[root][i];
		if(!vis[next]) {
			vis[next] = 1;
			dfs(next);
			dp[root] += dp[next];
		}
	}

	dp[root]++;
	return;
}

void sol() {
	int N,R,Q;
	cin >> N >> R >> Q;
	int a,b;
	for(int i=0; i<N-1; ++i) {
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	vis[R] = 1;
	dfs(R);
	int x;
	for(int i=0; i<Q; ++i) {
		cin >> x;
		cout << dp[x] << en;
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	while(T--) {
		sol();
	}

	return 0;
}