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

void sol() {
	int N;
	cin >> N;
	int sx,sy,ex,ey;
	cin >> sx >> sy >> ex >> ey;

	ll dist = LINF;
	int idx = 0;
	for(int i=0; i<N; ++i) {
		int M;
		cin >> M;
		ll sum = 0;
		int r = sx, c = sy;
		int x,y;
		for(int j=0; j<M; ++j) {
			cin >> x >> y;
			sum += (ll)abs(r-x) + abs(c-y);
			r = x; c = y;
		}
		sum += (ll)abs(r-ex) + abs(c-ey);
		if(sum < dist) {
			dist = sum;
			idx = i+1;
		}
	}
	cout << idx << en;

	return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	while(T--) {
		sol();
	}

	return 0;
}
