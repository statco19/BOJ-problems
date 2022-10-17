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

string N;
vt<int> v;

void sol() {
	cin >> N;

	int n = N.size()-1;
	int sum = 0;
	while(n >= 0) {
		sum += N[n] - '0';
		v.pb(N[n]-'0');
		n--;
	}

	sort(all(v), greater<>());
	if(sum % 3 != 0 || v[sz(v)-1] != 0) {
		cout << -1 << '\n';
	} else {
		for(auto x : v) {
			cout << x;
		}
		cout << '\n';
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	while(T--) {
		sol();
	}

	return 0;
}