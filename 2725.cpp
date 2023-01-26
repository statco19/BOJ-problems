#include <bits/stdc++.h>

#define vt vector
#define en '\n'
#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()

using namespace std;
int T = 1;

int vis[1001][1001];

int gcd(int a, int b) { return b == 0 ? a : gcd(b,a%b); }

void sol() {
	int n;
	cin >> n;

	int ans = 2;
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=n; ++j) {
			if(!vis[i][j]) ans++;
		}
	}

	cout << ans << en;

	return;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> T;

	for(int i=1; i<=1000; ++i) {
		for(int j=1; j<=1000; ++j) {
			if(!vis[i][j] && gcd(i,j) == 1) {
				int r = i, c = j;
				while(1) {
					r += i;
					c += j;
					if(r > 1000 || c > 1000) break;
					vis[r][c] = 1;
				}
			}
		}
	}

	while(T--) {
		sol();
	}

	return 0;
}
