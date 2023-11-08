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

int N;
vt<string> v,u;
umap<string, int> um;
int ans;

void sol() {
	cin >> N;
	string s;
	for(int i=0; i<N; ++i) {
		cin >> s;
		v.pb(s);
		um.insert({s,i});
	}

	for(int i=0; i<N; ++i) {
		cin >> s;
		u.pb(s);
		int initIdx = um.find(s)->second;
		if(initIdx == 0) continue;
		else {
			int cnt = 0;
			for(int j=0; j<i; ++j) {
				int afterIdx = um.find(u[j])->second;
				if(afterIdx < initIdx) cnt++;
			}

			if(cnt < initIdx) ans++;
		}
	}

	cout << ans << en;

	return;
}


int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);

	while(T--) {
		sol();
	}

   return 0;
}