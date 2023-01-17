#include <bits/stdc++.h>

#define ll long long
#define vt vector
#define en '\n'
#define pb push_back
#define pii pair<int,int>
#define prq priority_queue
#define sz(x) (x).size()
#define all(x) (x).begin(), (x).end()
#define rev(x) (x).rbegin(), (x).rend()

using namespace std;

const int INF = 0x3f3f3f3f; const int mINF = 0xc0c0c0c0;
const ll LINF = 0x3f3f3f3f3f3f3f3f; const ll mLINF = 0xc0c0c0c0c0c0c0c0;
const int d4r[4] = { -1,0,1,0 }; const int d4c[4] = { 0,1,0,-1 };
int T = 1;

void sol() {
	string s = "";
	while(1) {
		cin >> s;
		if(s == "0") break;

		int l=0, r=sz(s)-1;
		bool flag = 0;
		while(l<=r) {
			if(s[l] != s[r]) {
				flag = 1;
				break;
			}
			l++;
			r--;
		}
		if(flag) cout << "no" << en;
		else cout << "yes" << en;
	}
	
	return;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	while (T--) {
		sol();
	}

	return 0;
}
