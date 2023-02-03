#include <bits/stdc++.h>

#define vt vector
#define en '\n'
#define ll long long
#define ld long double
#define pb push_back
#define pii pair<int,int>
#define sz(x) (x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;
const int INF = 0x3f3f3f3f; const int mINF = 0xc0c0c0c0;
const ll LINF = 0x3f3f3f3f3f3f3f3f; const ll mLINF = 0xc0c0c0c0c0c0c0c0;
int T = 1;

ll psum[1000001];
ll mod[1000001];
ll cnt[1001];
ll ans;
int N,M;

void sol() {
	cin >> N >> M;
	int x;
	for(int i=1; i<=N; ++i) {
		cin >> x;
		psum[i] = psum[i-1] + x;
	}
	for(int i=1; i<=N; ++i) {
		mod[i] = psum[i] % M;
	}

	for(int i=1; i<=N; ++i) {
		cnt[mod[i]]++;
	}

	for(int i=0; i<M; ++i) {
		ll x = cnt[i];
		if(x) {
			if(i == 0) ans += x;
			ans += 1LL * x * (x-1) / 2;
		}
	}
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
