#include <bits/stdc++.h>

#define ll long long
using namespace std;
typedef pair<int,int> pint;
typedef vector<int> vint;
const int INF = 0x3f3f3f3f; const int mINF = 0xc0c0c0c0;
const ll LINF = 0x3f3f3f3f3f3f3f3f; const ll mLINF = 0xc0c0c0c0c0c0c0c0;

int N,D;
ll arr[100000];
ll dp[100000];
ll t[200000];
ll ans;

void init() {
	for(int i=N-1;i>0;--i) t[i] = max(t[i<<1],t[i<<1|1]);
}

ll query(int l, int r) {
	ll res = mLINF;
	for(l+=N,r+=N;l<r;l>>=1, r>>=1) {
		if(l&1) res = max(res, t[l++]);
		if(r&1) res = max(res, t[--r]);
	}
	return res;
}

void update(int p, ll val) {
	for(t[p+=N]=val;p>1;p>>=1) t[p>>1] = max(t[p], t[p^1]);
}

void sol() {
	init();

	int l,r;
	for(int i=1;i<N;++i) {
		r = i;
		l = i-D < 0 ? 0 : i-D;
		ll tmp = max(query(l,r) + t[i+N], t[i+N]);

		update(i, tmp);
	}
	
	ans = query(0,N);

	return;
}
 
int main() {
	scanf("%d", &N);
	scanf("%d", &D);
	for(int i=0;i<N;++i) {
		scanf("%lld", &arr[i]);
		t[i+N] = arr[i];
	}

	sol();
	printf("%lld\n", ans);
	return 0;
}

