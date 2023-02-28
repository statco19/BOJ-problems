#include <bits/stdc++.h>

#define vt vector
#define en '\n'
#define ll long long
#define ld long double
#define ioa insert_or_assign
#define umap unordered_map
#define prq priority_queue
#define pb push_back
#define pii pair<int,int>
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rev(c) (c).rbegin(), (c).rend()
#define mset(ar, val) memset(ar, val, sizeof(ar))

using namespace std;
const int INF = 0x3f3f3f3f; const int mINF = 0xc0c0c0c0;
const ll LINF = 0x3f3f3f3f3f3f3f3f; const ll mLINF = 0xc0c0c0c0c0c0c0c0;
int T = 1;

const int mx = 1e5;
int N,M;
vt<int> t[2*mx];

void init() {
	for(int i=N-1; i>0; --i) {
		t[i].resize(sz(t[i<<1]) + sz(t[i<<1|1]));
		merge(all(t[i<<1]), all(t[i<<1|1]), t[i].begin());
	}
}

int qry(int l, int r, int k) {
	int res = 0;
	for(l+=N, r+=N; l<r; l>>=1, r>>=1) {
		if(l&1) {
			res += t[l].end() - upper_bound(all(t[l]), k);
			l++;
		}
		if(r&1) {
			--r;
			res += t[r].end() - upper_bound(all(t[r]), k);
		}
	}
	return res;
}

void sol() {
	cin >> N;
	int x;
	for(int i=0; i<N; ++i) {
		cin >> x;
		t[i+N].pb(x);
	}
	init();

	cin >> M;
	int i,j,k;
	while(M--) {
		cin >> i >> j >> k;
		cout << qry(i-1, j, k) << en;
	}

	return;
}


int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);

	while(T--) {
		sol();
	}

   return 0;
}
