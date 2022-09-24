#include <bits/stdc++.h>

#define ll long long
using namespace std;
typedef pair<int,int> pint;
typedef vector<int> vint;
const int INF = 0x3f3f3f3f; const int mINF = 0xc0c0c0c0;
const ll LINF = 0x3f3f3f3f3f3f3f3f; const ll mLINF = 0xc0c0c0c0c0c0c0c0;

const int MAX = 5e6;
int N,L;
deque<pint> dq;
int arr[MAX], dp[MAX];

void sol() {
	for(int i=0;i<N;++i) {
		dp[i] = arr[i];

		while(!dq.empty() && dq.front().first < i-L+1) {
			dq.pop_front();
		}
		if(!dq.empty()) {
			dp[i] = min(dq.front().second, dp[i]);
		}
		while(!dq.empty() && dq.back().second > arr[i]) {
			dq.pop_back();
		}
		dq.push_back({i,arr[i]});
	}

	for(int i=0;i<N;++i) {
		cout << dp[i] << " ";
	}
	cout << '\n';

	return;
}
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> N >> L;
	for(int i=0;i<N;++i) {
		cin >> arr[i];
	}

	sol();
	return 0;
}
