#include <bits/stdc++.h>

#define vt vector
#define en '\n'
#define ll long long
#define ld long double
#define pb push_back
#define pii pair<int,int>
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rev(c) (c).rbegin(), (c).rend()
#define mid (st+end)/2

using namespace std;
const int INF = 0x3f3f3f3f; const int mINF = 0xc0c0c0c0;
const ll LINF = 0x3f3f3f3f3f3f3f3f; const ll mLINF = 0xc0c0c0c0c0c0c0c0;
int T = 1;

const double eps = 1e-9;

inline int diff(double lhs, double rhs) {
	if (lhs - eps < rhs && rhs < lhs + eps) return 0;
	return (lhs < rhs) ? -1 : 1;
}

struct Point {
	// double x, y;
	ll x,y;
	int idx;
	bool operator==(const Point& rhs) const { 
		return diff(x, rhs.x) == 0 && diff(y, rhs.y) == 0;
  	}

  	Point operator+(const Point& rhs) const {
  		return Point{ x + rhs.x, y + rhs.y };
  	}

  	Point operator-(const Point& rhs) const {
  		return Point{ x - rhs.x, y - rhs.y };
  	}

	// Point operator*(double t) const {
	// 	return Point{ x * t, y * t }; 
	// }

	Point operator*(ll t) const {
		return Point{ x * t, y * t };
	}

	bool operator<=(const Point& rhs) {
		return (x==rhs.x) ? y <= rhs.y : x <= rhs.x;
	}
};

inline double inner(const Point& a, const Point& b) {
	return a.x * b.x + a.y * b.y;
}
inline double outer(const Point& a, const Point& b) {
	return a.x * b.y - a.y * b.x;
}
inline double dist(const Point& a, const Point& b) {
	return sqrt(inner(a - b, a - b));
}
inline int ccw(const Point& a, const Point& b, const Point& c) {
	return diff(outer(b - a, c - a), 0);
}

int N;
int b;
vt<Point> robots, shelters;
vt<Point> ans;

void dfs() {
	if(b == (1<<N)-1) {
		for(int i=0; i<N; ++i) {
			Point a = robots[i];
			Point b = ans[i];
			for(int j=i+1; j<N; ++j) {
				Point c = robots[j];
				Point d = ans[j];

				if(ccw(a,b,c) * ccw(a,b,d) <= 0 && ccw(c,d,a) * ccw(c,d,b) <= 0) {
					if(ccw(a,b,c) * ccw(a,b,d) == 0 && ccw(c,d,a) * ccw(c,d,b) == 0) {
						if(b <= a) swap(a,b);
						if(d <= c) swap(c,d);

						if(a <= d && c <= b) return;
					} else {
						return;
					}
				}
			}
		}

		for(auto& p : ans) {
			cout << p.idx << en;
		}
		exit(0);
	}

	for(int i=0; i<N; ++i) {
		if(b & (1<<i)) continue;

		b |= (1<<i);
		ans.emplace_back(shelters[i]);
		dfs();
		ans.pop_back();
		b &= ~(1<<i);
	}
	return;
}

void sol() {
	cin >> N;
	robots.resize(N);
	shelters.resize(N);
	for(int i=0; i<N; ++i) {
		auto& p = robots[i];
		cin >> p.x >> p.y;
		p.idx = i+1;
	}
	for(int i=0; i<N; ++i) {
		auto& p = shelters[i];
		cin >> p.x >> p.y;
		p.idx = i+1;
	}

	dfs();

	return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	while(T--) {
		sol();
	}

	return 0;
}