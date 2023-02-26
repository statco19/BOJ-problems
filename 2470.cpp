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
	int n;
	cin >> n;
	vt<int> v(n);
	for(int& x : v) cin >> x;

	sort(all(v));
	int l=0, r=sz(v)-1;
	int diff = 2e9+1;
	int a,b;
	while(l<r) {
		int sum = (v[l] + v[r]);
		if(diff > abs(sum)) {
			diff = abs(sum);
			a = v[l]; b = v[r];
		}

		if(sum <= 0) {
			l++;
		} else {
			r--;
		}
	}

	cout << a << ' ' << b << en;

	return;
}


int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);

	while(T--) {
		sol();
	}

   return 0;
}
