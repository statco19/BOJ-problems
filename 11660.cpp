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
int arr[1025][1025];
int psum[1025][1025];

void sol() {
	for(int i=1;i<=N;++i) {
		for(int j=1;j<=N;++j) {
			psum[i][j] = arr[i][j] + psum[i][j-1];
		}
	}
	for(int j=1;j<=N;++j) {
		for(int i=1;i<=N;++i) {
			psum[i][j] += psum[i-1][j];
		}
	}

	int x1,y1,x2,y2;
	for(int k=0;k<M;++k) {
		cin >> x1 >> y1 >> x2 >> y2;
		cout << psum[x2][y2] - psum[x1-1][y2] - psum[x2][y1-1] + psum[x1-1][y1-1] << '\n';
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	for(int i=1;i<=N;++i) {
		for(int j=1;j<=N;++j) {
			cin >> arr[i][j];
		}
	}	
	sol();

	return 0;
}