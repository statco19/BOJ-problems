#include <bits/stdc++.h>

#define ll long long
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vint;
const int INF = 0x3f3f3f3f; const int mINF = 0xc0c0c0c0;
const ll LINF = 0x3f3f3f3f3f3f3f3f; const ll mLINF = 0xc0c0c0c0c0c0c0c0;

int N;
ll ans;
unordered_map<ll,int> um;
priority_queue<pair<int,ll>> pq;

void sol() {
	for(auto it=um.begin();it != um.end(); ++it) {
		pq.push({it->second, -(it->first)});
	}
	ans = -pq.top().second;

	return;
}
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	ll x;
	for(int i=0;i<N;++i) {
		cin >> x;
		if(um.find(x) == um.end()) {
			um.insert({x,1});
		} else {
			auto p = um.find(x);
			um.insert_or_assign(x,(p->second)+1);
		}
	}

	sol();
	cout << ans << '\n';
	return 0;
}
