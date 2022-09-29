#include <bits/stdc++.h>

#define ll long long
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vint;
const int INF = 0x3f3f3f3f; const int mINF = 0xc0c0c0c0;
const ll LINF = 0x3f3f3f3f3f3f3f3f; const ll mLINF = 0xc0c0c0c0c0c0c0c0;

int ans;
int N;
int arr[100002];
stack<int> st;

void sol() {
	st.push(0);  // dummy
	for(int i=1;i<=N+1;++i) {
		while(!st.empty() && arr[st.top()] > arr[i]) {
			int idx = st.top(); st.pop();
			ans = max(ans, arr[idx] * (i - st.top() - 1));
		}
		st.push(i);
	}

	return;
}
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	for(int i=1;i<=N;++i) {
		cin >> arr[i];
	}

	sol();
	cout << ans << '\n';
	return 0;
}
