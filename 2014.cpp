#include <bits/stdc++.h>

#define vt vector
#define en '\n'
#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()

using namespace std;
int T = 1;

void sol() {
	int K,N;
	cin >> K >> N;
	vt<int> v(K);
	for(int &x : v) cin >> x;

	priority_queue<int> pq;
	int cnt = 0;
	int prev = 0;

	for(int x : v) pq.push(-x);
	while(cnt < N) {
		while(prev == -pq.top()) {
			pq.pop();
		}
		ll res;
		for(int x : v) {
			res = -pq.top() * (ll)x;
			if(res > ((1LL<<31)-1)) {
				break;
			}

			pq.push(-res);
		}
		prev = -pq.top();
		cnt++;
	}

	cout << -pq.top() << en;

	return;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	while(T--) {
		sol();
	}

	return 0;
}
