#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

#define ll long long
#define vt vector
#define pii pair<int,int>
#define en "\n"
#define sz(x) (x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;
int T = 1;

const int mx = 5e5;
int N;
vt<int> v;
int t[2*mx];

void update(int p, int val) {
	for(t[p+=N]=val; p>1; p>>=1) t[p>>1] = t[p] + t[p^1];
}

int qry(int l, int r) {
	int res = 0;
	for(l+=N, r+=N; l<r; l>>=1, r>>=1) {
		if(l&1) res += t[l++];
		if(r&1) res += t[--r];
	}
	return res;
}

bool cmp1(pii &a, pii &b) {
	return a.first < b.first;
}

bool cmp2(pii &a, pii &b) {
	return a.second < b.second;
}

void sol() {
	cin >> N;
	v.resize(N);
	for(int &x : v) cin >> x;

	vt<pii> u(N);
	for(int i=0; i<sz(v); ++i) {
		int ab = v[i];
		u[i] = {v[i],i};
	}

	sort(all(u), cmp1);
	for(int i=0; i<sz(u); ++i) {
		int idx = u[i].second;
		u[i] = {i,idx};
	}

	sort(all(u), cmp2);
	for(int i=0; i<sz(u); ++i) {
		int ab = u[i].first;
		int idx = u[i].second;
		cout << (idx+1) - qry(0,ab) << en;
		update(ab,1);
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	while(T--) {
		sol();
	}

	return 0;
}