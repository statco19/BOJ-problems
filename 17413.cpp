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

void sol() {
	stack<char> st;
	queue<char> q;

	string s;
	getline(cin, s);
	bool tag = 0;
	for(int i=0; i<sz(s); ++i) {
		if(tag) {
			q.push(s[i]);
			if(s[i] == '>') {
				while(!q.empty()) {
					cout << q.front();
					q.pop();
				}
				tag = 0;
			}
		} else {
			if(s[i] == '<') {
				while(!st.empty()) {
					cout << st.top();
					st.pop();
				}

				q.push(s[i]);
				tag = 1;
			} else {
				if(s[i] == ' ') {
					while(!st.empty()) {
						cout << st.top();
						st.pop();
					}
					cout << ' ';
				} else {
					st.push(s[i]);
				}
			}
		}
	}

	if(tag) {
		while(!q.empty()) {
			cout << q.front();
			q.pop();
		}
	} else {
		while(!st.empty()) {
			cout << st.top();
			st.pop();
		}
	}
	cout << en;

	return;
}


int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);

	while(T--) {
		sol();
	}

   return 0;
}