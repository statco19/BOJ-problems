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

int L,P,V;
int ans;

void sol() {
	ans = (V/P) * L;
	if(V%P >= L) ans += L;
	else ans += V%P;

	return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n = 1;
	while(1) {
		cin >> L >> P >> V;
		if(!L&&!P&&!V) break;
		ans = 0;
		sol();
		cout << "Case " << n << ": " << ans << '\n';
		n++;
	}

	return 0;
}
