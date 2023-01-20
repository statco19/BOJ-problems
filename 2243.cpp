#include <iostream>
#include <algorithm>

#define vt vector
#define en '\n'

using namespace std;
int T = 1;

const int mx = 1e6;
int t[2*mx];
int n;

// void init() {
// 	for(int i=mx-1; i>0; --i) t[i] = t[i<<1] + t[i<<1|1];
// }

void update(int p, int val) {
	for(t[p+=mx]+=val; p>1; p>>=1) t[p>>1] = t[p] + t[p^1];
}

int qry(int l, int r) {
	int res = 0;
	for(l+=mx, r+=mx; l<r; l>>=1, r>>=1) {
		if(l&1) res += t[l++];
		if(r&1) res += t[--r];
	}
	return res;
}

void sol() {
	cin >> n;

	int a,b,c;
	for(int i=0; i<n; ++i) {
		cin >> a;
		if(a == 1) {
			cin >> b;

			int l = -1, r = mx;
			while(l+1 < r) {
				int mid = (l+r) / 2;

				if(l < 0) l = 0;
				int left = qry(l, mid);
				int right = qry(mid, r);

				if(b <= left) {
					r = mid;
				} else {
					l = mid;
					b -= left;
				}
			}

			cout << l+1 << en;
			update(l, -1);
		} else {
			cin >> b >> c;
			update(b-1, c);
		}
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	while(T--) {
		sol();
	}

	return 0;
}
