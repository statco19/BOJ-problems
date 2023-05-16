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

vt<int> ans;
vt<int> v(9);
int sum;

void dfs(int idx, int depth) {
	if(depth == 7) {
		if(sum == 100) {
			sort(all(ans));
			for(int x : ans) cout << x << en;
			exit(0);
		}
	} else {
		for(int i=idx; i<9; ++i) {
			sum += v[i];
			ans.pb(v[i]);
			dfs(i+1, depth+1);
			ans.pop_back();
			sum -= v[i];
		}
	}
	return;
}

void sol() {
	for(int &x : v) cin >> x;
	dfs(0, 0);

	return;
}


int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);

	while(T--) {
		sol();
	}

   return 0;
}