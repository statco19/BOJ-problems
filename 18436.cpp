#include <bits/stdc++.h>

#define vt vector
#define en '\n'
#define ll long long
#define ld long double
#define pb push_back
#define pii pair<int,int>
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rev(c) (c).rbegin(), (c).rend()
#define mid (st+end)/2

using namespace std;
const int INF = 0x3f3f3f3f; const int mINF = 0xc0c0c0c0;
const ll LINF = 0x3f3f3f3f3f3f3f3f; const ll mLINF = 0xc0c0c0c0c0c0c0c0;
int T = 1;

const int mx = 1e5;
int N,M;
int t[2*mx];
int a[mx];

void init() {
	for(int i=N-1; i>0; --i) t[i] = t[i<<1] + t[i<<1|1];
}

void update(int p, int val) {
	for(t[p+=N]=val; p>1; p>>=1) t[p>>1] = t[p] + t[p^1];
}

int qry(int l, int r) {
	int res = 0;
	for(l+=N, r+=N; l<r; l>>=1, r>>=1) {
		if(l&1) res += t[l++];
		if(r&1) res += t[--r];
	}
	return res;
}

void sol() {
	cin >> N;
	for(int i=0; i<N; ++i) {
		cin >> a[i];
		if(a[i] & 1) t[i+N] = 1;
		else t[i+N] = 0;
	}
	init();

	cin >> M;
	int x, l, r;
	for(int i=0; i<M; ++i) {
		cin >> x >> l >> r;
		if(x == 1) {
			update(l-1, r&1);
		} else if(x == 2) {
			cout << (r-l+1) - qry(l-1,r) << en;
		} else {
			cout << qry(l-1,r) << en;
		}
	}	

	return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	while(T--) {
		sol();
	}

	return 0;
}