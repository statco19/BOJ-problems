#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define ioa insert_or_assign
#define umap unordered_map
#define prq priority_queue
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vint;
const int INF = 0x3f3f3f3f; const int mINF = 0xc0c0c0c0;
const ll LINF = 0x3f3f3f3f3f3f3f3f; const ll mLINF = 0xc0c0c0c0c0c0c0c0;

int N;
int arr[1000001];
vint v = {mINF};
int ans;

int bs(int l, int r, int t) {
	int idx = 0;
	while(l+1<r) {
		int mid = (l+r)/2;

		if(v[mid] == t) {
			return mid;
		} else if(v[mid] > t) {
			r = mid;
		} else {
			l = mid;
		}
	}
	return r;
}

void sol() {
	for(int i=1;i<=N;++i) {
		if(arr[i] > v.back()) {
			v.pb(arr[i]);
		} else {
			// auto it = lower_bound(v.begin(), v.end(), arr[i]);
			// *it = arr[i];
			int idx = bs(0,v.size()-1,arr[i]);
			v[idx] = arr[i];
		}
	}
	ans = v.size() - 1;
	cout << ans << '\n';

	return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	for(int i=1;i<=N;++i) {
		cin >> arr[i];
	}
	sol();

	return 0;
}