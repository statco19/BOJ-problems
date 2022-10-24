#include <bits/stdc++.h>
using namespace std;

void sol() {
	int N;
	cin >> N;
	int ans = 0;
	vector<int> v;
	v.resize(N);
	for(int i=0;i<N;++i) {
		cin >> v[i];
	}

	int mx = v[v.size()-1];
	for(int i=v.size()-2;~i;--i) {
		while(v[i] >= mx) {
			v[i]--;
			ans++;
		}
		mx = v[i];
	}
	cout << ans << '\n';

	return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int T = 1;
	while(T--) {
		sol();
	}

	return 0;
}