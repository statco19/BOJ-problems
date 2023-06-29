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
	int n; cin >> n;
	vt<int> v(n);
	for(int &x : v) cin >> x;
	ll sum = 0;
		
	sort(all(v));
	deque<int> dq;
	dq.push_back(v[0]);
	for(int i=1; i<n; ++i) {
		if(i&1) {
			dq.push_front(v[i]);
		} else {
			dq.push_back(v[i]);
		}
	}
	for(int i=1; i<n; ++i) {
		sum += abs(dq[i]-dq[i-1]);
	}
	sum += abs(dq[0]-dq[n-1]);

	cout << sum << en;

	return;
}


int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);

	while(T--) {
		sol();
	}

   return 0;
}