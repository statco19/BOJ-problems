#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define vt vector
#define ll long long
#define pb push_back
#define ioa insert_or_assign
#define umap unordered_map
#define prq priority_queue
#define F first
#define S second
#define all(c) (c).begin(), (c).end()
#define rev(c) (c).rbegin(), (c).rend()
#define sz(x) (int)(x).size()
#define mset(ar, val) memset(ar, val, sizeof(ar))
#define en "\n"

const int d4r[4] = {-1,0,1,0}; const int d4c[4] = {0,1,0,-1};
const int d8r[8] = {-1,-1,0,1,1,1,0,-1}; const int d8c[8] = {0,1,1,1,0,-1,-1,-1};
const int INF = 0x3f3f3f3f; const int mINF = 0xc0c0c0c0;
const ll LINF = 0x3f3f3f3f3f3f3f3f; const ll mLINF = 0xc0c0c0c0c0c0c0c0;
int T = 1;

int n,k;
int ans;
vt<vt<int>> v;
bool vis[6][11];

void dfs(int idx, int credit) {
	if(credit >= k) {
		if(credit > k) {
			return;
		}

		ans++;
		return;
	}

	for(int i=idx; i<n; ++i) {
		auto u = v[i];
		bool overlap = 0;
		for(int i=u[1]; i<=u[2]; ++i) {
			if(vis[u[0]][i]) {
				overlap = 1;
				break;
			}
		}
		if(overlap) continue;

		for(int i=u[1]; i<=u[2]; ++i) {
			vis[u[0]][i] = 1;
		}
		dfs(i+1, credit + (u[2] - u[1] + 1));
		for(int i=u[1]; i<=u[2]; ++i) {
			vis[u[0]][i] = 0;
		}
	}
}

void sol() {
	cin >> n >> k;
	int w,s,e;
	int five = 0;
	for(int i=0; i<n; ++i) {
		cin >> w >> s >> e;
		if(w == 5) {
			five++;
			continue;
		}
		v.pb({w,s,e});
	}
	n -= five;
	dfs(0, 0);
	cout << ans << en;

	return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	while(T--) {
		sol();
	}

	return 0;
}