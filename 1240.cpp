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

int N,M;
vt<pii> adj[1001];
bool vis[1001];

void sol() {
	cin >> N >> M;
	for(int i=0,a,b,x; i<N-1; ++i) {
		cin >> a >> b >> x;
		adj[a].pb({b,x});
		adj[b].pb({a,x});
	}

	int a,b;
	while(M--) {
		cin >> a >> b;
		mset(vis,0);
		queue<pii> q;
		q.push({a,0});
		vis[a] = 1;
		while(!q.empty()) {
			auto p = q.front(); q.pop();

			if(p.first == b) {
				cout << p.second << en;
				break;
			}

			for(int i=0; i<sz(adj[p.first]); ++i) {
				auto r = adj[p.first][i];
				if(!vis[r.first]) {
					vis[r.first] = 1;
					q.push({r.first, p.second+r.second});
				}
			}
		}
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