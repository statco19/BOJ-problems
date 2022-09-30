#include <bits/stdc++.h>

#define ll long long
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vint;
const int INF = 0x3f3f3f3f; const int mINF = 0xc0c0c0c0;
const ll LINF = 0x3f3f3f3f3f3f3f3f; const ll mLINF = 0xc0c0c0c0c0c0c0c0;

int T,n;
int preorder[1001], inorder[1001];

void construction(int preIdx, int l, int r) {
	for(int i=l;i<r;++i) {
		if(inorder[i] == preorder[preIdx]) {
			construction(preIdx+1, l, i);
			construction(preIdx+i+1-l, i+1, r);
			cout << preorder[preIdx] << " ";
		}
	}
}

void sol() {
	construction(1,1,n+1);
	cout << '\n';

	return;
}
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	while(T--) {
		cin >> n;
		memset(preorder,0,sizeof(preorder));
		memset(inorder,0,sizeof(inorder));
		for(int i=1;i<=n;++i) {
			cin >> preorder[i];
		}
		for(int i=1;i<=n;++i) {
			cin >> inorder[i];
		}
		sol();
	}

	return 0;
}
