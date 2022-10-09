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
string s;
int ans;
int c[1001][1001];

void sol() {
	for(int i=1;i<=s1.size();++i) {
		for(int j=1;j<=s2.size();++j) {
			if(s1[i-1] == s2[j-1]) {
				c[i][j] = c[i-1][j-1] + 1;
			} else {
				c[i][j] = max(c[i][j-1], c[i-1][j]);
			}
		}
	}

	int i = s1.size(), j = s2.size();
	ans = c[i][j];
	while(i > 0 && j > 0) {
		if(c[i-1][j] < c[i][j] && c[i][j-1] < c[i][j]) {
			s += s1[i-1];
			i--;
			j--;
		} else if(c[i][j-1] >= c[i][j]) {
			j--;
		} else {
			i--;
		}
	}
	string rev(s.rbegin(), s.rend());
	cout << ans << '\n';
	cout << rev << '\n';

	return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> s1 >> s2;
	sol();

	return 0;
}