#include <bits/stdc++.h>

#define vt vector
#define en '\n'
#define ll long long
#define all(x) (x).begin(), (x).end()

using namespace std;
int T = 1;

void sol() {
	int K;
	cin >> K;
	priority_queue<ll> pq;
	int x;
	for(int i=0; i<K; ++i) {
		cin >> x;
		pq.push(-x);
	}

	ll ans = 0;
	while(pq.size() >= 2) {
		ll a = -pq.top(); pq.pop();
		ll b = -pq.top(); pq.pop();
		ans += a+b;
		pq.push(-(a+b));
	}

	cout << ans << en;
	
	return;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--) {
		sol();
	}

	return 0;
}
