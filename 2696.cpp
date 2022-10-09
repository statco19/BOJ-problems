#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define ioa insert_or_assign
#define umap unordered_map
#define prq priority_queue
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vint;
const int INF = 0x3f3f3f3f; const int mINF = 0xc0c0c0c0;
const ll LINF = 0x3f3f3f3f3f3f3f3f; const ll mLINF = 0xc0c0c0c0c0c0c0c0;

int M;
int T;
int arr[10000];
prq<int, vint, less<int>> mxq;
prq<int, vint, greater<int>> mnq;

void sol() {
	int cnt = 0;
	cout << M/2 + 1 << '\n';
	for(int i=0;i<M;++i) {
		if(mxq.size() > mnq.size()) {
			if(!mxq.empty() && arr[i] < mxq.top()) {
				mxq.push(arr[i]);
				mnq.push(mxq.top()); mxq.pop();
			} else {
				mnq.push(arr[i]);
			}
		} else if(mxq.size() == mnq.size()) {
			if(!mxq.empty() && arr[i] > mxq.top()) {
				mnq.push(arr[i]);
				mxq.push(mnq.top()); mnq.pop();
			} else {
				mxq.push(arr[i]);
			}
		} else {
			mxq.push(arr[i]);
		}

		if(i&1^1) {
			cout << mxq.top() << " ";
			cnt++;
			if(cnt % 10 == 0) cout << '\n';
		}
	}
	cout << '\n';

	return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	while(T--) {
		cin >> M;
		memset(arr,0,sizeof(arr));
		mxq = prq<int, vint, less<int>> ();
		mnq = prq<int, vint, greater<int>> ();
		for(int i=0;i<M;++i) {
			cin >> arr[i];
		}
		
		sol();
	}

	return 0;
}