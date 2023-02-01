#include <bits/stdc++.h>

#define vt vector
#define en '\n'
#define ll long long
#define ld long double
#define pb push_back
#define sz(x) (x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;
const int INF = 0x3f3f3f3f; const int mINF = 0xc0c0c0c0;
const ll LINF = 0x3f3f3f3f3f3f3f3f; const ll mLINF = 0xc0c0c0c0c0c0c0c0;
int T = 1;

int N,Q;
int p[200001];
vt<vt<int>> queries;
vt<int> v;
vt<string> res;

int find(int x) {
	if(p[x] == x) return x;
	return p[x] = find(p[x]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);

	if(a < b) p[b] = a;
	else p[a] = b;

	return;
}

bool isUnion(int a, int b) {
	return find(a) == find(b);
}

void sol() {
	cin >> N >> Q;
	v.resize(N+1);
	for(int i=1; i<=N; ++i) {
		p[i] = i;
	}

	for(int i=1; i<=N-1; ++i) {
		cin >> v[i+1];
	}

	int x,b,c,d;
	for(int i=0; i<N-1+Q; ++i) {
		cin >> x;
		if(x == 0) {
			cin >> b;
			queries.pb({x,b});
		} else {
			cin >> c >> d;
			queries.pb({x,c,d});
		}
	}

	for(int i=sz(queries)-1; ~i; --i) {
		vt<int> q = queries[i];
		int x = q[0];
		int b,c,d;
		if(x == 0) {
			b = q[1];

			merge(b, v[b]);
		} else {
			c = q[1];
			d = q[2];

			if(isUnion(c,d)) {
				res.pb("YES");
			} else {
				res.pb("NO");
			}
		}
	}
	for(int i=sz(res)-1; ~i; --i) {
		cout << res[i] << en;
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
