#include <bits/stdc++.h>

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

void sol() {
	umap<int,pii> u;
	vt<int> v;
	int cnt = 0;
	int N,C;
	cin >> N >> C;
	for(int i=0,x; i<N; ++i) {
		cin >> x;
		if(u.find(x) == u.end()) {
			u[x] = {1,cnt++};
			v.pb(x);
		} else {
			pii& p = u[x];
			p.first++;
		}
	}

	vt<pair<int,pii>> a;
	for(int x : v) {
		a.pb({x,u[x]});
	}
	sort(all(a), [](const pair<int,pii>& p1, pair<int,pii>& p2) {
		return(p1.second.first == p2.second.first) 
		? p1.second.second < p2.second.second 
		: p1.second.first > p2.second.first;
	});

	for(auto p : a) {
		for(int i=0; i<p.second.first; ++i) {
			cout << p.first << ' ';
		}
	}
	cout << en;

	return;
}


int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	while(T--) {
		sol();
	}

   return 0;
}