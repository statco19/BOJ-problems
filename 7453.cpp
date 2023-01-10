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
#define en '\n'

const int d4r[4] = {-1,0,1,0}; const int d4c[4] = {0,1,0,-1};
const int d8r[8] = {-1,-1,0,1,1,1,0,-1}; const int d8c[8] = {0,1,1,1,0,-1,-1,-1};
const int INF = 0x3f3f3f3f; const int mINF = 0xc0c0c0c0;
const ll LINF = 0x3f3f3f3f3f3f3f3f; const ll mLINF = 0xc0c0c0c0c0c0c0c0;
int T = 1;

int n;
int arr[4000][4];
ll ans;

void sol() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 4; ++j) {
			cin >> arr[i][j];
		}
	}

	// meet in the middle
	umap<int,int> um;
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			sum = arr[i][0] + arr[j][1];
			um[sum]++;
		}
	}

	sum = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			sum = arr[i][2] + arr[j][3];
			if(um.find(-sum) != um.end()) ans += um[-sum];
		}
	}

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
