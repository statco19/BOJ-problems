#include <bits/stdc++.h>

#define vt vector
#define ll long long
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define rev(c) (c).rbegin(), (c).rend()
#define sz(x) (int)(x).size()
#define ioa insert_or_assign
#define umap unordered_map
#define prq priority_queue
using namespace std;
typedef pair<int,int> pii;
const int d4r[4] = {-1,0,1,0}; const int d4c[4] = {0,1,0,-1};
const int d8r[8] = {-1,-1,0,1,1,1,0,-1}; const int d8c[8] = {0,1,1,1,0,-1,-1,-1};
const int INF = 0x3f3f3f3f; const int mINF = 0xc0c0c0c0;
const ll LINF = 0x3f3f3f3f3f3f3f3f; const ll mLINF = 0xc0c0c0c0c0c0c0c0;
int T = 1;

int N,M,K;
int a[101][101], b[101][101], c[101][101];

void sol() {
	cin >> N >> M;
	for(int i=1;i<=N;++i) {
		for(int j=1;j<=M;++j) {
			cin >> a[i][j];
		}
	}

	cin >> M >> K;
	for(int i=1;i<=M;++i) {
		for(int j=1;j<=K;++j) {
			cin >> b[i][j];
		}
	}

	for(int i=1;i<=N;++i) {
		for(int j=1;j<=K;++j) {
			for(int k=1;k<=M;++k) {
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}
	
	for(int i=1;i<=N;++i) {
		for(int j=1;j<=K;++j) {
			cout << c[i][j] << ' ';
		}
		cout << '\n';
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	while(T--) {
		sol();
	}

	return 0;
}