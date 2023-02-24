#include <bits/stdc++.h>

#define vt vector
#define en '\n'
#define ll long long
#define ld long double
#define pb push_back
#define pii pair<int,int>
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rev(c) (c).rbegin(), (c).rend()
#define mid (st+end)/2

using namespace std;
const int INF = 0x3f3f3f3f; const int mINF = 0xc0c0c0c0;
const ll LINF = 0x3f3f3f3f3f3f3f3f; const ll mLINF = 0xc0c0c0c0c0c0c0c0;
int T = 1;

const int mx = 1e9;
const int h = ceil(log2(mx));
int N,M,V;
int C[200001];
int sparse[h+1][200001];

void sol() {
	cin >> N >> M >> V;
	for(int i=1; i<=N; ++i) cin >> C[i];

	for(int j=1; j<=N; ++j) {
		if(j == N) {
			sparse[0][j] = V;
		} else {
			sparse[0][j] = j+1;
		}
	}
	for(int i=1; i<=h; ++i) {
		for(int j=1; j<=N; ++j) {
			sparse[i][j] = sparse[i-1][sparse[i-1][j]];
		}
	}

	int K;
	for(int i=0; i<M; ++i) {
		cin >> K;
		int node = 1;
		int idx = 0;
		while(K) {
			if(K&1) node = sparse[idx][node];

			idx++;
			K >>= 1;
		}

		cout << C[node] << en;
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