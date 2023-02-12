#include <bits/stdc++.h>

#define vt vector
#define en '\n'
#define ll long long
#define ld long double
#define pb push_back
#define pii pair<int,int>
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define mid (st+end)/2

using namespace std;
const int INF = 0x3f3f3f3f; const int mINF = 0xc0c0c0c0;
const ll LINF = 0x3f3f3f3f3f3f3f3f; const ll mLINF = 0xc0c0c0c0c0c0c0c0;
int T = 1;

int N,Q;
ll a[101010];
ll arr[101010], lazy[404040], tree[404040];

void init(int node, int st, int end) {
	if(st == end) {
		tree[node] = arr[st];
	} else {
		init(node*2, st, mid);
		init(node*2+1, mid+1, end);
		tree[node] = tree[node*2] + tree[node*2+1];
	}
	return;
}

void update_lazy(int node, int st, int end) {
	if(lazy[node] != 0) {
		tree[node] += (end-st+1)*lazy[node];
		if(st != end) {
			lazy[node*2] += lazy[node];
			lazy[node*2+1] += lazy[node];
		}

		lazy[node] = 0;
	}

	return;
}

void update_range(int node, int st, int end, int left, int right, ll diff) {
	update_lazy(node, st, end);
	if(left > end || right < st) {
		return;
	}

	if(left<=st && end<=right) {
		tree[node] += (end-st+1)*diff;
		if(st != end) {
			lazy[node*2] += diff;
			lazy[node*2+1] += diff;
		}
		return;
	}

	update_range(node*2, st, mid, left, right, diff);
	update_range(node*2+1, mid+1, end, left, right, diff);
	tree[node] = tree[node*2] + tree[node*2+1];

	return;
}

ll query(int node, int st, int end, int left, int right) {
	update_lazy(node, st, end);
	if(left > end || right < st) {
		return 0;
	}

	if(left<=st && end<=right) {
		return tree[node];
	}

	ll lsum = query(node*2, st, mid, left, right);
	ll rsum = query(node*2+1, mid+1, end, left, right);

	return lsum + rsum;
}

void sol() {
	cin >> N;
	for(int i=1; i<=N+1; ++i) {
		if(i<=N) cin >> a[i];
		arr[i] = a[i] - a[i-1];
	}
	init(1,1,N+1);

	cin >> Q;
	int a;
	ll x,y;
	for(int i=0; i<Q; ++i) {
		cin >> a;
		if(a == 1) {
			cin >> x >> y;
			update_range(1,1,N+1,x,y,1);
			update_range(1,1,N+1,y+1,y+1, -(y-x+1));
		} else {
			cin >> x;
			cout << query(1,1,N+1,1,x) << en;
		}
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