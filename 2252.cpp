#include <bits/stdc++.h>

#define vt vector
#define ll long long
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define rev(c) (c).rbegin(), (c).rend()
#define sz(x) (int)(x).size()
#define ioa insert_or_assign
#define umap unordered_map
#define prq priority_queue
using namespace std;
typedef pair<int,int> pii;
const int d4r[4] = {-1,0,1,0}; const int d4c[4] = {0,1,0,-1};
const int d8r[8] = {-1,-1,0,1,1,1,0,-1}; const int d8c[8] = {0,1,1,1,0,-1,-1,-1};
const int INF = 0x3f3f3f3f; const int mINF = 0xc0c0c0c0;
const ll LINF = 0x3f3f3f3f3f3f3f3f; const ll mLINF = 0xc0c0c0c0c0c0c0c0;
int T = 1;

int N,M;
int inDegree[32001];
int dp[32001];
vt<int> adj[32001];
vt<int> group[32001];
queue<int> q;

void sol() {
	cin >> N >> M;
	memset(dp,mINF,sizeof(dp));
	int a,b;
	for(int i=0; i<M; ++i) {
		cin >> a >> b;
		adj[a].pb(b);
		inDegree[b]++;
	}

	for(int i=1;i<=N;++i) {
		if(inDegree[i] == 0) {
			dp[i] = 0;
			q.push(i);
		}
	}

	while(!q.empty()) {
		int size = q.size();
		for(int i=0; i<size; ++i) {
			int node = q.front(); q.pop();
			cout << node << ' ';

			for(auto v : adj[node]) {
				if(--inDegree[v] == 0) {
					q.push(v);
				}
			}
		}
	}
	cout << '\n';

	return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	while(T--) {
		sol();
	}

	return 0;
}