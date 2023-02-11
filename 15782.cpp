#include <bits/stdc++.h>

#define vt vector
#define en '\n'
#define ll long long
#define ld long double
#define pb push_back
#define pii pair<int,int>
#define sz(x) (x).size()
#define all(x) (x).begin(), (x).end()
#define mid (st+end)/2

using namespace std;
const int INF = 0x3f3f3f3f; const int mINF = 0xc0c0c0c0;
const ll LINF = 0x3f3f3f3f3f3f3f3f; const ll mLINF = 0xc0c0c0c0c0c0c0c0;
int T = 1;


int N,M;
int l[100001], r[100001];
vt<int> adj[100001];
int arr[100001];
int tree[400004];
int lazy[400004];
bool vis[100001];

void init(int node, int st, int end) {
	if(st == end) {
		tree[node] = arr[st];
	} else {
		init(node*2, st, mid);
		init(node*2+1, mid+1, end);
		tree[node] = tree[node*2] ^ tree[node*2+1];
	}
	return;
}

void update_lazy(int node, int st, int end) {
	if(lazy[node] != 0) {
		if( (end-st+1) & 1 ) {
			tree[node] ^= lazy[node];
		}
		if(st != end) {
			lazy[node*2] ^= lazy[node];
			lazy[node*2+1] ^= lazy[node];
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
		if( (end-st+1) & 1 ) {
			tree[node] ^= diff;
		}
		if(st != end) {
			lazy[node*2] ^= diff;
			lazy[node*2+1] ^= diff;
		}
		return;
	}

	update_range(node*2, st, mid, left, right, diff);
	update_range(node*2+1, mid+1, end, left, right, diff);
	tree[node] = tree[node*2] ^ tree[node*2+1];

	return;
}

int query(int node, int st, int end, int left, int right) {
	update_lazy(node, st, end);
	if(left > end || right < st) {
		return 0;
	}

	if(left<=st && end<=right) {
		return tree[node];
	}

	int lxor = query(node*2, st, mid, left, right);
	int rxor = query(node*2+1, mid+1, end, left, right);

	return lxor ^ rxor;
}

void dfs(int x, int &o) {
	l[x] = ++o;
	for(int next : adj[x]) {
		if(!vis[next]) {
			vis[next] = 1;
			dfs(next, o);
		}
	}
	r[x] = o;
}

void sol() {
	cin >> N >> M;
	int a,b;
	for(int i=1; i<=N-1; ++i) {
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	int o = 0;
	vis[1] = 1;
	dfs(1,o);

	for(int i=1; i<=N; ++i) {
		cin >> arr[l[i]];
	}
	init(1,1,N);

	int x,y;
	for(int i=0; i<M; ++i) {
		cin >> a;
		if(a == 1) {
			cin >> x;
			cout << query(1,1,N,l[x],r[x]) << en;
		} else {
			cin >> x >> y;
			update_range(1,1,N,l[x],r[x],y);
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