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

typedef struct Point_ {
	ll x,y;

	bool operator<=(const Point_ &p) {
		if(x == p.x) {
			return y <= p.y;
		}
		return x <= p.x;
	}
} Point;

typedef struct line {
	Point s,e;
} Line;

int N;
int group[3001];
int cnt[3001];

int find(int x) {
	if(group[x] == x) return x;
	return group[x] = find(group[x]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);

	if(a < b) {
		group[b] = a;
	} else {
		group[a] = b;
	}
	return;
}

bool isUnion(int a, int b) {
	return find(a) == find(b);
}

int ccw(Point &a, Point &b, Point &c) {
	ll x = a.x*b.y + b.x*c.y + c.x*a.y - b.x*a.y - c.x*b.y - a.x*c.y;
	if(x > 0) return 1;
	else if(x == 0) return 0;
	else return -1;
}

void sol() {
	cin >> N;
	vt<Line> v(N+1);

	for(int i=1; i<=N; ++i) group[i] = i;

	int x1,y1,x2,y2;
	for(int i=1; i<=N; ++i) {
		cin >> x1 >> y1 >> x2 >> y2;
		v[i].s = {x1,y1};
		v[i].e = {x2,y2};
	}

	int num = 0;
	for(int i=1; i<=N-1; ++i) {
		for(int j=i+1; j<=N; ++j) {
			Line la = v[i];
			Line lb = v[j];

			if(ccw(la.s, la.e, lb.s) * ccw(la.s, la.e, lb.e) <= 0 && ccw(lb.s, lb.e, la.s) * ccw(lb.s, lb.e, la.e) <=0 ) {
				if(ccw(la.s, la.e, lb.s) * ccw(la.s, la.e, lb.e) == 0 && ccw(lb.s, lb.e, la.s) * ccw(lb.s, lb.e, la.e) == 0) {
					if(la.e <= la.s) swap(la.s, la.e);
					if(lb.e <= lb.s) swap(lb.s, lb.e);

					if(la.s <= lb.e && lb.s <= la.e) {
						if(!isUnion(i,j)) {
							merge(i,j);
						}
					}
				} else {
					if(!isUnion(i,j)) {
						merge(i,j);
					}
				}
			}
		}
	}

	unordered_map<int,int> um;
	set<int> st;
	int mxCnt = 0;
	for(int i=1; i<=N; ++i) {
		int x = find(i);
		st.insert(group[x]);
		if(++um[group[x]] > mxCnt) {
			mxCnt = um[x];
		}
	}

	cout << sz(st) << en << mxCnt << en;

	return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	while(T--) {
		sol();
	}

	return 0;
}