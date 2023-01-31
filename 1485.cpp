#include <bits/stdc++.h>

#define vt vector
#define en '\n'
#define ll long long
#define ld long double
#define pb push_back
#define all(x) (x).begin(), (x).end()

using namespace std;
const int INF = 0x3f3f3f3f; const int mINF = 0xc0c0c0c0;
const ll LINF = 0x3f3f3f3f3f3f3f3f; const ll mLINF = 0xc0c0c0c0c0c0c0c0;
int T = 1;

int N;

typedef struct point_ {
	int x,y;

	bool operator<(point_ &p) {
		return y == p.y ? x < p.x : y < p.y;
	}
} point;

void sol() {
	vt<point> v;
	int x,y;
	for(int i=0; i<4; ++i) {
		cin >> x >> y;
		v.pb({x,y});
	}

	sort(all(v));
	if(abs(v[0].y - v[2].y) == abs(v[1].y - v[3].y)
		&& abs(v[0].x - v[1].x) == abs(v[2].x - v[3].x)
		&& abs(v[0].y - v[2].y) == abs(v[2].x - v[3].x)
	) {
		ll a = 1LL * (v[3].x-v[0].x) * (v[3].x-v[0].x) + 1LL * (v[3].y-v[0].y) * (v[3].y-v[0].y);
		ll b = 1LL * (v[1].x-v[2].x) * (v[1].x-v[2].x) + 1LL * (v[1].y-v[2].y) * (v[1].y-v[2].y);
		if(a == b) cout << 1 << en;
		else cout << 0 << en;
	} else {
		cout << 0 << en;
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	while(T--) {
		sol();
	}

	return 0;
}
