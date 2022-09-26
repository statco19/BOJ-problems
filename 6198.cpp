#include <bits/stdc++.h>

#define ll long long
using namespace std;
typedef pair<int,int> pint;
typedef vector<int> vint;
const int INF = 0x3f3f3f3f; const int mINF = 0xc0c0c0c0;
const ll LINF = 0x3f3f3f3f3f3f3f3f; const ll mLINF = 0xc0c0c0c0c0c0c0c0;

ll ans;
int N;
stack<int> st;

void sol() {
	// monotonic stack
	int x;
	for(int i=0;i<N;++i) {
		cin >> x;

		while(!st.empty() && st.top() <= x) {
			st.pop();
		}
		ans += st.size();
		st.push(x);
	}

	return;
}
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;

	sol();
	cout << ans << '\n';
	return 0;
}
