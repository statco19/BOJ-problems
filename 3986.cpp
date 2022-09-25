#include <bits/stdc++.h>

#define ll long long
using namespace std;
typedef pair<int,int> pint;
typedef vector<int> vint;
const int INF = 0x3f3f3f3f; const int mINF = 0xc0c0c0c0;
const ll LINF = 0x3f3f3f3f3f3f3f3f; const ll mLINF = 0xc0c0c0c0c0c0c0c0;

int N;
int ans;

void sol() {
	string s;
	for(int i=0;i<N;++i) {
		stack<char> st;
		cin >> s;

		for(int j=0;j<s.size();++j) {
			char c = s[j];
			if(!st.empty()) {
				if(st.top() == c) {
					st.pop();
				} else {
					st.push(c);
				}
			} else {
				st.push(c);
			}
		}

		if(st.empty()) ans++;
	}
	return;
}
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> N;

	sol();
	cout << ans << '\n';
	return 0;
}
