#include <bits/stdc++.h>

#define vt vector
#define en '\n'
#define ll long long
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
const int INF = 0x3f3f3f3f; const int mINF = 0xc0c0c0c0;
const ll LINF = 0x3f3f3f3f3f3f3f3f; const ll mLINF = 0xc0c0c0c0c0c0c0c0;
int T = 1;

int N;
vt<int> v;
int M;
int ans;

void sol() {
	cin >> N;
	v.resize(N);
	for(int& x : v) cin >> x;
	cin >> M;
	
	int l = 0, r = 1e9;
	while(l+1<r) {
		int mid = (l+r)/2;
		int k = 0;
		int sum = 0;
		for(int x : v) {
			sum += min(x,mid);
			k = max(k, min(x,mid));
		}

		if(sum == M) {
			ans = max(ans, k);
			r = mid;
		} else if(sum > M) {
			r = mid;
		} else if(sum < M) {
			ans = max(ans, k);
			l = mid;
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
