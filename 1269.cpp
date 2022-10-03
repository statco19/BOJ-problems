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

int ans;
int A,B;
int ar[200000], br[200000];
umap<int,int> am, bm, um;
vint v;

void sol() {
	for(int i=0;i<A;++i) {
		if(bm.find(ar[i]) == bm.end()) {
			um.ioa(ar[i],1);
		}
	}
	for(int i=0;i<B;++i) {
		if(am.find(br[i]) == am.end()) {
			um.ioa(br[i],1);
		}
	}
	ans = um.size();
	cout << ans << '\n';

	return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> A >> B;
	int x;
	for(int i=0;i<A;++i) {
		cin >> x;
		am.ioa(x,1);
		ar[i] = x;
	}

	for(int i=0;i<B;++i) {
		cin >> x;
		bm.ioa(x,1);
		br[i] = x;
	}
	sol();

	return 0;
}
