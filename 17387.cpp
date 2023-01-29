#include <bits/stdc++.h>

#define vt vector
#define en '\n'
#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()

using namespace std;
int T = 1;

typedef struct Point_ {
	ll x,y;

	bool operator<=(const Point_ &p) {
		if(x == p.x) {
			return y <= p.y;
		}
		return x <= p.x;
	}
} Point;

int ccw(Point &a, Point &b, Point &c) {
	ll x = a.x*b.y + b.x*c.y + c.x*a.y - b.x*a.y - c.x*b.y - a.x*c.y;
	if(x > 0) return 1;
	else if(x == 0) return 0;
	else return -1;
}

void sol() {
	Point a,b,c,d;
	cin >> a.x >> a.y >> b.x >> b.y;
	cin >> c.x >> c.y >> d.x >> d.y;

	if(ccw(a,b,c) * ccw(a,b,d) <= 0 && ccw(c,d,a) * ccw(c,d,b) <= 0) {
		if(ccw(a,b,c) * ccw(a,b,d) == 0 && ccw(c,d,a) * ccw(c,d,b) == 0) {  // on a line
			if(b <= a) swap(a,b);
			if(d <= c) swap(c,d);

			if(a <= d && c <= b) {
				cout << 1 << en;
			} else {
				cout << 0 << en;
			}
		} else {
			cout << 1 << en;
		}
	} else {
		cout << 0 << en;
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	while(T--) {
		sol();
	}

	return 0;
}
