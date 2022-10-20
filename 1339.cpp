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

int N;
ll ans;
vt<int> alphabets;

void sol() {
	cin >> N;
	alphabets.resize(26);
	string s;
	for(int i=0; i<N; ++i) {
		cin >> s;
		int pos = pow(10, sz(s)-1);

		for(int j=0; j<sz(s); ++j) {
			alphabets[s[j] - 'A'] += pos;
			pos /= 10;
		}
	}
	sort(all(alphabets));

	int cnt = 9;
	for(int i=sz(alphabets)-1; ~i; --i) {
		if(!cnt) break;

		ans += alphabets[i] * cnt--;
	}

	cout << ans << '\n';

	return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	while(T--) {
		sol();
	}

	return 0;
}