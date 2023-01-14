#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

#define ll long long
#define vt vector
#define pii pair<int,int>
#define en "\n"
#define pb push_back
#define sz(x) (x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;
int T = 1;

int t;
int n,m;
vt<int> a,b;
ll ans;

void sol() {
	cin >> t;
	cin >> n;
	a.resize(n);
	for(int &x : a) cin >> x;

	cin >> m;
	b.resize(m);
	for(int &x : b) cin >> x;

	vt<int> sa,sb;
	for(int i=0; i<n; ++i) {
		int sum = a[i];
		sa.pb(sum);
		for(int j=i+1; j<n; ++j) {
			sum += a[j];
			sa.pb(sum);
		}
	}

	for(int i=0; i<m; ++i) {
		int sum = b[i];
		sb.pb(sum);
		for(int j=i+1; j<m; ++j) {
			sum += b[j];
			sb.pb(sum);
		}
	}

	sort(all(sa)); sort(all(sb));
	for(int i=0; i<sz(sa); ++i) {
		int sum = sa[i];
		
		ans += upper_bound(all(sb), t-sum) - lower_bound(all(sb), t-sum);
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