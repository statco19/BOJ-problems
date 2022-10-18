#include <bits/stdc++.h>

#define vt vector
#define ll long long
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define rev(c) (c).rbegin(), (c).rend()
#define sz(x) (int)(x).size()
#define ioa insert_or_assign
#define umap unordered_map
#define prq priority_queue
using namespace std;
typedef pair<int,int> pii;
const int d4r[4] = {-1,0,1,0}; const int d4c[4] = {0,1,0,-1};
const int d8r[8] = {-1,-1,0,1,1,1,0,-1}; const int d8c[8] = {0,1,1,1,0,-1,-1,-1};
const int INF = 0x3f3f3f3f; const int mINF = 0xc0c0c0c0;
const ll LINF = 0x3f3f3f3f3f3f3f3f; const ll mLINF = 0xc0c0c0c0c0c0c0c0;
int T = 1;

int N;
int ans;
int zeros;
vt<int> v;

void sol() {
	cin >> N;
	v.resize(N);
	for(int i=0;i<N;++i) {
		cin >> v[i];
	}

	// 0 : do not get tied up with positive numbers, get tied up with the smallest negative nubmers (if any exist)
	// 1 : do not get tied up with positive numbers

	sort(all(v));
	prq<int> minq, maxq, ones;
	for(auto x : v) {
		if(x < 0) {
			minq.push(-x);
		} else if(x != 1 && x > 0) {
			maxq.push(x);
		} else if(x == 0) {
			zeros++;
		} else if(x == 1) {
			ones.push(x);
		}
	}

	if(sz(minq)&1^1) {
		while(!minq.empty()) {
			int a = -minq.top(); minq.pop();
			int b = -minq.top(); minq.pop();

			ans += a * b;
		}
	} else {
		while(sz(minq) > 1) {
			int a = -minq.top(); minq.pop();
			int b = -minq.top(); minq.pop();

			ans += a * b;
		}

		if(zeros) {
			zeros--;  // tied up with a zero
		} else {
			while(sz(minq)) {
				ans += -minq.top();
				minq.pop();
			}
		}
	}

	while(sz(maxq) > 1) {
		int a = maxq.top(); maxq.pop();
		int b = maxq.top(); maxq.pop();
		ans += a * b;
	}
	while(sz(maxq)) {
		ans += maxq.top();
		maxq.pop();
	}

	while(sz(ones)) {
		ans++;
		ones.pop();
	}

	cout << ans << '\n';

	return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	while(T--) {
		sol();
	}

	return 0;
}