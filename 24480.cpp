#include <bits/stdc++.h>

#define vt vector
#define en '\n'
#define ll long long
#define ull unsigned long long
#define ld long double
#define ioa insert_or_assign
#define umap unordered_map
#define prq priority_queue
#define pb push_back
#define pii pair<int,int>
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rev(c) (c).rbegin(), (c).rend()
#define mset(ar, val) memset(ar, val, sizeof(ar))

using namespace std;
const int d4r[4] = {-1,0,1,0}; const int d4c[4] = {0,1,0,-1};
const int d8r[8] = {-1,-1,0,1,1,1,0,-1}; const int d8c[8] = {0,1,1,1,0,-1,-1,-1};
const int INF = 0x3f3f3f3f; const int mINF = 0xc0c0c0c0;
const ll LINF = 0x3f3f3f3f3f3f3f3f; const ll mLINF = 0xc0c0c0c0c0c0c0c0;
int T = 1;

int n,m,r;
vt<int> adj[100001];
bool vis[100001];
int num[100001];
int cnt;

void dfs(int curr) {
	num[curr] = ++cnt;
	vis[curr] = 1;
	for(int i=0; i<sz(adj[curr]); ++i) {
		int next = adj[curr][i];
		if(!vis[next]) {
			dfs(next);
		}
	}
}

void sol() {
	cin >> n >> m >> r;
	for(int i=0,u,v; i<m; ++i) {
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	for(int i=1; i<=n; ++i) sort(rev(adj[i]));
	dfs(r);
	for(int i=1; i<=n; ++i) {
		cout << num[i] << en;
	}

	return;
}


int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);

	while(T--) {
		sol();
	}

   return 0;
}