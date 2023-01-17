#include <bits/stdc++.h>

#define ll long long
#define vt vector
#define en '\n'
#define pb push_back
#define pii pair<int,int>
#define prq priority_queue
#define sz(x) (x).size()
#define all(x) (x).begin(), (x).end()
#define rev(x) (x).rbegin(), (x).rend()

using namespace std;

const int INF = 0x3f3f3f3f; const int mINF = 0xc0c0c0c0;
const ll LINF = 0x3f3f3f3f3f3f3f3f; const ll mLINF = 0xc0c0c0c0c0c0c0c0;
const int d4r[4] = { -1,0,1,0 }; const int d4c[4] = { 0,1,0,-1 };
int T = 1;

ll myPow(int x, int p, int mod) {
	ll res = 1;
	for(int i=1; i<=p; ++i) {
		res = ((ll)res % mod) * ((ll)x % mod);
	}
	return res;
}

void sol() {
	int L;
	string s;
	cin >> L >> s;
	int r = 31;
	int mod = 1234567891;

	ll sum = 0;
	for(int i=0; i<L; ++i) {
		sum = (sum % mod) + ((s[i] - 'a' + 1) * (myPow(r,i,mod) % mod)) % mod;
	}
	cout << sum % mod << en;

	return;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	while (T--) {
		sol();
	}

	return 0;
}
