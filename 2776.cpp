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


void sol() {
	int N,M;
	cin >> N;
	vt<int> v(N);
	for(int& x : v) cin >> x;

	cin >> M;
	vt<int> u(M);
	for(int& x : u) cin >> x;
	
	sort(all(v));
	for(int i=0; i<M; ++i) {
		int l=-1, r=N;
		bool found = 0;
		while(l+1 < r) {
			int mid = (l+r)/2;

			if(u[i] == v[mid]) {
				found = 1;
				break;
			} else if(u[i] < v[mid]) {
				r = mid;
			} else {
				l = mid;
			}
		}

		if(found) cout << 1 << en;
		else cout << 0 << en;
	}

	return;
}


int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	while(T--) {
		sol();
	}

   return 0;
}