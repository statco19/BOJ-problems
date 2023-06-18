#include <bits/stdc++.h>

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

int number = 9999;
int primeNum[10000];
int x,y;
vt<int> adj[10000];
bool vis[10000];

void primeNumberSieve() {
    for (int i=2; i<=number; ++i) {
		primeNum[i] = i;
	}

    for (int i=2; i<=sqrt(number); ++i) {
        if (primeNum[i] == 0)
            continue;
        for (int j=i*i; j<=number; j+=i)
            primeNum[j] = 0;
    }
    return;
}

bool diffByOne(int a, int b) {
	int base = 10;
	int cnt = 0;
	while(a) {
		if(a%base != b%base) cnt++;
		a /= 10;
		b /= 10;
	}
	if(cnt == 1) return 1;
	else return 0;
}

void sol() {
	mset(vis,0);
	cin >> x >> y;

	queue<int> q;
	q.push(x);
	vis[x] = 1;
	int ans = 0;
	bool done = 0;
	while(!q.empty()) {
		int size = sz(q);
		for(int i=0,a; i<size; ++i) {
			a = q.front(); q.pop();
			if(a == y) {
				done = 1;
				break;
			}

			for(int j=0; j<sz(adj[a]); ++j) {
				int next = adj[a][j];
				if(!vis[next]) {
					vis[next] = 1;
					q.push(next);
				}
			}
		}
		if(done) break;

		ans++;
	}
	if(done) cout << ans << en;
	else cout << "Impossible" << en;

	return;
}


int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	primeNumberSieve();
	for(int i=1000; i<=number; ++i) {
		if(primeNum[i]) {
			for(int j=i+1; j<=number; ++j) {
				if(primeNum[j] && diffByOne(i,j)) {
					adj[i].pb(j);
					adj[j].pb(i);
				}
			}
		}
	}
	while(T--) {
		sol();
	}

   return 0;
}