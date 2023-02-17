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
	double x, y;
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

  	Point operator*(double t) const {
		return Point{ x * t, y * t }; 
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

vector<Point> convex_hull(vector<Point>& dat) {
	if (dat.size() <= 3) return dat;
	vector<Point> upper, lower;
	sort(dat.begin(), dat.end(), [](const Point& a, const Point& b) {
		return(a.x==b.x)?a.y<b.y:a.x<b.x;
	});

	for (const auto& p : dat) {
		while (upper.size() >= 2 && ccw(*++upper.rbegin(), *upper.rbegin(), p) >= 0) upper.pop_back();
		while (lower.size() >= 2 && ccw(*++lower.rbegin(), *lower.rbegin(), p) <= 0) lower.pop_back();
		upper.emplace_back(p);
		lower.emplace_back(p);
	}
	upper.insert(upper.end(), ++lower.rbegin(), --lower.rend());
	return upper;
}

vt<Point> v;
bool cmp(const Point &a, const Point &b) {
	ll c = ccw(v[0], a, b);
	if(c == 0) {
		return dist(v[0], a) < dist(v[0], b);
	}

	return c > 0;
}

void sol() {
	int n;
	cin >> n;
	v.resize(n);
	
	for(int i=0; i<n; ++i) {
		Point& p = v[i];
		cin >> p.x >> p.y;
		p.idx = i;
	}

	sort(v.begin(), v.end(), [](const Point& a, const Point& b) {
		return(a.x==b.x)?a.y<b.y:a.x<b.x;
	});

	sort(v.begin()+1, v.end(), cmp);
	vt<Point> u;
	int idx = 0;
	for(int i=sz(v)-1; i>0; --i) {
		if(ccw(v[0], v[i], v[i-1]) == 0) {
			u.emplace_back(v[i-1]);
		} else {
			idx = i;
			break;
		}
	}
	u.insert(u.begin(), v.back());

	for(int i=0; i<idx; ++i) {
		cout << v[i].idx << " ";
	}
	for(auto& p : u) {
		cout << p.idx << " ";
	}
	cout << en;

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