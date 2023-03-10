#include <bits/stdc++.h>
#include <quadmath.h>

#define vt vector
#define en '\n'
#define ll long long
#define ull unsigned long long
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
const int d4r[4] = {-1,0,1,0}; const int d4c[4] = {0,1,0,-1};
const int d8r[8] = {-1,-1,0,1,1,1,0,-1}; const int d8c[8] = {0,1,1,1,0,-1,-1,-1};
const int INF = 0x3f3f3f3f; const int mINF = 0xc0c0c0c0;
const ll LINF = 0x3f3f3f3f3f3f3f3f; const ll mLINF = 0xc0c0c0c0c0c0c0c0;
int T = 1;

const double eps = 1e-9;

inline int diff(double lhs, double rhs) {
	if (lhs - eps < rhs && rhs < lhs + eps) return 0;
	return (lhs < rhs) ? -1 : 1;
}

struct Point {
	ll x,y;
	bool operator==(const Point& rhs) const { 
		return diff(x, rhs.x) == 0 && diff(y, rhs.y) == 0;
  	}

  	Point operator+(const Point& rhs) const {
  		return Point{ x + rhs.x, y + rhs.y };
  	}

  	Point operator-(const Point& rhs) const {
  		return Point{ x - rhs.x, y - rhs.y };
  	}

	Point operator*(ll t) const {
		return Point{ x * t, y * t };
	}
};

inline double outer(const Point& a, const Point& b) {
	return a.x * b.y - a.y * b.x;
}
inline int ccw(const Point& a, const Point& b, const Point& c) {
	return diff(outer(b - a, c - a), 0);
}

void antipodal_pairs(vector<Point>& pt) {
	// calculate convex hull
	sort(pt.begin(), pt.end(), [](const Point& a, const Point& b) {
		return (a.x == b.x) ? a.y < b.y : a.x < b.x;
	});

	vector<Point> up, lo;
	for (const auto& p : pt) {
		while (up.size() >= 2 && ccw(*++up.rbegin(), *up.rbegin(), p) >= 0) up.pop_back();
		while (lo.size() >= 2 && ccw(*++lo.rbegin(), *lo.rbegin(), p) <= 0) lo.pop_back();

		up.emplace_back(p);
		lo.emplace_back(p);
	}

	ll mx = mLINF;
	for (int i = 0, j = (int)lo.size() - 1; i + 1 < up.size() || j > 0; ) {
		// get_pair(up[i], lo[j]); // DO WHAT YOU WANT
		ll d = (up[i].x-lo[j].x)*(up[i].x-lo[j].x) + (up[i].y-lo[j].y)*(up[i].y-lo[j].y);
		mx = max(mx, d);

		if (i + 1 == up.size()) {
			--j;
		}
		else if (j == 0) {
			++i;
		}
		else if ((long long)(up[i + 1].y - up[i].y) * (lo[j].x - lo[j - 1].x)
				> (long long)(up[i + 1].x - up[i].x) * (lo[j].y - lo[j - 1].y)) {
			++i;
		} else {
			--j;
		}
	}

	cout << mx << en;
}

void sol() {
	int n;
	cin >> n;
	vt<Point> v(n);
	for(auto& p : v) cin >> p.x >> p.y;

	antipodal_pairs(v);

	return;
}


int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);

	while(T--) {
		sol();
	}

   return 0;
}