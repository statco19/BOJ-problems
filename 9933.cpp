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
const int d4r[4] = {-1,0,1,0}; const int d4c[4] = {0,1,0,-1};
const int d8r[8] = {-1,-1,0,1,1,1,0,-1}; const int d8c[8] = {0,1,1,1,0,-1,-1,-1};
const int INF = 0x3f3f3f3f; const int mINF = 0xc0c0c0c0;
const ll LINF = 0x3f3f3f3f3f3f3f3f; const ll mLINF = 0xc0c0c0c0c0c0c0c0;
int T = 1;

int N;
umap<string, bool> um;

bool isPal(string s) {
	return s == string(rev(s));
}

void sol() {
	cin >> N;
	int len; char c;

	string s;
	for(int i=0; i<N; ++i) {
		cin >> s;
		if(isPal(s)) {
			len = s.size();
			c = s[(int)s.size() / 2];
		} else {
			if(um.find(s) != um.end()) {
				len = s.size();
				c = s[(int)s.size() / 2];
			}
			else {
				um.insert({string(rev(s)), 1});
			}
		}
	}

	cout << len << ' ' << c << en;

	return;
}


int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);

	while(T--) {
		sol();
	}

   return 0;
}