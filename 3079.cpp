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
const int INF = 0x3f3f3f3f; const int mINF = 0xc0c0c0c0;
const ll LINF = 0x3f3f3f3f3f3f3f3f; const ll mLINF = 0xc0c0c0c0c0c0c0c0;
int T = 1;


void sol() {
	int N,M;
	cin >> N >> M;
	vt<ull> v(N);
	for(ull &x : v) cin >> x;
		
	ull ans = *max_element(all(v)) * M;
	ull l=0, r=*max_element(all(v)) * M;
	while(l+1 < r) {
		ull mid = (l+r) / 2;
		
		ull cnt = 0;
		for(ull x : v) {
			cnt += mid / x;
		}
		
		if(cnt >= M) {
			r = mid;
			ans = min(ans,r);
		} else {
			l = mid;
		}
	}

	cout << ans << en;

	return;
}


int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);

	while(T--) {
		sol();
	}

   return 0;
}