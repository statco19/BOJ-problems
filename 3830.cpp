#include <bits/stdc++.h>

#define ll long long
#define vt vector
#define pii pair<int,int>
#define en "\n"
#define pb push_back
#define sz(x) (x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;
int T = 1;

const int d4r[4] = {-1,0,1,0}; const int d4c[4] = {0,1,0,-1};
const int d8r[8] = {-1,-1,0,1,1,1,0,-1}; const int d8c[8] = {0,1,1,1,0,-1,-1,-1};
const int INF = 0x3f3f3f3f; const int mINF = 0xc0c0c0c0;
const ll LINF = 0x3f3f3f3f3f3f3f3f; const ll mLINF = 0xc0c0c0c0c0c0c0c0;

int parent[100001];
ll dist[100001];
bool check[100001];
vt<pair<ll,ll>> adj[100001];
vt<pair<ll,ll>> qry;

int getParent(int x) {
	if(parent[x] == x) return x;
	return parent[x] = getParent(parent[x]);
}

void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if(a < b) parent[b] = a;
	else parent[a] = b;
	return;
}

int findParent(int a, int b) {
	return getParent(a) == getParent(b);
}

void dfs(int idx, ll val) {
	check[idx] = 1;
	dist[idx] = val;

	for(pii p : adj[idx]) {
		int next = p.first;
		if(!check[next]) {
			check[next] = 1;
			dfs(next, val + p.second);
		}
	}
}

void init() {
	memset(dist, 0, sizeof(dist));
	memset(check, 0, sizeof(check));
	for(int i=0; i<100001; ++i) {
		parent[i] = i;
		adj[i] = vt<pair<ll,ll>> ();
	}
	qry.clear();
}

void sol() {
	int N,M;
	
	while(1) {
		cin >> N >> M;
		if(N == 0 && M == 0) break;
		
		init();
		for(int i=0; i<M; ++i) {
			char c;
			int a,b,w;
			cin >> c;
			
			if(c == '!') {
				cin >> a >> b >> w;
				unionParent(a,b);
				adj[a].pb({b,w});
				adj[b].pb({a,-w});
			} else {
				cin >> a >> b;
				if(findParent(a,b)) {
					qry.pb({a,b});
				} else {
					qry.pb({-1,-1});
				}	
			}
		}

		for(int i=1; i<=N; ++i) {
			if(!check[i]) dfs(i,0);
		}

		for(int i=0; i<sz(qry); ++i) {
			int a = qry[i].first;
			int b = qry[i].second;
			if(a == -1 && b == -1) {
				cout << "UNKNOWN" << en;
			} else {
				cout << dist[b] - dist[a] << en;
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