#include <bits/stdc++.h>

#define ll long long
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vint;
const int INF = 0x3f3f3f3f; const int mINF = 0xc0c0c0c0;
const ll LINF = 0x3f3f3f3f3f3f3f3f; const ll mLINF = 0xc0c0c0c0c0c0c0c0;

int N,M;
int ans;
bool possible;
int clauses[101][2];
int var;
vint v;

bool check() {
	int res = 1;
	int x=0,y=0;
	for(int i=0;i<M;++i) {
		x = clauses[i][0];
		y = clauses[i][1];

		int a,b;
		if(x<0 && y<0) {
			a = !((var & (1<<(-x)))>>(-x));
			b = !((var & (1<<(-y)))>>(-y));
			res &= a|b;
		} else if(x<0 && y>0) {
			a = !((var & (1<<(-x)))>>(-x));
			b = ((var & (1<<y)) >> y);
			res &= a|b;
		} else if(x>0 && y<0) {
			a = ((var & (1<<x)) >> x);
			b = !((var & (1<<(-y)))>>(-y));
			res &= a|b;
		} else if(x>0 && y>0) {
			a = ((var & (1<<x)) >> x);
			b = ((var & (1<<y)) >> y);
			res &= a|b;
		}
	}

	return res;
}

void dfs(int idx) {
	if(idx == N+1) {
		if(check()) {
			ans = 1;
			v.resize(N+1);
			for(int i=1;i<=N;++i) {
				v[i] = ((var & (1<<i))>>i);
			}
		}
		return;
	}

	for(int i=0;i<=1;++i) {
		if(i==0) {
			var &= ~(1<<idx);
			dfs(idx+1);
			var |= (1<<idx);
		} else {
			var |= (1<<idx);
			dfs(idx+1);
			var &= ~(1<<idx);
		}

		if(ans) break;
	}

	return;
}

void sol() {
	dfs(1);

	return;
}
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	for(int i=0;i<M;++i) {
		cin >> clauses[i][0] >> clauses[i][1];
	}

	sol();
	cout << ans <<'\n';
	if(ans) {
		for(int i=1;i<=N;++i) {
			cout << v[i] << " ";
		}
		cout << '\n';
	}
	return 0;
}
