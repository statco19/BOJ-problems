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
int cnt;
bool vis[100001];
int seq[100001];
vt<int> adj[100001];

void sol() {
	cin >> n >> m >> r;
	for(int i=0,u,v; i<m; ++i) {
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	for(int i=1; i<=n; ++i) {
		sort(all(adj[i]));
	}

	queue<int> q;
	q.push(r);
	vis[r] = 1;
	while(!q.empty()) {
		int k = q.front(); q.pop();
		seq[k] = ++cnt;

		for(int i=0; i<sz(adj[k]); ++i) {
			int next = adj[k][i];
			if(!vis[next]) {
				vis[next] = 1;
				q.push(next);
			}
		}
	}

	for(int i=1; i<=n; ++i) cout << seq[i] << en;

	return;
}


int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);

	while(T--) {
		sol();
	}

   return 0;
}