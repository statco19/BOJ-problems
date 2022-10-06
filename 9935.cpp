#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define ioa insert_or_assign
#define umap unordered_map
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vint;
const int INF = 0x3f3f3f3f; const int mINF = 0xc0c0c0c0;
const ll LINF = 0x3f3f3f3f3f3f3f3f; const ll mLINF = 0xc0c0c0c0c0c0c0c0;

string ans;
string S,E;
stack<char> st;
stack<char> e;

void sol() {
	for(int i=0;i<S.size();++i) {
		st.push(S[i]);
		if(S[i] == E[E.size()-1]) {
			string temp = "";
			int cnt = 0;
			while(!st.empty() && cnt < E.size()) {
				temp += st.top();
				st.pop();
				cnt++;
			}
			string rev(temp.rbegin(), temp.rend());
			if(rev != E) {
				for(int j=0;j<rev.size();++j) {
					st.push(rev[j]);
				}
			}
		}
	}
	string tmp = "";
	while(!st.empty()) {
		tmp += st.top();
		st.pop();
	}
	if(tmp == "") ans = "FRULA";
	else {
		string rev(tmp.rbegin(), tmp.rend());
		ans = rev;
	}
	cout << ans << '\n';

	return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> S >> E;
	sol();

	return 0;
}