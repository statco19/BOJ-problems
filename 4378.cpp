#include <bits/stdc++.h>
#include <quadmath.h>

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
	string s;
	umap<char, char> u;
	u['1']='`', u['2']='1'; u['3']='2'; u['4']='3'; u['5']='4';
	u['6']='5'; u['7']='6'; u['8']='7'; u['9']='8'; u['0']='9';
	u['-']='0'; u['=']='-';
	u['W']='Q'; u['E']='W'; u['R']='E'; u['T']='R'; u['Y']='T';
	u['U']='Y'; u['I']='U'; u['O']='I'; u['P']='O'; u['[']='P'; u[']']='['; u['\\']=']';
	u['S']='A'; u['D']='S'; u['F']='D'; u['G']='F'; u['H']='G';
	u['J']='H'; u['K']='J'; u['L']='K'; u[';']='L'; u['\'']=';'; u['X']='Z';
	u['C']='X'; u['V']='C'; u['B']='V'; u['N']='B'; u['M']='N';
	u[',']='M'; u['/']='.'; u[' ']=' '; u['.']=',';

	while(1) {
		getline(cin, s);
		if(cin.eof()) break;
		for(int i=0; i<sz(s); ++i) cout << u[s[i]];
		cout << en;
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