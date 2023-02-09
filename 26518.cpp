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

void sol() {
	ld b,c,a1,a2;
	cin >> b >> c >> a1 >> a2;

	ld a3 = 0.0;
	ld ans = 0.0;
	while(1) {
		a3 = b*a2 + c*a1;
		ld x = a3 / a2;
		if(abs(ans - x) * (ld)pow(10,9) < 1) {
			break;
		} else {
			ans = x;
			a1 = a2;
			a2 = a3;
		}
	}

	cout << fixed; cout.precision(9);
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