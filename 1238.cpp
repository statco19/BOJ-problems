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

vt<pii> adj[2][1001];
int d[2][1001];
int N,M,X;
int ans = mINF;

void dijkstra(int k) {
	prq<pii> pq;
	pq.push({0,X});
	d[k][X] = 0;

	while(!pq.empty()) {
		pii p = pq.top(); pq.pop();
		int cost = -p.first;
		int curr = p.second;

		if(d[k][curr] < cost) continue;
		for(int i=0; i<sz(adj[k][curr]); ++i) {
			int nCost = adj[k][curr][i].second;
			int next = adj[k][curr][i].first;

			if(d[k][next] > cost + nCost) {
				d[k][next] = cost + nCost;
				pq.push({-d[k][next], next});
			}
		}
	}

	return;
}

void sol() {
	mset(d, INF);
	cin >> N >> M >> X;
	for(int i=0,a,b,c; i<M; ++i) {
		cin >> a >> b >> c;
		adj[0][a].pb({b,c});
		adj[1][b].pb({a,c});  // reverse
	}

	dijkstra(1);
	dijkstra(0);

	for(int i=1; i<=N; ++i) {
		ans = max(ans, d[1][i] + d[0][i]);
	}
	cout << ans << en;

	return;
}


int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	while(T--) {
		sol();
	}

   return 0;
}