#include <bits/stdc++.h>

#define vt vector
#define en '\n'
#define ll long long
#define ld long double
#define pb push_back
#define pii pair<int,int>
#define sz(x) (x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;
const int INF = 0x3f3f3f3f; const int mINF = 0xc0c0c0c0;
const ll LINF = 0x3f3f3f3f3f3f3f3f; const ll mLINF = 0xc0c0c0c0c0c0c0c0;
int T = 1;

void sol() {
	int n;
	string s;
	cin >> n >> s;

	for(int i=0; i<n-4; ++i) {
		char c = s[i];
		bool win = 1;
		for(int j=i+1; j<i+5; ++j) {
			if(c+1 == s[j] || c-1 == s[j]) {
				c = s[j];
			} else {
				win = 0;
				break;
			}
		}

		if(win) {
			cout << "YES" << en;
			return;
		}
	}

	cout << "NO" << en;

	return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	while(T--) {
		sol();
	}

	return 0;
}