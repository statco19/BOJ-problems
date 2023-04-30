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

void sol() {
	double gpa = 0.0;
	string sub, grade;
	double credit;
	double c = 0.0;
	umap<string, double> u;
	u["A+"] = 4.5; u["A0"] = 4.0;
	u["B+"] = 3.5; u["B0"] = 3.0;
	u["C+"] = 2.5; u["C0"] = 2.0;
	u["D+"] = 1.5; u["D0"] = 1.0;
	u["F"] = 0.0;
	for(int i=0; i<20; ++i) {
		cin >> sub >> credit >> grade;
		if(grade != "P") {
			gpa += credit * u[grade];
			c += credit;
		}
	}
	
	cout << fixed;
	cout.precision(6);
	if(c == 0.0) {
		cout << c << en;
	} else {
		cout << gpa / c << en;
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