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

void sol() {
	int N;
	cin >> N;
	vt<pii> v(N);
	for(auto &p : v) {
		cin >> p.first >> p.second;
	}

	vt<pii> u(N);
	for(int i=0; i<N; ++i) {
		u[i].first = v[i].first * v[i].second;
		u[i].second = v[i].second - 1;
	}

	int sum = 0;
	for(int i=0; i<N; ++i) {
		sum += u[i].first;
	}

	cout << sum << en;

	return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	while(T--) {
		sol();
	}

	return 0;
}
