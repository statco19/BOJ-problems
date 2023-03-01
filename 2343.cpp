#include <bits/stdc++.h>

#define vt vector
#define en '\n'
#define ll long long
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
const int INF = 0x3f3f3f3f; const int mINF = 0xc0c0c0c0;
const ll LINF = 0x3f3f3f3f3f3f3f3f; const ll mLINF = 0xc0c0c0c0c0c0c0c0;
int T = 1;


void sol() {
	int N,M;
	cin >> N >> M;
	ll ans = LINF;
	vt<ll> v(N+1);
	for(int i=1; i<=N; ++i) cin >> v[i];

	ll l = 0, r = 1e9;
	while(l+1 < r) {
		ll mid = (l+r)/2;

		ll cnt = 0;
		ll sum = 0;
		for(int i=1; i<=N; ++i) {
			if(v[i] > mid) {
				cnt = INF;
				break;
			}
			if(sum + v[i] <= mid) {
				sum += v[i];
			} else {
				cnt++;
				sum = v[i];
			}
		}
		if(sum) cnt++;

		if(cnt <= M) {
			ans = min(ans, mid);
			r = mid;
		} else {
			l = mid;
		}
	}
	if(ans == LINF) ans = min(ans, r);

	cout << ans << en;

	return;
}


int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);

	while(T--) {
		sol();
	}

   return 0;
}