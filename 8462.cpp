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

int n,t,k;
typedef struct query {
	int idx, s, e;

	bool operator<(const query &q) {
		return s/k == q.s/k ? e/k < q.e/k : s/k < q.s/k;
	}
} Query;

ll cnt[1000001];
vt<ll> v;
vt<Query> qr;
vt<ll> ans;

void sol() {
	cin >> n >> t;
	v.resize(n+1);
	k = sqrt(n);
	for(int i=1; i<=n; ++i)
		cin >> v[i];

	qr.resize(t);
	ans.resize(t);
	int idx=0, s,e;
	for(int i=0; i<t; ++i) {
		qr[i].idx = idx++;
		cin >> qr[i].s >> qr[i].e;
	}
	sort(all(qr));

	ll power = 0;
	int l = qr[0].s, r = qr[0].e;
	for(int i=l; i<=r; ++i) {
		cnt[v[i]]++;
	}

	for(int i=1; i<=1000000; ++i) {
		if(cnt[i]) {
			power += cnt[i] * cnt[i] * i;
		}
	}
	ans[qr[0].idx] = power;

	for(int i=1; i<t; ++i) {
		s = qr[i].s;
		e = qr[i].e;

		while(s < l) {
			ll num = v[l-1];
			ll oldCnt = cnt[num];
			cnt[num]++;
			ll newCnt = cnt[num];
			l--;

			power += (newCnt * newCnt - oldCnt * oldCnt) * num;
		}
		while(s > l) {
			ll num = v[l];
			ll oldCnt = cnt[num];
			cnt[num]--;
			ll newCnt = cnt[num];
			l++;

			power += (newCnt * newCnt - oldCnt * oldCnt) * num;
		}
		while(e < r) {
			ll num = v[r];
			ll oldCnt = cnt[num];
			cnt[num]--;
			ll newCnt = cnt[num];
			r--;

			power += (newCnt * newCnt - oldCnt * oldCnt) * num;
		}
		while(e > r) {
			ll num = v[r+1];
			ll oldCnt = cnt[num];
			cnt[num]++;
			ll newCnt = cnt[num];
			r++;

			power += (newCnt * newCnt - oldCnt * oldCnt) * num;
		}

		ans[qr[i].idx] = power;
	}

	for(ll x : ans) cout << x << en;

	return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	while(T--) {
		sol();
	}

	return 0;
}
