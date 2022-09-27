#include <bits/stdc++.h>

#define ll long long
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vint;
const int INF = 0x3f3f3f3f; const int mINF = 0xc0c0c0c0;
const ll LINF = 0x3f3f3f3f3f3f3f3f; const ll mLINF = 0xc0c0c0c0c0c0c0c0;

int N;
int ans;
vector<pii> v;

bool cmp(pii &p1, pii &p2) {
	if(p1.first < p2.first) {
		return 1;
	} else {
		return p1.second <= p2.second;
	}
}

void sol() {
	int a,b;
	for(int i=0;i<N;++i) {
		a = v[i].first;
		b = v[i].second;

		if(ans < a) {
			ans = a;
		}
		ans += b;
	}

	return;
}
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	v.resize(N);
	int a,b;
	for(int i=0;i<N;++i) {
		cin >> a >> b;
		v[i] = {a,b};
	}
	sort(v.begin(), v.end());

	sol();
	cout << ans << '\n';
	return 0;
}
