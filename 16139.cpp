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

int psum[200001][26];

void sol() {
	string s;
	int q;
	cin >> s >> q;

	for(int i=1; i<=sz(s); ++i) {
		psum[i][s[i-1]-'a']++;
		for(int j=0; j<26; ++j) {
			psum[i][j] += psum[i-1][j];
		}
	}

	char a;
	int l,r;
	while(q--) {
		cin >> a >> l >> r;
		cout << psum[r+1][a-'a'] - psum[l][a-'a'] << en;
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
