#include <bits/stdc++.h>

#define ll long long
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vint;
const int INF = 0x3f3f3f3f; const int mINF = 0xc0c0c0c0;
const ll LINF = 0x3f3f3f3f3f3f3f3f; const ll mLINF = 0xc0c0c0c0c0c0c0c0;

stack<pii> st;
int N;
int arr[1000001], freq[1000001], res[1000001];

void sol() {
	for(int i=1;i<=N;++i) {
		freq[arr[i]]++;
	}

	// monotone stack (larget -> small)
	for(int i=N;i>=1;--i) {
		int x = freq[arr[i]];
		while(!st.empty() && st.top().second <= x) {  // st.top().second : frequency
			st.pop();
		}
		if(st.empty()) {
			res[i] = -1;
		} else {
			res[i] = st.top().first;
		}
		st.push({arr[i],x});
	}

	for(int i=1;i<=N;++i) {
		cout << res[i] << " ";
	}
	cout << '\n';

	return;
}
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	for(int i=1;i<=N;++i) {
		cin >> arr[i];
	}

	sol();
	return 0;
}
