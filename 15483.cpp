#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define ioa insert_or_assign
#define umap unordered_map
#define prq priority_queue
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vint;
const int INF = 0x3f3f3f3f; const int mINF = 0xc0c0c0c0;
const ll LINF = 0x3f3f3f3f3f3f3f3f; const ll mLINF = 0xc0c0c0c0c0c0c0c0;

string s1,s2;
int ans;
int c[1001][1001];

void sol() {
	for(int i=0;i<=s1.size();++i) {
		c[i][s2.size()] = s1.size() - i;
	}
	for(int j=0;j<=s2.size();++j) {
		c[s1.size()][j] = s2.size() - j;
	}

	for(int i=s1.size()-1; ~i; --i) {
		for(int j=s2.size()-1; ~j; --j) {
			if(s1[i] == s2[j]) {
				c[i][j] = c[i+1][j+1];
			} else {
				c[i][j] = min({c[i][j+1], c[i+1][j], c[i+1][j+1]}) + 1;
			}
		}
	}
	ans = c[0][0];
	cout << ans << '\n';

	return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> s1 >> s2;
	sol();

	return 0;
}