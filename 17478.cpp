#include <bits/stdc++.h>

#define vt vector
#define en '\n'
#define ll long long
#define ull unsigned long long
#define ld long double
#define ioa insert_or_assign
#define umap unordered_map
#define prq priority_queue
#define pb push_back
#define pii pair<int,int>
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rev(c) (c).rbegin(), (c).rend()
#define mset(ar, val) memset(ar, val, sizeof(ar))

using namespace std;
const int d4r[4] = {-1,0,1,0}; const int d4c[4] = {0,1,0,-1};
const int d8r[8] = {-1,-1,0,1,1,1,0,-1}; const int d8c[8] = {0,1,1,1,0,-1,-1,-1};
const int INF = 0x3f3f3f3f; const int mINF = 0xc0c0c0c0;
const ll LINF = 0x3f3f3f3f3f3f3f3f; const ll mLINF = 0xc0c0c0c0c0c0c0c0;
int T = 1;

int N;

void underscore(int n) {
	for(int i=0; i<2*n; ++i) {
		cout << "_";
	}
}

void func(int n) {
	int x = N-n;
	underscore(2*x);
	cout << "\"재귀함수가 뭔가요?\"" << en;
	if(n == 0) {
		underscore(2*x);
		cout << "\"재귀함수는 자기 자신을 호출하는 함수라네\"" << en;
	} else {
		underscore(2*x);
		cout << "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어." << en;
		underscore(2*x);
		cout << "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지." << en;
		underscore(2*x);
		cout << "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"" << en;
		func(n-1);
	}
	underscore(2*x);
	cout << "라고 답변하였지." << en;

	return;
}
void sol() {
	cin >> N;

	cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다." << en;
	func(N);

	return;
}


int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);

	while(T--) {
		sol();
	}

   return 0;
}