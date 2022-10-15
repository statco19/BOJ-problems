#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define ioa insert_or_assign
#define umap unordered_map
#define prq priority_queue
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vint;
const int di4[4] = {-1,0,1,0}; const int dj4[4] = {0,1,0,-1};
const int di8[8] = {-1,-1,0,1,1,1,0,-1}; const int dj8[8] = {0,1,1,1,0,-1,-1,-1};
const int INF = 0x3f3f3f3f; const int mINF = 0xc0c0c0c0;
const ll LINF = 0x3f3f3f3f3f3f3f3f; const ll mLINF = 0xc0c0c0c0c0c0c0c0;
int T = 1;

int N;
int arr[501][2];
int m[501][501], s[501][501];

void sol() {
	cin >> N;
	for(int i=1;i<=N;++i) {
		cin >> arr[i][0] >> arr[i][1];
	}

	for(int l=2;l<=N;++l) {
		for(int i=1;i<=N-l+1;++i) {
			int j = i + l - 1;
			m[i][j] = INF;
			for(int k=i;k<j;++k) {
				int q = m[i][k] + m[k+1][j] + arr[i][0]*arr[k][1]*arr[j][1];
				if(q < m[i][j]) {
					m[i][j] = q;
					s[i][j] = k;
				}
			}

			for(int i=1;i<=N;++i) {
				for(int j=1;j<=N;++j) {
					cout << m[i][j] << ' ';
				}
				cout << '\n';
			}
			cout << '\n';

			for(int i=1;i<=N;++i) {
				for(int j=1;j<=N;++j) {
					cout << s[i][j] << ' ';
				}
				cout << '\n';
			}
			cout << '\n';
		}
	}
	cout << m[1][N] << '\n';

	return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	while(T--) {
		sol();
	}

	return 0;
}