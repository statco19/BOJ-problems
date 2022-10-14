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
int T = 1;

int N;
int dp_max[2][5], dp_min[2][5], arr[100001][5];

void sol() {
	cin >> N;

	memset(dp_min, INF, sizeof(dp_min));
	memset(dp_max, mINF, sizeof(dp_max));
	for(int i=1;i<=N;++i) {
		for(int j=1;j<=3;++j) {
			cin >> arr[i][j];
		}
	}
	for(int j=1;j<=3;++j) {
		dp_max[0][j] = 0;
		dp_min[0][j] = 0;
	}

	for(int i=1;i<=N;++i) {
		for(int j=1;j<=3;++j) {
			dp_max[1][j] = arr[i][j] + max({dp_max[0][j-1], dp_max[0][j], dp_max[0][j+1]});
			dp_min[1][j] = arr[i][j] + min({dp_min[0][j-1], dp_min[0][j], dp_min[0][j+1]});
		}
		for(int j=1;j<=3;++j) {
			dp_max[0][j] = dp_max[1][j];
			dp_min[0][j] = dp_min[1][j];
		}
	}

	int mnN = INF, mxN = mINF;
	for(int j=1;j<=3;++j) {
		mnN = dp_min[1][j] < mnN ? dp_min[1][j] : mnN;
		mxN = dp_max[1][j] > mxN ? dp_max[1][j] : mxN;
	}
	cout << mxN << ' ' << mnN << '\n';

	return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	while(T--) {
		sol();
	}

	return 0;
}