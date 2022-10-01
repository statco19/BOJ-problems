#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define ioa insert_or_assign
#define umap unordered_map
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vint;
const int INF = 0x3f3f3f3f; const int mINF = 0xc0c0c0c0;
const ll LINF = 0x3f3f3f3f3f3f3f3f; const ll mLINF = 0xc0c0c0c0c0c0c0c0;

int n,m;
int s,e;
int ans;
vint adj[101];
int vi[101];
bool found = 0;

void bfs(int a, int b) {
	queue<int> q;
	q.push(a);
	vi[a] = 1;

	while(!q.empty()) {
		int size = q.size();
		for(int k=0;k<size;++k) {
			int curr = q.front(); q.pop();
			if(curr == b) {
				found = 1;
				return;
			}

			for(int i=0;i<adj[curr].size();++i) {
				int next = adj[curr][i];
				if(!vi[next]) {
					q.push(next);
					vi[next] = 1;
				}
			}
		}
		ans++;
	}
	return;
}

void sol() {
	cin >> m;
	int x,y;
	for(int i=0;i<m;++i) {
		cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	bfs(s,e);
	if(!found) ans = -1;

	return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	cin >> s >> e;

	sol();
	cout << ans << '\n';

	return 0;
}
