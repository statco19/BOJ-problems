#include <bits/stdc++.h>

#define ll long long
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vint;
const int INF = 0x3f3f3f3f; const int mINF = 0xc0c0c0c0;
const ll LINF = 0x3f3f3f3f3f3f3f3f; const ll mLINF = 0xc0c0c0c0c0c0c0c0;

int ans;
int N;
int t[200000];
int arr[100000];

void init() {
	for(int i=N-1;i>=0;--i) t[i] = arr[t[i<<1]] <= arr[t[i<<1|1]] ? t[i<<1] : t[i<<1|1];
}

int query(int l, int r) {
	int idx=0;
	int res = INF;
	for(l+=N,r+=N;l<r;l>>=1,r>>=1) {
		if(l&1) {
			if(arr[t[l]] < res) {
				res = arr[t[l]];
				idx = t[l];
			}
			l++;
		}

		if(r&1) {
			--r;
			if(arr[t[r]] < res) {
				res = arr[t[r]];
				idx = t[r];
			}
		}
	}
	return idx;
}

int largest(int l, int r) {
	int idx = query(l,r);
	int res = arr[idx] * (r-l);


	if(0<=l && l<idx) {
		// cout << "left : " << l << " " << idx << '\n';
		int area = largest(l,idx);
		if(area > res) res = area;
	}
	if(idx+1<r && r<=N) {
		// cout << "right : " << idx+1 << " " << r << '\n';
		int area = largest(idx+1, r);
		if(area > res) res = area;
	}

	return res;
}

void sol() {
	init();
	ans = largest(0,N);

	return;
}
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	for(int i=0;i<N;++i) {
		cin >> arr[i];
		t[i+N] = i;
	}

	sol();
	cout << ans << '\n';
	return 0;
}
