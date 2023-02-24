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


void sol() {
	vt<int> v(50);
	for(int& x : v) cin >> x;
	int x;
	cin >> x;

	int rank = 0;
	for(int i=0; i<50; ++i) {
		if(v[i] >= x) rank++;
		else break;
	}
	if(rank <= 5) cout << "A+" << en;
	else if(rank <= 15) cout << "A0" << en;
	else if(rank <= 30) cout << "B+" << en;
	else if(rank <= 35) cout << "B0" << en;
	else if(rank <= 45) cout << "C+" << en;
	else if(rank <= 48) cout << "C0" << en;
	else cout << "F" << en;

	return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	while(T--) {
		sol();
	}

	return 0;
}