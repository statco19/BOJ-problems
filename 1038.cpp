#include <bits/stdc++.h>

#define ll long long
using namespace std;
typedef pair<int,int> pint;
typedef vector<int> vint;
const int INF = 0x3f3f3f3f; const int mINF = 0xc0c0c0c0;
const ll LINF = 0x3f3f3f3f3f3f3f3f; const ll mLINF = 0xc0c0c0c0c0c0c0c0;

int N;
int nums[10] = {0,1,2,3,4,5,6,7,8,9};
vector<ll> res;
ll ans;

void dfs(int st, int limitDepth, int depth, ll n) {
	if(depth == limitDepth) {
		res.push_back(n);
		return;
	}

	for(int i=st;i<10;++i) {
		dfs(i+1, limitDepth, depth+1, (i * pow(10,depth) + n));
	}
	return;
}

void sol() {
	if(N <= 9) {
		ans = N;
		return;
	}
	if(N >= 1023) {
		ans = -1;
		return;
	}

	vint v;
	for(int i=1;i<=10;++i) {
		dfs(0, i, 0, 0);
	}

	sort(res.begin(), res.end());
	ans = res[N];

	return;
}
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;

	sol();
	cout << ans << '\n';
	return 0;
}
