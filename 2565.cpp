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

int N;
int ans;
vector<pii> lines;
int dp[101];

bool cmp(pii &a, pii &b) {
	if(a.first < b.first) return 1;
	else if(a.first == b.first) return a.second <= b.second;
	else return 0;
}

void sol() {
	sort(lines.begin(), lines.end(),cmp);
	
	for(int i=1;i<=N;++i) {
		dp[i] = 1;
		for(int j=1;j<i;++j) {

			if(lines[j-1].second < lines[i-1].second) {
				dp[i] = max(dp[j]+1, dp[i]);
			}
		}
	}

	ans = N - *max_element(dp,dp+N+1);
	cout << ans << '\n';

	return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	lines.resize(N);
	int x,y;
	for(int i=0;i<N;++i) {
		cin >> x >> y;
		lines[i] = {x,y};
	}
	sol();

	return 0;
}