#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define ioa insert_or_assign
#define umap unordered_map
#define prq priority_queue
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vint;
const int INF = 0x3f3f3f3f; const int mINF = 0xc0c0c0c0;
const ll LINF = 0x3f3f3f3f3f3f3f3f; const ll mLINF = 0xc0c0c0c0c0c0c0c0;

int N,M;
int A,B,C;
int cnt[501];
ll d[501];
bool inQueue[501];
queue<int> q;
vector<pii> adj[501];

void sol() {
	fill(d,d+501,LINF);
	d[1] = 0;
	q.push(1);  // dcurr, curr
	inQueue[1] = 1;

	while(!q.empty()) {
		int curr = q.front(); q.pop();
		inQueue[curr] = 0;
		if(++cnt[curr] >= N) {
			cout << "-1" << '\n';
			return;
		}

		for(int i=0;i<adj[curr].size();++i) {
			int next = adj[curr][i].first;
			int dist = adj[curr][i].second;
			
			if(d[next] > d[curr] + dist) {
				d[next] = d[curr] + dist;

				if(!inQueue[next]) {
					q.push(next);
					inQueue[next] = 1;
				}
			}
		}
	}

	for(int i=2;i<=N;++i) {
		int dist = d[i] != LINF ? d[i] : -1;
		cout << dist << '\n';
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	for(int i=0;i<M;++i) {
		cin >> A >> B >> C;
		adj[A].pb({B,C});
	}
	sol();

	return 0;
}