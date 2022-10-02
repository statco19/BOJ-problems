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
vint arr;
int N;

void sol() {
	sort(arr.begin(), arr.end());
	for(int i=arr.size()-1; ~i; --i) {
		if(arr[i] * (N-i) > ans) {
			ans = arr[i] * (N-i);
		}
	}
	cout << ans << '\n';

	return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	arr.resize(N);
	for(int i=0;i<N;++i) {
		cin >> arr[i];
	}
	sol();

	return 0;
}
