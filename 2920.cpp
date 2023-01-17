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
	bool asc = 1, desc = 1;
	int x;
	for(int i=0; i<8; ++i) {
		cin >> x;
		if(x != (i+1)) asc = 0;
		if(x != (8-i)) desc = 0;
	}

	if(!asc && !desc) cout << "mixed" << en;
	else if(!asc) cout << "descending" << en;
	else cout << "ascending" << en;

	return;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	while (T--) {
		sol();
	}

	return 0;
}
