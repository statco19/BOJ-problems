#include <bits/stdc++.h>

#define vt vector
#define ll long long
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define rev(c) (c).rbegin(), (c).rend()
#define sz(x) (int)(x).size()
#define ioa insert_or_assign
#define umap unordered_map
#define prq priority_queue
using namespace std;
typedef pair<int,int> pii;
const int d4r[4] = {-1,0,1,0}; const int d4c[4] = {0,1,0,-1};
const int d8r[8] = {-1,-1,0,1,1,1,0,-1}; const int d8c[8] = {0,1,1,1,0,-1,-1,-1};
const int INF = 0x3f3f3f3f; const int mINF = 0xc0c0c0c0;
const ll LINF = 0x3f3f3f3f3f3f3f3f; const ll mLINF = 0xc0c0c0c0c0c0c0c0;
int T = 1;

int t;
vt<int> v = {300, 60, 10};
vt<int> bt = {0, 0, 0};

void sol() {
	cin >> t;
	if(t % 10) {
		cout << "-1" << '\n';
		return;
	}

	for(int i=0; i<sz(v); ++i) {
		while(t >= v[i]) {
			t -= v[i];
			bt[i]++;
		}
	}
	for(auto x : bt) {
		cout << x << ' ';
	}
	cout << '\n';

	return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	while(T--) {
		sol();
	}

	return 0;
}