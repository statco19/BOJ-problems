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

const double EPS = 1e-10;
typedef vector<vector<double>> VVD;

bool gauss_jordan(VVD& a, VVD& b) {
	const int n = a.size();
	const int m = b[0].size();
	vector<int> irow(n), icol(n), ipiv(n);

	for (int i = 0; i < n; i++) {
		int pj=-1,pk=-1;
		for (int j = 0; j < n; j++) if (!ipiv[j])
			for (int k = 0; k < n; k++) if (!ipiv[k])
				if (pj == -1 || fabs(a[j][k]) > fabs(a[pj][pk])) { pj = j; pk = k; }

	if (fabs(a[pj][pk]) < EPS) return false;
	ipiv[pk]++;
	swap(a[pj], a[pk]);
	swap(b[pj], b[pk]);
	irow[i] = pj;
	icol[i] = pk;

	double c = 1.0 / a[pk][pk];
	a[pk][pk] = 1.0;
	for (int p=0;p < n; p++) a[pk][p] *= c;
	for (int p=0;p < m; p++) b[pk][p] *= c;
	for (int p=0;p < n; p++) if(p!=pk) {
		c = a[p][pk];
		a[p][pk] = 0;
		for(int q=0;q<n;q++) a[p][q]-= a[pk][q]*c;
		for (int q = 0; q < m; q++) b[p][q] -= b[pk][q] * c;
		}
	}

	for(int p = n - 1; p >= 0; p--) if (irow[p] != icol[p]) {
		for (int k = 0; k < n; k++) swap(a[k][irow[p]], a[k][icol[p]]);
	}

	return true;
}

void sol() {
	int N; cin >> N;

	VVD A,B;
	for(int i=0; i<N; ++i) {
		vt<double> v;
		double x;
		for(int j=0; j<N; ++j) {
			cin >> x;
			v.pb(x);
		}
		A.pb(v);

		v.clear();
		cin >> x;
		v.pb(x);
		B.pb(v);
	}

	gauss_jordan(A,B);
	for(int i=0; i<N; ++i) {
		cout << B[i][0] << ' ';
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