#include <bits/stdc++.h>

#define ll long long
using namespace std;
typedef pair<int,int> pint;
typedef vector<int> vint;
const int INF = 0x3f3f3f3f; const int mINF = 0xc0c0c0c0;
const ll LINF = 0x3f3f3f3f3f3f3f3f; const ll mLINF = 0xc0c0c0c0c0c0c0c0;

int N;
double ans;
stack<double> st;
string str;
int arr[26];

double cal(double a, double b, char c) {
	double res;
	if(c == '*') {
		res = a*b;
	} else if(c == '+') {
		res = a+b;
	} else if(c == '/') {
		res = a/b;
	} else if (c == '-') {
		res = a-b;
	}
	return res;
}

void sol() {
	for(int i=0;i<str.size();++i) {
		char c = str[i];
		int idx = c-'A';
		if(0<=idx&&idx<=25) {
			st.push(arr[idx]);
		} else {
			if(st.size() >= 2) {
				double b = st.top(); st.pop();
				double a = st.top(); st.pop();

				double res = cal(a,b,c);
				st.push(res);
			}
		}
	}

	ans = st.top();

	return;
}
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> str;
	for(int i=0;i<N;++i) {
		cin >> arr[i];
	}

	sol();
	cout << fixed;
	cout.precision(2);
	cout << ans << '\n';
	return 0;
}
