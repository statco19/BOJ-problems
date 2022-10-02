#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define ioa insert_or_assign
#define umap unordered_map
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vint;
const int INF = 0x3f3f3f3f; const int mINF = 0xc0c0c0c0;
const ll LINF = 0x3f3f3f3f3f3f3f3f; const ll mLINF = 0xc0c0c0c0c0c0c0c0;

ll ans;
int N;
vint road;
vector<ll> gas;

void sol() {
	ll mnG = gas[0];
	for(int i=0;i<N-1;++i) {
		ans += road[i] * mnG;
		if(gas[i+1] < mnG) mnG = gas[i+1];
	}
	cout << ans << '\n';

	return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	road.resize(N-1);
	gas.resize(N);
	for(int i=0;i<N-1;++i) {
		cin >> road[i];
	}
	for(int i=0;i<N;++i) {
		cin >> gas[i];
	}
	sol();

	return 0;
}
