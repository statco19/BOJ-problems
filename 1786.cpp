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

void calculate_pi(vector<int>& pi, const seq_t& str) {
	pi[0] = -1;
	for (int i = 1, j = -1; i < str.size(); i++) {
		while (j >= 0 && str[i] != str[j + 1]) j = pi[j];
		if (str[i] == str[j + 1])
			pi[i] = ++j;
		else
			pi[i] = -1;
	}
}

vector<int> kmp(const seq_t& text, const seq_t& pattern) {
	vector<int> pi(pattern.size()), ans;
	if (pattern.size() == 0) return ans;
	calculate_pi(pi, pattern);
	for (int i = 0, j = -1; i < text.size(); i++) {
		while (j >= 0 && text[i] != pattern[j + 1]) j = pi[j];
		if (text[i] == pattern[j + 1]) {
			j++;
			if (j + 1 == pattern.size()) {
				ans.push_back(i - j);
				j = pi[j];
			}
		}
	}
	return ans;
}

void sol() {
	string t,p;
	getline(cin, t);
	getline(cin, p);

	seq_t text, pattern;
	for(int i=0; i<sz(t); ++i) {
		text.pb(t[i]);
	}
	for(int i=0; i<sz(p); ++i) {
		pattern.pb(p[i]);
	}

	seq_t ans = kmp(text, pattern);
	cout << sz(ans) << en;
	if(sz(ans)) {
		for(int x : ans) cout << x+1 << ' ';
		cout << en;
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