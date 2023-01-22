#include <iostream>
#include <algorithm>

#define vt vector
#define en '\n'
#define ll long long

using namespace std;
int T = 1;

int N;

struct Point {
	ll x,y;
	bool operator < (const Point &a) {
		return y == a.y ? x < a.x : y < a.y;
	}
};

Point p[100001];

ll ccw(const Point &a, const Point &b, const Point &c) {
	return a.x*b.y + b.x*c.y + c.x*a.y - b.x*a.y - c.x*b.y - a.x*c.y;
}

ll dist(const Point &a, const Point &b) {
	return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}

bool cmp(const Point &a, const Point &b) {
	ll c = ccw(p[0], a, b);
	if(c == 0) {
		return dist(p[0], a) < dist(p[0], b);
	}

	return c > 0;
}

int stack[100001], top;
void push(int n) { stack[top++] = n; }

void sol() {
	cin >> N;
	for(int i=0; i<N; ++i) {
		cin >> p[i].x >> p[i].y;
	}

	sort(p, p+N);
	sort(p+1, p+N, cmp);

	push(0);
	push(1);

	for(int i=2; i<N; ++i) {
		while(top >= 2 && ccw(p[i], p[stack[top-2]], p[stack[top-1]]) <= 0) top--;
		push(i);
	}

	cout << top << en;

	return;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	while(T--) {
		sol();
	}

	return 0;
}
