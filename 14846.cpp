#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <unordered_map>

#define ll long long
#define vt vector
#define pii pair<int,int>
#define en "\n"
#define pb push_back
#define sz(x) (x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;
int T = 1;

const int INF = 0x3f3f3f3f; const int mINF = 0xc0c0c0c0;
int d8r[8] = {-1,-1,0,1,1,1,0,-1}; int d8c[8] = {0,1,1,1,0,-1,-1,-1};

int N;
int ar[301][301][11];
int psum[301][301][11];

void sol() {
	cin >> N;
	for(int i=1; i<=N; ++i) {
		for(int j=1; j<=N; ++j) {
			int x;
			cin >> x;
			ar[i][j][x]++;
		}
	}

	for(int i=1; i<=N; ++i) {
		for(int j=1; j<=N; ++j) {
			for(int k=1; k<=10; ++k) {
				psum[i][j][k] = psum[i][j-1][k] + ar[i][j][k];
			}
		}
	}

	for(int j=1; j<=N; ++j) {
		for(int i=1; i<=N; ++i) {
			for(int k=1; k<=10; ++k) {
				psum[i][j][k] += psum[i-1][j][k];
			}
		}
	}

	int Q;
	cin >> Q;
	int x1,y1,x2,y2;
	while(Q--) {
		cin >> x1 >> y1 >> x2 >> y2;

		int cnt = 0;
		for(int k=1; k<=10; ++k) {
			cnt += psum[x2][y2][k] - psum[x1-1][y2][k] - psum[x2][y1-1][k] + psum[x1-1][y1-1][k] > 0 ? 1 : 0;
		}

		cout << cnt << en;
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