#include <bits/stdc++.h>
#include <quadmath.h>

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

int N;
int parent[300001];
int cnt[300001];

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
	cin >> N;
	for(int i=1;i<=N;++i) {
		parent[i] = i;
	}

	for(int i=0,u,v; i<N-2; ++i) {
		cin >> u >> v;
		merge(u,v);
	}

	for(int i=1; i<=N; ++i) {
		if(parent[i] == i) cout << i << ' ';
	}
	cout << en;

	return;
}


int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);

	while(T--) {
		sol();
	}

   return 0;
}