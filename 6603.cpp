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

int k;
vt<int> v, a;

void dfs(int idx, int depth) {
	if(depth == 6) {
		for(int x : a) {
			cout << x << ' ';
		}
		cout << en;
		return;
	}

	for(int i=idx; i<k; ++i) {
		a.pb(v[i]);
		dfs(i+1,depth+1);
		a.pop_back();
	}
	return;
}

void sol() {
	while(1) {
		cin >> k;
		if(!k) return;
		v.clear();
		for(int i=0,x; i<k; ++i) {
			cin >> x;
			v.pb(x);
		}

		dfs(0,0);
		cout << en;
	}

	return;
}


int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);

	while(T--) {
		sol();
	}

   return 0;
}