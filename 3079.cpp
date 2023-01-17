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

void sol() {
	int N,M;
	cin >> N >> M;
	vt<ll> v(N);
	for(ll &x : v) cin >> x;
		
	ll ans = *max_element(all(v)) * M;
	ll l=0, r=*max_element(all(v)) * M;
	while(l+1 < r) {
		ll mid = (l+r) / 2;
		
		ll cnt = 0;
		for(ll x : v) {
			cnt += mid / x;
		}
		
		if(cnt >= M) {
			r = mid;
			ans = min(ans,r);
		} else {
			l = mid;
		}
	}

	cout << ans << en;

	return;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	while (T--) {
		sol();
	}

	return 0;
}
