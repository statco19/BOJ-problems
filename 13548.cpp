#include <bits/stdc++.h>

#define vt vector
#define en '\n'
#define ll long long
#define ld long double
#define pb push_back
#define pii pair<int,int>
#define sz(x) (x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;
const int INF = 0x3f3f3f3f; const int mINF = 0xc0c0c0c0;
const ll LINF = 0x3f3f3f3f3f3f3f3f; const ll mLINF = 0xc0c0c0c0c0c0c0c0;
int T = 1;

const int mx = 1e5;
int N,M,k;
typedef struct query {
	int idx, s, e;

	bool operator<(const query &q) {
		return s / k == q.s / k ? e / k < q.e / k : s / k < q.s / k;
	}
} Query;

vt<int> v;
vt<Query> qr;
vt<int> ans;
int t[2*mx];

void init() {
	for(int i=mx-1; i>0; --i) t[i] = max(t[i<<1], t[i<<1|1]);
}

void update(int p, int val) {
	for(t[p+=mx]+=val; p>1; p>>=1) t[p>>1] = max(t[p], t[p^1]);
}

int qry(int l, int r) {
	int res = mINF;
	for(l+=mx, r+=mx; l<r; l>>=1, r>>=1) {
		if(l&1) {
			int tmp = t[l++];
			res = max(res, tmp);
		}
		if(r&1) {
			int tmp = t[--r];
			res = max(res, tmp);
		}
	}
	return res;
}

void sol() {
	cin >> N;
	k = sqrt(N);
	v.resize(N+1);

	for(int i=1; i<=N; ++i)
		cin >> v[i];

	cin >> M;
	qr.resize(M);
	ans.resize(M);
	int idx = 0;
	for(int i=0; i<M; ++i) {
		auto &q = qr[i];
		q.idx = idx++;
		cin >> q.s >> q.e;
	}

	sort(all(qr));

	int l = qr[0].s, r = qr[0].e;
	for(int i=l; i<=r; ++i) {
		t[v[i]-1+mx]++;
	}
	init();
	ans[qr[0].idx] = qry(0,mx);

	int s,e;
	for(int i=1; i<M; ++i) {
		s = qr[i].s;
		e = qr[i].e;

		vt<pii> revised;
		while(s < l) {
			--l;
			revised.pb({v[l],1});
		}
		while(s > l) {
			revised.pb({v[l],-1});
			l++;
		}
		while(e < r) {
			revised.pb({v[r],-1});
			r--;
		}
		while(e > r) {
			++r;
			revised.pb({v[r],1});
		}

		for(pii p : revised) {
			update(p.first-1, p.second);  // sqrt(N) * lgN
		}
		ans[qr[i].idx] = qry(0,mx);
	}

	for(int x : ans) cout << x << en;

	return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	while(T--) {
		sol();
	}

	return 0;
}
