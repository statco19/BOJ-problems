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

const int mod = 1e9 + 7;
typedef struct term {
	ll coef, power;

	bool operator<(const term &t) {
		return power < t.power;
	}
} Term;

ll myPower(ll x, ll p) {
	if(p == 0) return 1;

	ll y = myPower(x, p/2) % mod;
	if(p & 1) {
		return (x % mod) * (y % mod) * (y % mod);
	} else {
		return (y % mod) * (y % mod);
	}
}

void sol() {
	int N;
	cin >> N;
	vt<Term> v(N);
	for(auto &t : v) {
		cin >> t.coef >> t.power;
	}
	sort(all(v));

	vt<Term> u(N);
	for(int i=0; i<N; ++i) {
		u[i].coef = v[i].coef * v[i].power;
		u[i].power = max(0LL, v[i].power - 1);
	}

	ll sum = 0;
	for(int i=0; i<N; ++i) {
		sum = sum % mod + ((u[i].coef % mod) * (myPower(2, u[i].power) % mod)) % mod;
	}

	cout << sum % mod << en;

	return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	while(T--) {
		sol();
	}

	return 0;
}