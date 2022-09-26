#include <bits/stdc++.h>

#define ll long long
using namespace std;
typedef pair<int,int> pint;
typedef vector<int> vint;
const int INF = 0x3f3f3f3f; const int mINF = 0xc0c0c0c0;
const ll LINF = 0x3f3f3f3f3f3f3f3f; const ll mLINF = 0xc0c0c0c0c0c0c0c0;

int N,P;
stack<int> lines[7];
int ans;

void sol() {
	int l,f;
	for(int i=0;i<N;++i) {
		cin >> l >> f;
		if(lines[l].empty()) {
			lines[l].push(f);
			ans++;	
		} else {
			while(!lines[l].empty() && lines[l].top() > f) {
				lines[l].pop();
				ans++;
			}
			if(!lines[l].empty() && lines[l].top() == f) continue;
			lines[l].push(f);
			ans++;
		}
	}

	return;
}
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> P;

	sol();
	cout << ans << '\n';
	return 0;
}
