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
int maxStock;

void sol() {
	for(int i=N-1; ~i; --i) {
		if(arr[i] > maxStock) maxStock = arr[i];
		else if(arr[i] < maxStock) {
			ans += maxStock - arr[i];
		}
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
		maxStock = 0;
		memset(arr,0,sizeof(arr));
		for(int i=0;i<N;++i) {
			cin >> arr[i];
		}
		sol();
	}

	return 0;
}
