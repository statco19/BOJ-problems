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
int t[2*mx];

void init() {
	for(int i=N-1; i>0; --i) t[i] = min(t[i<<1], t[i<<1|1]);
}

void update(int p, int val) {
	for(t[p+=N]=val; p>1; p>>=1) t[p>>1] = min(t[p], t[p^1]);
}

int qry(int l, int r) {
	int res = INF;
	for(l+=N, r+=N; l<r; l>>=1, r>>=1) {
		if(l&1) res = min(res, t[l++]);
		if(r&1) res = min(res, t[--r]);
	}
	return res;
}

void sol() {
	cin >> N;
	for(int i=0; i<N; ++i) cin >> t[i+N];
	init();

	cin >> M;
	int x,i,j;
	while(M--) {
		cin >> x >> i >> j;
		if(x == 1) {
			update(i-1, j);
		} else {
			cout << qry(i-1, j) << en;
		}
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
