#include <bits/stdc++.h>

#define vt vector
#define en '\n'
#define ll long long
#define ull unsigned long long
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
const int d4r[4] = {-1,0,1,0}; const int d4c[4] = {0,1,0,-1};
const int d8r[8] = {-1,-1,0,1,1,1,0,-1}; const int d8c[8] = {0,1,1,1,0,-1,-1,-1};
const int INF = 0x3f3f3f3f; const int mINF = 0xc0c0c0c0;
const ll LINF = 0x3f3f3f3f3f3f3f3f; const ll mLINF = 0xc0c0c0c0c0c0c0c0;
int T = 1;

const int mx = 2e5;
int N,M;
pii t[2*mx];

void init() {
	for(int i=N-1; i>0; --i) {
		if(t[i<<1].first < t[i<<1|1].first) {
			t[i] = t[i<<1];
		} else if(t[i<<1].first > t[i<<1|1].first) {
			t[i] = t[i<<1|1];
		} else {
			if(t[i<<1].second <= t[i<<1|1].second) {
				t[i] = t[i<<1];
			} else {
				t[i] = t[i<<1|1];
			}
		}
	}
}

void update(int p, int val) {
	for(t[p+=N].first = val; p>1; p>>=1) {
		if(t[p].first < t[p^1].first) {
			t[p>>1] = t[p];
		} else if(t[p].first > t[p^1].first) {
			t[p>>1] = t[p^1];
		} else {
			if(t[p].second <= t[p^1].second) {
				t[p>>1] = t[p];
			} else {
				t[p>>1] = t[p^1];
			}
		}
	}
}

int qry(int l, int r) {
	int res = INF;
	int idx = N;
	for(l+=N, r+=N; l<r; l>>=1, r>>=1) {
		if(l&1) {
			int tmp = t[l].first;
			if(tmp < res) {
				res = tmp;
				idx = t[l].second;
			} else if(tmp == res) {
				idx = min(idx, t[l].second);
			}
			l++;
		}
		if(r&1) {
			--r;
			int tmp = t[r].first;
			if(tmp < res) {
				res = tmp;
				idx = t[r].second;
			} else if(tmp == res) {
				idx = min(idx, t[r].second);
			}
		}
	}
	return idx;
}

void sol() {
	cin >> N;
	for(int i=0,x; i<N; ++i) {
		cin >> x;
		t[i+N] = {x,i+1};
	}
	init();

	cin >> M;
	int x,l,v;
	while(M--) {
		cin >> x;
		if(x == 1) {
			cin >> l >> v;
			update(l-1,v);
		} else {
			cout << qry(0,N) << en;
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