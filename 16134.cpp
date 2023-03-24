#include <bits/stdc++.h>

#define vt vector
#define en '\n'
#define ll long long
#define ull unsigned long long
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
const int d4r[4] = {-1,0,1,0}; const int d4c[4] = {0,1,0,-1};
const int d8r[8] = {-1,-1,0,1,1,1,0,-1}; const int d8c[8] = {0,1,1,1,0,-1,-1,-1};
const int INF = 0x3f3f3f3f; const int mINF = 0xc0c0c0c0;
const ll LINF = 0x3f3f3f3f3f3f3f3f; const ll mLINF = 0xc0c0c0c0c0c0c0c0;
int T = 1;

const int mod = 1e9+7;
int N,R;
ll pow(ll x, ll n, ll r) {
	ll res = 1;
	while(n) {
		if(n&1) res = (res * x) % r;
		x = (x * x) % r;
		n >>= 1;
	}

	return res;
}
ll fac[1000001], fac_inv[1000001];
inline ll C(int a, int b) { return (fac[a] * fac_inv[a - b] % mod) * fac_inv[b] % mod; }

void sol() {
	cin >> N >> R;
	fac[0] = 1;
	for(int i=1; i<=N; ++i) {
		fac[i] = fac[i-1] * i % mod;
	}
	fac_inv[N] = pow(fac[N], mod-2, mod);
	for(int i=N; i>0; --i) {
		fac_inv[i-1] = fac_inv[i] * i % mod;
	}

	cout << C(N,R) << en;

	return;
}


int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);

	while(T--) {
		sol();
	}

   return 0;
}