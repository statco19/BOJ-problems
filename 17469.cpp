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

int N,Q;
int p[100001];
vt<int> v;
set<int> nodes[100001];
vt<pii> qr;
vt<int> ans;

int find(int x) {
	if(p[x] == x) return x;
	return p[x] = find(p[x]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);

	if(a != b) {
		if(sz(nodes[a]) <= sz(nodes[b])) {
			for(auto it=nodes[a].begin(); it!=nodes[a].end(); ++it) {
				nodes[b].insert(*it);
			}

			p[a] = b;
		} else {
			for(auto it=nodes[b].begin(); it!=nodes[b].end(); ++it) {
				nodes[a].insert(*it);
			}

			p[b] = a;
		}
	}
	return;
}

bool isUnion(int a, int b) {
	return find(a) == find(b);
}

void sol() {
	cin >> N >> Q;
	for(int i=1; i<=N; ++i)
		p[i] = i;

	v.resize(N+1);
	for(int i=2; i<=N; ++i) {
		cin >> v[i];
	}

	int color;
	for(int i=1; i<=N; ++i) {
		cin >> color;
		nodes[i].insert(color);
	}

	qr.resize(N+Q-1);
	for(int i=0; i<N+Q-1; ++i) {
		auto &q = qr[i];
		cin >> q.first >> q.second;
	}

	for(int i=sz(qr)-1; ~i; --i) {
		auto q = qr[i];
		if(q.first == 1) {
			int x = q.second;
			if(!isUnion(x,v[x])) {
				merge(x,v[x]);
			}
		} else if(q.first == 2) {
			ans.pb(sz(nodes[find(q.second)]));
		}
	}

	for(int i=sz(ans)-1; ~i; --i) {
		cout << ans[i] << en;
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
