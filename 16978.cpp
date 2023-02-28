#include <bits/stdc++.h>

#define vt vector
#define en '\n'
#define ll long long
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
const int INF = 0x3f3f3f3f; const int mINF = 0xc0c0c0c0;
const ll LINF = 0x3f3f3f3f3f3f3f3f; const ll mLINF = 0xc0c0c0c0c0c0c0c0;
int T = 1;

struct Query {
	int k,l,r;
	int idx;

	bool operator<(const Query& a) {
		return k < a.k;
	}
};

const int mx = 1e5;
int N,M;
ll t[2*mx];
vt<Query> qr1, qr2;
vt<ll> ans;

void init() {
	for(int i=N-1; i>0; --i) t[i] = t[i<<1] + t[i<<1|1];
}

void update(int p, ll val) {
	for(t[p+=N]=val; p>1; p>>=1) t[p>>1] = t[p] + t[p^1];
}

ll qry(int l, int r) {
	ll res = 0;
	for(l+=N, r+=N; l<r; l>>=1, r>>=1) {
		if(l&1) res += t[l++];
		if(r&1) res += t[--r];
	}
	return res;
}

void sol() {
	cin >> N;
	for(int i=0; i<N; ++i) cin >> t[i+N];
	init();
	
	cin >> M;
	int x,k,l,r;
	int cnt = 0;
	for(int i=0; i<M; ++i) {
		cin >> x;
		if(x == 1) {
			cin >> k >> l;
			qr1.pb({k,l,-1,-1});
		} else {
			cin >> k >> l >> r;
			qr2.pb({k,l,r,cnt++});
		}
	}

	ans.resize(cnt);
	sort(all(qr2));

	k = 0;
	int i = 0;
	while(i < sz(qr2)) {
		auto q = qr2[i];
		if(q.k <= k) {
			ans[q.idx] = qry(q.l-1, q.r);
			i++;
		} else {
			auto p = qr1[k++];
			update(p.k-1, p.l);
		}
	}

	for(ll x : ans) cout << x << en;
	
	return;
}


int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);

	while(T--) {
		sol();
	}

   return 0;
}
