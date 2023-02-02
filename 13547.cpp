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

int N,M;
int k;
int check[1000001];

typedef struct query {
	int idx, s, e;

	bool operator<(const query &q) {
		if(s / k == q.s / k) {
			return e / k < q.e / k;
		}
		return s / k < q.s / k;
	}
} Query;

void sol() {
	cin >> N;
	k = sqrt(N);
	vt<int> v;
	vt<Query> qr;

	v.resize(N+1);
	for(int i=1; i<=N; ++i) cin >> v[i];

	cin >> M;
	qr.resize(M);
	int idx = 0;
	int s,e;
	for(auto &q : qr) {
		cin >> s >> e;
		q = {idx++, s, e};
	}

	sort(all(qr));

	vt<int> ans(M);
	int l = qr[0].s, r = qr[0].e;
	int cnt = 0;

	for(int i=l; i<=r; ++i)
		if(++check[v[i]] == 1) cnt++;

	ans[qr[0].idx] = cnt;

	for(int i=1; i<M; ++i) {
		idx = qr[i].idx;
		s = qr[i].s;
		e = qr[i].e;

		while(s < l)
			if(++check[v[--l]] == 1) cnt++;
		while(s > l)
			if(--check[v[l++]] == 0) cnt--;
		while(e < r)
			if(--check[v[r--]] == 0) cnt--;
		while(e > r)
			if(++check[v[++r]] == 1) cnt++;

		ans[idx] = cnt;
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
