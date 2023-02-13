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

const int mx = 1e5;
int N;
int L,R;
ll t[100002];

void update(int p, ll val) {
	while(p <= mx) {
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
	cin >> N;

	ll flower;
	for(int i=0; i<N; ++i) {
		flower = 0;
		cin >> L >> R;
		ll left = qry(L);
		ll right = qry(R);

		if(left > 0) {
			flower += left;
			update(L, -left);
			update(L+1, left);
		}
		if(right > 0) {
			flower += right;
			update(R, -right);
			update(R+1, right);
		}

		if(L+1 < R) {
			update(L+1, 1);
			update(R, -1);
		}
		cout << flower << en;
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