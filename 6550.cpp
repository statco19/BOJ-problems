#include <bits/stdc++.h>

#define vt vector
#define en '\n'
#define ll long long
#define ld long double
#define pb push_back
#define pii pair<int,int>
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rev(c) (c).rbegin(), (c).rend()
#define mid (st+end)/2

using namespace std;
const int INF = 0x3f3f3f3f; const int mINF = 0xc0c0c0c0;
const ll LINF = 0x3f3f3f3f3f3f3f3f; const ll mLINF = 0xc0c0c0c0c0c0c0c0;
int T = 1;


void sol() {
	string s,t;
	while(1) {
		cin >> s >> t;
		if(cin.eof()) break;

		int idx = 0;
		for(int i=0; i<sz(t); ++i) {
			if(t[i] == s[idx]) {
				idx++;
			}	
		}
		if(idx == sz(s)) cout << "Yes" << en;
		else cout << "No" << en;
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