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

int N,M,K;
ll ar[1000001];
ll t[1000001];

void update(int p, ll val) {
	while(p<=N) {
		t[p] += val;
		p += p & -p;
	}
}

ll qry(int p) {
	ll res = 0;
	while(p>0) {
		res += t[p];
		p -= p & -p;
	}
	return res;
}

void sol() {
	cin >> N >> M >> K;
	ll x;
	for(int i=1; i<=N; ++i) {
		cin >> ar[i];
		update(i,ar[i]);
	}

	int a,b;
	ll c;
	for(int i=0; i<M+K; ++i) {
		cin >> a >> b >> c;
		if(a == 1) {
			update(b,c-ar[b]);
			ar[b] = c;
		} else {
			cout << qry(c) - qry(b-1) << en;
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
