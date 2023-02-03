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
	unordered_map<string, bool> um;
	string s;
	cin >> s;
	for(int i=0; i<sz(s); ++i) {
		for(int j=0; j<sz(s); ++j) {
			string t = s.substr(i,j);
			if(um.find(t) == um.end()) um.insert_or_assign(t,1);	
		}
	}
	cout << sz(um) << en;

	return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	while(T--) {
		sol();
	}

	return 0;
}
