#include <bits/stdc++.h>

#define vt vector
#define en '\n'
#define ll long long
#define ld long double
#define pb push_back
#define pii pair<int,int>
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rev(c) (c).rbegin(), (c).rend()
#define mid (st+end)/2

using namespace std;
const int INF = 0x3f3f3f3f; const int mINF = 0xc0c0c0c0;
const ll LINF = 0x3f3f3f3f3f3f3f3f; const ll mLINF = 0xc0c0c0c0c0c0c0c0;
int T = 1;

int N,M;
ll t[100001];
int l[100001], r[100001];
vt<int> adj[100001];

void dfs(int x, int &o) {
	l[x] = ++o;
	for(int next : adj[x]) {
		dfs(next, o);
	}
	r[x] = o;
}

void update(int p, ll val) {
	while(p <= N) {
		t[p] += val;
		p += p & -p;
	}
}

ll qry(int p) {
	ll res = 0;
	while(p > 0) {
		res += t[p];
		p -= p & -p;
	}
	return res;
}

void sol() {
	cin >> N >> M;
	int x;
	for(int i=1; i<=N; ++i) {
		cin >> x;
		if(x == -1) continue;
		adj[x].pb(i);
	}
	int o = 0;
	dfs(1,o);

	ll y,z;
	for(int i=0; i<M; ++i) {
		cin >> x;
		if(x == 1) {
			cin >> y >> z;
			update(l[y], z);
			update(r[y]+1, -z);
		} else {
			cin >> y;
			cout << qry(l[y]) << en;
		}
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	while(T--) {
		sol();
	}

	return 0;
}