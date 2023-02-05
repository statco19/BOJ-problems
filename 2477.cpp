#include <bits/stdc++.h>

#define vt vector
#define en '\n'
#define ll long long
#define ld long double
#define pb push_back
#define pii pair<int,int>
#define sz(x) (x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;
const int INF = 0x3f3f3f3f; const int mINF = 0xc0c0c0c0;
const ll LINF = 0x3f3f3f3f3f3f3f3f; const ll mLINF = 0xc0c0c0c0c0c0c0c0;
int T = 1;

int k;
int cnt[5];
vt<pii> v;
int d, l;

void sol() {
	cin >> k;
	// (4,2), (2,3), (3,1), (1,4)
	
	for(int i=0; i<6; ++i) {
		cin >> d >> l;
		cnt[d]++;
		v.pb({d,l});
	}

	int ans;
	if(cnt[4]==1 && cnt[2]==1) {
		pii p1,p2;
		int area = 0;
		for(pii p : v) {
			if(p.first == 4) p1 = p;
			if(p.first == 2) p2 = p;
		}
		area += p1.second * p2.second;

		bool flag = 0;
		for(int i=0; i<5; ++i) {
			if(v[i].first == 1 && v[i+1].first == 3) {
				area -= v[i].second * v[i+1].second;
				flag = 1;
				break;
			}
		}
		if(!flag) {
			area -= v[0].second * v[5].second;
		}
		
		ans = k * area;
	} else if(cnt[2]==1 && cnt[3]==1) {
		pii p1,p2;
		int area = 0;
		for(pii p : v) {
			if(p.first == 2) p1 = p;
			if(p.first == 3) p2 = p;
		}
		area += p1.second * p2.second;

		bool flag = 0;
		for(int i=0; i<5; ++i) {
			if(v[i].first == 4 && v[i+1].first == 1) {
				area -= v[i].second * v[i+1].second;
				flag = 1;
				break;
			}
		}
		if(!flag) {
			area -= v[0].second * v[5].second;
		}
		
		ans = k * area;
	} else if(cnt[3]==1 && cnt[1]==1) {
		pii p1,p2;
		int area = 0;
		for(pii p : v) {
			if(p.first == 3) p1 = p;
			if(p.first == 1) p2 = p;
		}
		area += p1.second * p2.second;

		bool flag = 0;
		for(int i=0; i<5; ++i) {
			if(v[i].first == 2 && v[i+1].first == 4) {
				area -= v[i].second * v[i+1].second;
				flag = 1;
				break;
			}
		}
		if(!flag) {
			area -= v[0].second * v[5].second;
		}
		
		ans = k * area;
	} else if(cnt[1]==1 && cnt[4]==1) {
		pii p1,p2;
		int area = 0;
		for(pii p : v) {
			if(p.first == 1) p1 = p;
			if(p.first == 4) p2 = p;
		}
		area += p1.second * p2.second;

		bool flag = 0;
		for(int i=0; i<5; ++i) {
			if(v[i].first == 3 && v[i+1].first == 2) {
				area -= v[i].second * v[i+1].second;
				flag = 1;
				break;
			}
		}
		if(!flag) {
			area -= v[0].second * v[5].second;
		}
		
		ans = k * area;
	}

	cout << ans << en;

	return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	while(T--) {
		sol();
	}

	return 0;
}
