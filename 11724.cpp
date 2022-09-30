#include <bits/stdc++.h>

#define ll long long
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vint;
const int INF = 0x3f3f3f3f; const int mINF = 0xc0c0c0c0;
const ll LINF = 0x3f3f3f3f3f3f3f3f; const ll mLINF = 0xc0c0c0c0c0c0c0c0;

int ans;
int N,M;
vint adj[1001];
int vi[1001];

void bfs(int st) {
	queue<int> q;
	q.push(st);
	vi[st] = 1;

	while(!q.empty()) {
		int curr = q.front(); q.pop();
		for(int i=0;i<adj[curr].size();++i) {
			int next = adj[curr][i];
			if(!vi[next]) {
				q.push(next);
				vi[next] = 1;
			}
		}
	}
	return;
}

void sol() {
	for(int i=1;i<=N;++i) {
		if(adj[i].size() > 0 && !vi[i]) {
			bfs(i);
			ans++;
		}
	}
	for(int i=1;i<=N;++i) {
		if(adj[i].size() == 0 && !vi[i]) {
			ans++;
		}
	}

	return;
}
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	int u,v;
	for(int i=0;i<M;++i) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);	
	}
	sol();
	cout << ans << '\n';

	return 0;
}
