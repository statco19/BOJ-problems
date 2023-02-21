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

const int mod = 1e5+3;
const int mx = 5e5;
const int h = (int)ceil(log2(mx));
int N,Q;
ll f[h+1][mod], g[h+1][mod];
ll tf[mx+1], tg[mx+1];
ll a[mx+1];

void update_f(int p, ll val) {
	while(p<=N) {
		tf[p] += val;
		p += p & -p;
	}
}

void update_g(int p, ll val) {
	while(p<=N) {
		tg[p] += val;
		p += p & -p;
	}
}

ll qry_f(int p) {
	ll res = 0;
	while(p>0) {
		res += tf[p];
		p -= p & -p;
	}
	return res;
}

ll qry_g(int p) {
	ll res = 0;
	while(p>0) {
		res += tg[p];
		p -= p & -p;
	}
	return res;
}

void sol() {
	cin >> N >> Q;
	for(int i=1; i<=N; ++i) {
		cin >> a[i];
	}
	for(int j=0; j<mod; ++j) {
		f[0][j] = (2LL*j*j-1+mod) % mod;
		g[0][j] = (4LL*j*j-3+mod)*j % mod;
	}
	for(int i=1; i<=h; ++i) {
		for(int j=0; j<mod; ++j) {
			f[i][j] = f[i-1][f[i-1][j]];
		}
	}
	for(int i=1; i<=h; ++i) {
		for(int j=1; j<mod; ++j) {
			g[i][j] = g[i-1][g[i-1][j]];
		}
	}

	ll t,l,r;
	for(int i=0; i<Q; ++i) {
		cin >> t;
		if(t == 1) {
			cin >> l >> r;
			update_f(l,1);
			update_f(r+1,-1);
		} else if(t == 2) {
			cin >> l >> r;
			update_g(l,1);
			update_g(r+1,-1);
		} else {
			cin >> l;
			ll p = qry_f(l);
			ll q = qry_g(l);

			ll x = a[l];
			int idx = 0;
			while(q) {
				if(q & 1) {
					x = g[idx][x];
				}
				q >>= 1;
				idx++;
			}
			idx = 0;
			while(p) {
				if(p & 1) {
					x = f[idx][x];
				}
				p >>= 1;
				idx++;
			}

			cout << x << en;
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