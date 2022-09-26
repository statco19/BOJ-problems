#include <bits/stdc++.h>

#define ll long long
using namespace std;
typedef pair<int,int> pint;
typedef vector<int> vint;
const int INF = 0x3f3f3f3f; const int mINF = 0xc0c0c0c0;
const ll LINF = 0x3f3f3f3f3f3f3f3f; const ll mLINF = 0xc0c0c0c0c0c0c0c0;

stack<char> st;
string s;
ll ans;
int open;

void sol() {
	for(int i=0;i<s.size();++i) {
		char c = s[i];
		if(c == '(') {
			st.push(c);
			open++;
		} else {
			open--;
			if(st.top() == '(') {
				ans += open;
				st.push(c);
			} else {
				ans++;
			}
		}
	}

	return;
}
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> s;

	sol();
	cout << ans << '\n';
	return 0;
}
