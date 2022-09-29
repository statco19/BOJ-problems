#include <bits/stdc++.h>

#define ll long long
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vint;
const int INF = 0x3f3f3f3f; const int mINF = 0xc0c0c0c0;
const ll LINF = 0x3f3f3f3f3f3f3f3f; const ll mLINF = 0xc0c0c0c0c0c0c0c0;

int N,K;
int arr[1025];
vint nodes[1025];

void traverse(int l, int r, int depth) {
	int idx = (l+r)/2;
	nodes[depth].push_back(arr[idx]);

	if(l<idx) traverse(l, idx-1, depth+1);
	if(r>idx) traverse(idx+1,r, depth+1);
	return;
}

void sol() {
	traverse(1,N,1);
	for(int i=1;i<=K;++i) {
		for(int j=0;j<nodes[i].size();++j) {
			cout << nodes[i][j] << " ";
		}
		cout << '\n';
	}

	return;
}
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> K;
	N = pow(2,K)-1;
	for(int i=1;i<=N;++i) {
		cin >> arr[i];
	}

	sol();
	return 0;
}
