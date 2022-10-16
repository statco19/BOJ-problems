#include <bits/stdc++.h>

#define vt vector
#define ll long long
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define ioa insert_or_assign
#define umap unordered_map
#define prq priority_queue
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vint;
const int d4r[4] = {-1,0,1,0}; const int d4c[4] = {0,1,0,-1};
const int d8r[8] = {-1,-1,0,1,1,1,0,-1}; const int d8c[8] = {0,1,1,1,0,-1,-1,-1};
const int INF = 0x3f3f3f3f; const int mINF = 0xc0c0c0c0;
const ll LINF = 0x3f3f3f3f3f3f3f3f; const ll mLINF = 0xc0c0c0c0c0c0c0c0;
int T = 1;

int V,E;
int a,b,c;
vt<pii> adj[10001];
bool vi[10001];
prq<pii> pq;
int ans;

void sol() {
	cin >> V >> E;
	for(int i=0;i<E;++i) {
		cin >> a >> b >> c;
		adj[a].pb({b,c});
		adj[b].pb({a,c});
	}

	pq.push({0,1});
	while(!pq.empty()) {
		pii p = pq.top(); pq.pop();
		int dist = -p.first;
		int curr = p.second;

		if(!vi[curr]) {
			vi[curr] = 1;
			ans += dist;
			for(int i=0; i<sz(adj[curr]); ++i) {
				pq.push({-(adj[curr][i].second), adj[curr][i].first});
			}
		}
	}

	cout << ans << '\n';

	return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	while(T--) {
		sol();
	}

	return 0;
}