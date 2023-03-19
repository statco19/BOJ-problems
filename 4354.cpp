#include <bits/stdc++.h>
#include <quadmath.h>

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

typedef vector<int> seq_t;

void sol() {
	string s;
	while(1) {
		cin >> s;
		if(s == ".") break;

		seq_t str;
		for(int i=0; i<sz(s); ++i) {
			str.pb(s[i]);
		}

		vt<int> pi(sz(str));
		pi[0] = -1;
		for (int i = 1, j = -1; i < str.size(); i++) {
			while (j >= 0 && str[i] != str[j + 1]) j = pi[j];
			if (str[i] == str[j + 1])
				pi[i] = ++j;
			else
				pi[i] = -1;
		}

		int x = pi[sz(s)-1]+1;
		if(sz(s) % (sz(s)-x) == 0) {
			cout << sz(s) / (sz(s)-x) << en;
		} else {
			cout << 1 << en;
		}
	}

	return;
}


int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);

	while(T--) {
		sol();
	}

   return 0;
}