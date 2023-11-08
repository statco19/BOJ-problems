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

int N,M;
int d[1001], ar[100001];
int r,g;

void init() {
	r = (int)sqrt(N);
	g = N / r;
	if(N % r != 0) g++;
	
	for(int i=0; i<N; ++i) {
		d[i/r] = min(d[i/r], ar[i]);
	}

	return;
}

void update(int idx, int val) {
	idx--;
	ar[idx] = val;
	int tg = idx / r;
	int s = tg * r;
	int e = min(s + r, N);

	d[tg] = ar[s];
	for(int i=s; i<e; ++i) {
		d[tg] = min(d[tg], ar[i]);
	}
	return;
}

int qry(int L, int R) {
	L--; R--;
	if(L/r == R/r) {
		int res = INF;
		for(int i=L; i<R+1; ++i) {
			res = min(res, ar[i]);
		}
		return res;
	}
	else {
		int res = INF;
		while(1) {
			res = min(res, ar[L]);
			L++;

			if(L % r == 0) break;
		}

		while(1) {
			res = min(res, ar[R]);
			R--;

			if(R % r == r-1) break;
		}

		int sg = L/r, eg = R/r;
		for(int i=sg; i<=eg; ++i) {
			res = min(res, d[i]);
		}

		return res;
	}
}

void sol() {
	cin >> N;
	memset(d,INF,sizeof(d));
	for(int i=0; i<N; ++i) {
		cin >> ar[i];
	}
	init();
	
	cin >> M;
	int a,b,c;
	while(M--) {
		cin >> a >> b >> c;
		if(a == 1) {
			update(b, c);
		} else {
			cout << qry(b, c) << en;
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