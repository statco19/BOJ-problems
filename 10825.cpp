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
	int n; cin >> n;
	vt<pair<string,vt<int>>> v(n);
	for(auto &p : v) {
		(p.second).resize(3);
		cin >> p.first >> (p.second)[0] >> (p.second)[1] >> (p.second)[2];
	}

	sort(all(v), [](const pair<string,vt<int>>& p1, const pair<string,vt<int>>& p2) {
		if((p1.second)[0] == (p2.second)[0]) {
			if((p1.second)[1] == (p2.second)[1]) {
				if((p1.second)[2] == (p2.second)[2]) {
					return p1.first < p2.first;
				} else {
					return (p1.second)[2] > (p2.second)[2];
				}
			} else {
				return (p1.second)[1] < (p2.second)[1];
			}
		} else {
			return (p1.second)[0] > (p2.second)[0];
		}
	});

	for(auto p : v) {
		cout << p.first << en;
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