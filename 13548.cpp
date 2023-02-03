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
int ccnt[100001];
int cnt[100001];
int mx;

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

	ccnt[0] = N;
	int l = qr[0].s, r = qr[0].e;
	for(int i=l; i<=r; ++i) {
		ccnt[cnt[v[i]]]--;
		cnt[v[i]]++;
		ccnt[cnt[v[i]]]++;
		mx = max(mx, cnt[v[i]]);
	}
	ans[qr[0].idx] = mx;

	int s,e;
	for(int i=1; i<M; ++i) {
		s = qr[i].s;
		e = qr[i].e;

		while(s < l) {
			l--;
			ccnt[cnt[v[l]]]--;
			cnt[v[l]]++;
			ccnt[cnt[v[l]]]++;
			mx = max(mx, cnt[v[l]]);
		}
		while(s > l) {
			ccnt[cnt[v[l]]]--;
			cnt[v[l]]--;
			ccnt[cnt[v[l]]]++;
			l++;
			if(ccnt[mx] == 0) mx--;
		}
		while(e < r) {
			ccnt[cnt[v[r]]]--;
			cnt[v[r]]--;
			ccnt[cnt[v[r]]]++;
			r--;
			if(ccnt[mx] == 0) mx--;
		}
		while(e > r) {
			r++;
			ccnt[cnt[v[r]]]--;
			cnt[v[r]]++;
			ccnt[cnt[v[r]]]++;
			mx = max(mx, cnt[v[r]]);
		}

		ans[qr[i].idx] = mx;
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
