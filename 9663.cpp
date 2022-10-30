#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define vt vector
#define ll long long
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define en '\n'
const int d4r[4] = {-1,0,1,0}; const int d4c[4] = {0,1,0,-1};
const int d8r[8] = {-1,-1,0,1,1,1,0,-1}; const int d8c[8] = {0,1,1,1,0,-1,-1,-1};
const int INF = 0x3f3f3f3f; const int mINF = 0xc0c0c0c0;
const ll LINF = 0x3f3f3f3f3f3f3f3f; const ll mLINF = 0xc0c0c0c0c0c0c0c0;
int T = 1;

int N;
int ans;
int vru[31], vld[31], vr[16], vc[16];

void dfs(int c, int cnt) {
	if(cnt == N) {
		ans++;
		return;
	}

	for(int i=1; i<=N; ++i) {
		if(!vru[c-i+(N-1)] && !vld[i+c] && !vr[i]) {
			vru[c-i+(N-1)] = 1; vld[i+c] = 1; vr[i] = 1;
			dfs(c+1, cnt+1);
			vru[c-i+(N-1)] = 0; vld[i+c] = 0; vr[i] = 0;
		}
	}
}

void sol() {
	cin >> N;

	dfs(0,0);
	cout << ans << en;

	return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	while(T--) {
		sol();
	}

	return 0;
}