#include <bits/stdc++.h>

#define vt vector
#define en '\n'
#define ll long long
#define all(x) (x).begin(), (x).end()

using namespace std;
int T = 1;

void sol() {
	int N,W,H;
	cin >> N >> W >> H;

	int x;
	while(N--) {
		cin >> x;
		if(x <= W || x <= H || x*x <= W*W + H*H) {
			cout << "DA" << en;
		} else {
			cout << "NE" << en;
		}
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	while(T--) {
		sol();
	}

	return 0;
}
