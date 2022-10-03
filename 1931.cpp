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
int N;
vector<pii> arr;

int cmp(pii &a, pii &b) {
	if(a.second < b.second) return 1;
	else if(a.second > b.second) return 0;
	else return a.first <= b.first;
}

void sol() {
	sort(arr.begin(), arr.end(), cmp);
	int e = 0;
	for(int i=0;i<N;++i) {
		pii p = arr[i];
		if(p.first >= e) {
			e = p.second;
			ans++;
		}
	}
	cout << ans << '\n';

	return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	arr.resize(N);
	int s,e;
	for(int i=0;i<N;++i) {
		cin >> s >> e;
		arr[i] = {s,e};
	}
	sol();

	return 0;
}
