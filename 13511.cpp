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

const int mx = 1e5;
const int h = (int)ceil(log2(mx));
int N,M;
int depth[mx+1];
int parent[h+1][mx+1];
ll d[h+1][mx+1];
vt<pair<int,ll>> adj[mx+1];

void dfs(int curr) {
	for(int i=0; i<sz(adj[curr]); ++i) {
		int next = adj[curr][i].first;
		ll dist = adj[curr][i].second;
		if(depth[next] == -1) {
			parent[0][next] = curr;
			d[0][next] = dist;
			depth[next] = depth[curr] + 1;
			dfs(next);
		}
	}
	return;
}

void connect() {
	for(int i=1; i<=h; ++i) {
		for(int j=1; j<=N; ++j) {
			parent[i][j] = parent[i-1][parent[i-1][j]];
			d[i][j] = d[i-1][j] + d[i-1][parent[i-1][j]];
		}
	}
}

int lca(int u, int v) {
	if(depth[u] < depth[v]) swap(u,v);
	int diff = depth[u] - depth[v];

	int i=0;
	while(diff) {
		if(diff & 1) {
			u = parent[i][u];
		}
		diff >>= 1;
		i++;
	}

	if(u != v) {
		for(int i=h-1; i>=0; --i) {
			if(parent[i][u] != -1 && parent[i][u] != parent[i][v]) {
				u = parent[i][u];
				v = parent[i][v];
			}
		}
		u = parent[0][u];
	}
	
	return u;
}

void getKthNode(int u, int du, int v, int dv, int k) {
	if(k-1 <= du) {
		k--;
		int j = 0;
		while(k) {
			if(k & 1) {
				u = parent[j][u];
			}
			k >>= 1;
			j++;
		}

		cout << u << en;
	} else {
		k = dv - (k-1-du);
		int j = 0;
		while(k) {
			if(k & 1) {
				v = parent[j][v];
			}
			k >>= 1;
			j++;
		}

		cout << v << en;
	}
	return;
}

void sol() {
	cin >> N;
	memset(depth, -1, sizeof(depth));
	int u,v;
	ll dist;
	for(int i=0; i<N-1; ++i) {
		cin >> u >> v >> dist;
		adj[u].pb({v,dist});
		adj[v].pb({u,dist});
	}

	depth[1] = 0;
	dfs(1);
	connect();

	cin >> M;
	int x,k;
	for(int i=0; i<M; ++i) {
		cin >> x >> u >> v;
		if(x == 1) {
			int LCA = lca(u,v);
			int du = depth[u] - depth[LCA];
			int dv = depth[v] - depth[LCA];

			ll a = 0, b = 0;
			int j=0;
			while(du) {
				if(du & 1) {
					a += d[j][u];
					u = parent[j][u];
				}
				du >>= 1;
				j++;
			}

			j=0;
			while(dv) {
				if(dv & 1) {
					b += d[j][v];
					v = parent[j][v];	
				}
				dv >>= 1;
				j++;
			}

			cout << a + b << en;
		} else {
			cin >> k;
			bool swapped = 0;
			if(depth[u] < depth[v]) {
				swap(u,v);
				swapped = 1;
			}
			if(k == 1) {
				if(!swapped) cout << u << en;
				else cout << v << en;
				continue;
			}
			
			int LCA = lca(u,v);
			int du = depth[u] - depth[LCA];
			int dv = depth[v] - depth[LCA];

			if(k-1 == du + dv) {
				if(!swapped) cout << v << en;
				else cout << u << en;
				continue;
			}

			if(!swapped) {
				getKthNode(u, du, v, dv, k);
			} else {
				getKthNode(v, dv, u, du, k);
			}
		}
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