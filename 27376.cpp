#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define vt vector
#define ll long long
#define pb push_back
#define ioa insert_or_assign
#define umap unordered_map
#define prq priority_queue
#define F first
#define S second
#define all(c) (c).begin(), (c).end()
#define rev(c) (c).rbegin(), (c).rend()
#define sz(x) (int)(x).size()
#define mset(ar, val) memset(ar, val, sizeof(ar))
#define en "\n"

const int d4r[4] = {-1,0,1,0}; const int d4c[4] = {0,1,0,-1};
const int d8r[8] = {-1,-1,0,1,1,1,0,-1}; const int d8c[8] = {0,1,1,1,0,-1,-1,-1};
const int INF = 0x3f3f3f3f; const int mINF = 0xc0c0c0c0;
const ll LINF = 0x3f3f3f3f3f3f3f3f; const ll mLINF = 0xc0c0c0c0c0c0c0c0;
int T = 1;

typedef struct light {
	ll x,t,s;

	bool operator<(const light &l) {
		return x < l.x;
	}
} Light;

ll n,k;
ll dist;
ll ans;

void sol() {
	cin >> n >> k;
	vt<Light> v(k);
	ll x,t,s;
	for(int i=0; i<k; ++i) {
		cin >> x >> t >> s;
		v[i] = {x,t,s};
	}
	sort(all(v));

	for(int i=0; i<k; ++i) {
		ans += v[i].x - dist;
		dist += v[i].x - dist;

		if(ans < v[i].s) {
			ans += (v[i].s - ans);
		} else {
			ll q = (ans - v[i].s) / v[i].t;
			if(q % 2 == 1) {
				ans += (q+1)*v[i].t - (ans - v[i].s);
			} 
		}
	}
	if(dist < n) {
		ans += n-dist;
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