#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define ioa insert_or_assign
#define umap unordered_map
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vint;
const int INF = 0x3f3f3f3f; const int mINF = 0xc0c0c0c0;
const ll LINF = 0x3f3f3f3f3f3f3f3f; const ll mLINF = 0xc0c0c0c0c0c0c0c0;

int T,n;
vint f;

void fib() {
	f.resize(100000);
	f[0] = 0; f[1] = 1; f[2] = 1;
	int idx = 2;
	while(f[idx++] < 1000000000) {
		f[idx] = f[idx-1] + f[idx-2];
	}
	f.resize(idx);
}

void sol() {
	vint v;
	for(int i=f.size()-1; i>0; --i) {
		if(f[i] <= n) {
			v.pb(f[i]);
			n -= f[i];
		}
	}

	for(int j=v.size()-1; ~j; --j) {
		cout << v[j];
		if(j>0)
			cout << " ";
	}
	cout << '\n';

	return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	fib();
	while(T--) {
		cin >> n;
		sol();
	}

	return 0;
}

