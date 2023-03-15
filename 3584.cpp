#include <bits/stdc++.h>
#include <quadmath.h>

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

int mx = (int)ceil(log2(100001));
int parent[100001][(int)ceil(log2(100001))];
int depth[100001];
vt<int> adj[100001];
int N;

void dfs(int curr) {
	for(int next : adj[curr]) {
		if(depth[next] == -1) {
			parent[next][0] = curr;
			depth[next] = depth[curr] + 1;
			dfs(next);
		}
	}
	
	return;
}

void connect() {
	for(int k=1; k<mx; ++k) {
		for(int i=1; i<=N; ++i) {
			parent[i][k] = parent[parent[i][k-1]][k-1];
		}
	}
	return;
}

int lca(int u, int v) {
	if(depth[u] < depth[v]) {
		swap(u,v);
	}
	
	int diff = depth[u] - depth[v];
	
	int i = 0;
	while(diff) {
		if(diff & 1) {
			u = parent[u][i];
		}
		diff >>= 1;
		i++;
	}
	
	if(u != v) {
		for(int i=mx - 1; i>=0; --i) {
			if(parent[u][i] != -1 && parent[u][i] != parent[v][i]) {
				u = parent[u][i];
				v = parent[v][i];
			}
		}
		u = parent[u][0];
	}
	
	return u;
}

void sol() {
	cin >> N;
	mx = (int)ceil(log2(N));
	int u,v;
	for(int i=0; i<=N; ++i) adj[i].clear();
	memset(parent,0,sizeof(parent));
	memset(depth, -1, sizeof(depth));
	
	int inDegree[10001] = {0};
	for(int i=0; i<N-1; ++i) {
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
		inDegree[v]++;
	}
	int root = 1;
	for(int i=1; i<=N; ++i) {
		if(inDegree[i] == 0) {
			root = i;
		}
	}
	cin >> u >> v;
	depth[root] = 0;
	dfs(root);  // root
	connect();

	cout << lca(u,v) << en;

	return;
}


int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	while(T--) {
		sol();
	}

   return 0;
}