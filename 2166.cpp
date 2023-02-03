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

typedef struct point {
	double x,y;

} Point;

double ccw(Point &a, Point &b, Point &c) {
	return a.x*b.y + b.x*c.y + c.x*a.y - b.x*a.y - c.x*b.y - a.x*c.y;
}

int N;
vt<Point> coords;

void sol() {
	cin >> N;
	coords.resize(N);
	for(auto &p : coords) {
		cin >> p.x >> p.y;
	}

	double area = 0.0;
	for(int i=1; i<N-1; ++i) {
		area += 0.5 * ccw(coords[0], coords[i], coords[i+1]);

	}

	cout<<fixed;
	cout.precision(1);
	cout << round(abs(area) * 10) / 10.0 << en;

	return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	while(T--) {
		sol();
	}

	return 0;
}
