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

int N,M;
int parent[51];
umap<int,int> u;

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

	if(u.find(x) != u.end()) {
		parent[y] = x;
	} else if(u.find(y) != u.end()) {
		parent[x] = y;
	} else {
		if(x < y) parent[y] = x;
		else parent[x] = y;
	}
}

bool isUnion(int x, int y) {
	x = find(x);
	y = find(y);

	return x == y;
}

void sol() {
	cin >> N >> M;
	int x; cin >> x;

	for(int i=1; i<=N; ++i) parent[i] = i;

	for(int i=0,k; i<x; ++i) {
		cin >> k;
		u[k]++;
	}

	vt<vt<int>> v;
	for(int i=0,k; i<M; ++i) {
		cin >> k;
		vt<int> a;

		int prev;
		for(int j=0,p; j<k; ++j) {
			cin >> p;

			if(j > 0) {
				merge(prev, p);
			}
			prev = p;
			a.pb(p);
		}

		v.pb(a);
	}

	int ans = 0;
	for(int i=0; i<M; ++i) {
		bool err = 0;
		for(int j=0; j<sz(v[i]); ++j) {
			if(u.find(find(v[i][j])) != u.end()) {
				err = 1;
				break;
			}
		}

		if(!err) {
			ans++;
		}
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