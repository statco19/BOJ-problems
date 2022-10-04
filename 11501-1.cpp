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

ll ans;
int T,N;
int arr[1000000];
int t[2000000];

void init() {
	for(int i=N-1;i>0;--i) t[i] = arr[t[i<<1]] >= arr[t[i<<1|1]] ? t[i<<1] : t[i<<1|1];
}

int qry(int l, int r) {
	int res = mINF;
	int idx;
	for(l+=N,r+=N; l<r; l>>=1,r>>=1) {
		if(l&1) {
			if(arr[t[l]] > res) {
				res = arr[t[l]];
				idx = t[l];
			}
			l++;
		}
		if(r&1) {
			--r;
			if(arr[t[r]] > res) {
				res = arr[t[r]];
				idx = t[r];
			}
		}
	}
	return idx;
}

void sol() {
	init();

	int st = 0;
	int idx = qry(st,N);
	while(1) {
		for(int i=st;i<idx;++i) {
			ans += arr[idx] - arr[i];
		}
		st = idx+1;
		if(st < N) idx = qry(st,N);
		else break;
	}
	cout << ans << '\n';

	return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	while(T--) {
		cin >> N;
		ans = 0;
		memset(t,0,sizeof(t));
		memset(arr,0,sizeof(arr));
		for(int i=0;i<N;++i) {
			cin >> arr[i];
			t[i+N] = i;
		}
		sol();
	}

	return 0;
}
