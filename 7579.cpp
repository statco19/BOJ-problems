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

int N,M;
int dp[10001];
int m[101], c[101];
int sum;

void sol() {
	for(int i=1;i<=N;++i) {
		for(int j=sum; j>=c[i]; --j) {
			dp[j] = max(dp[j], dp[j-c[i]] + m[i]);
		}
	}

	int i=0;
	for(;i<sum, dp[i]<M;++i);
	cout << i << '\n';

	return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	for(int i=1;i<=N;++i) {
		cin >> m[i];
	}
	for(int i=1;i<=N;++i) {
		cin >> c[i];
		sum += c[i];
	}
	sol();

	return 0;
}