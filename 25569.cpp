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

const int mod = 1e9+7;
int N;
vt<int> v,m;
ll fac[600001], fac_inv[300001];

ll pow(ll x, ll n, ll r) {
	ll res = 1;
	while(n) {
		if(n&1) res = (res * x) % r;
		x = (x * x) % r;
		n >>= 1;
	}

	return res;
}

void sol() {
	cin >> N;
	v.resize(N+1);
	m.resize(N+1);
	int A,B;
	for(int i=1; i<=N; ++i) {
		cin >> A >> B;
		v[i] = A+B;
		m[i] = min(A,B);
	}

	fac[0] = 1;
	for(int i=1; i<=600000; ++i) {
		fac[i] = fac[i-1] * i % mod;
	}
	fac_inv[300000] = pow(fac[300000], mod-2, mod);
	for(int i=300000; i>0; --i) {
		fac_inv[i-1] = fac_inv[i] * i % mod;
	}

	ll ans = 1;
	for(int i=1; i<=N; ++i) {
		ll x = ((fac[v[i]] * fac_inv[m[i]]) % mod * fac_inv[v[i]-m[i]] - 1) % mod;
		ans = ans * x % mod;
	}
	cout << ans << en;

	return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	while(T--) {
		sol();
	}

	return 0;
}