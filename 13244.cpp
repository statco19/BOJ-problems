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

int parent[1001];

int find(int x) {
	if(parent[x] == x) {
		return x;
	}

	return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
	x = find(x);
	y = find(y);

	if(x == y) return;

	if(x < y) parent[y] = x;
	else parent[x] = y;
}

bool isUnion(int x, int y) {
	x = find(x);
	y = find(y);

	return x == y;
}

void sol() {
	bool conn[1001][1001] = {0};
	int N,M;
	cin >> N >> M;
	for(int i=1; i<=N; ++i) parent[i] = i;
	int u,v;
	bool isGraph = 0;
	while(M--) {
		cin >> u >> v;
		if(!conn[u][v] && !conn[v][u]) {
			conn[u][v] = 1;
			conn[v][u] = 1;
			if(isUnion(u,v)) {
				isGraph = 1;
			} else {
				merge(u,v);
			}
		} else {
			isGraph = 1;
		}
	}
	for(int i=1; i<=N; ++i) {
		find(i);
		if(parent[i] != 1) {
			isGraph = 1;
			break;
		}
	}

	if(isGraph) cout << "graph" << en;
	else cout << "tree" << en;

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