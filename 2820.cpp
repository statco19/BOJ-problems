#include <bits/stdc++.h>

#define vt vector
#define en '\n'
#define ll long long
#define ld long double
#define pb push_back
#define pii pair<int,int>
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define mid (st+end)/2

using namespace std;
const int INF = 0x3f3f3f3f; const int mINF = 0xc0c0c0c0;
const ll LINF = 0x3f3f3f3f3f3f3f3f; const ll mLINF = 0xc0c0c0c0c0c0c0c0;
int T = 1;

int N,M;
vt<int> adj[500001];
ll ar[500001];
ll t[500002];
ll l[500001], r[500001];

void dfs(int x, ll &o) {
	l[x] = ++o;
	for(int next : adj[x]) {
		dfs(next, o);
	}
	r[x] = o;

	return;
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
	cin >> ar[1];

	ll x,y;
	for(int i=2; i<=N; ++i) {
		cin >> x >> y;
		ar[i] = x;
		adj[y].pb(i);
	}

	ll o = 0;
	dfs(1,o);

	for(int i=1; i<=N; ++i) {
		update(l[i], ar[i]);
		update(l[i]+1, -ar[i]);
	}

	char c;
	for(int i=0; i<M; ++i) {
		cin >> c;
		int a;
		ll x;
		if(c == 'p') {
			cin >> a >> x;
			update(l[a]+1, x);
			update(r[a]+1, -x);
		} else if(c == 'u') {
			cin >> a;
			cout << qry(l[a]) << en;
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