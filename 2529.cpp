#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define vt vector
#define ll long long
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define en '\n'

const int d4r[4] = {-1,0,1,0}; const int d4c[4] = {0,1,0,-1};
const int d8r[8] = {-1,-1,0,1,1,1,0,-1}; const int d8c[8] = {0,1,1,1,0,-1,-1,-1};
const int INF = 0x3f3f3f3f; const int mINF = 0xc0c0c0c0;
const ll LINF = 0x3f3f3f3f3f3f3f3f; const ll mLINF = 0xc0c0c0c0c0c0c0c0;
int T = 1;


ll mxN = mLINF, mnN = LINF;
string mx, mn;
int k;
vt<int> ineq(10);
vt<int> nums(11);
vt<bool> v(11);

void dfs(int depth) {
	if(depth == k+1) {
		string s = "";
		for(int i=1; i<=k+1; ++i) {
			s += to_string(nums[i]);
		}
		ll val = stoll(s);
		if(val > mxN) {
			mxN = val;
			mx = s;
		}
		if(val < mnN) {
			mnN = val;
			mn = s;
		}
		return;
	}

	if(depth == 0) {
		for(int i=0; i<10; ++i) {
			v[i] = 1;
			nums[depth+1] = i;
			dfs(depth+1);
			nums[depth+1] = 0;
			v[i] = 0;
		}
	} else {
		for(int i=0; i<10; ++i) {
			if(!v[i]) {
				if(ineq[depth] && nums[depth] < i) {
					v[i] = 1;
					nums[depth+1] = i;
					dfs(depth+1);
					nums[depth+1] = 0;
					v[i] = 0;
				} else if(!ineq[depth] && nums[depth] > i) {
					v[i] = 1;
					nums[depth+1] = i;
					dfs(depth+1);
					nums[depth+1] = 0;
					v[i] = 0;
				}
			}
		}
	}

	return;
}

void sol() {
	cin >> k;
	string s;
	for(int i=1; i<=k; ++i) {
		cin >> s;
		ineq[i] = s == "<" ? 1 : 0;
	}

	dfs(0);
	cout << mx << en << mn << en;

	return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	while(T--) {
		sol();
	}

	return 0;
}