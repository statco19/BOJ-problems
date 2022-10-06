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

int T,n;
string p;
string ar;
vint v;
int position;  // 0: head, 1: tail
int l,r;

vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;
 
    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }
 
    return answer;
}

void sol() {
	string s = "";
	s = ar.substr(1,ar.size()-2);
	vector<string> nums = split(s,',');
	for(string str : nums) {
		v.pb(stoi(str));
	}

	for(int i=0;i<p.size();++i) {
		char c = p[i];
		if(c == 'R') {
			position ^= 1;
		} else if(c == 'D') {
			if(position == 0) {  // head
				l++;
			} else if(position == 1) {  // tail
				r--;
			}
			if(l>r) {
				cout << "error" << '\n';
				return;
			}
		}
	}
	
	cout << "[";	
	if(position == 0) {
		for(int i=l;i<r;++i) {
			cout << v[i];
			if(i < r-1) {
				cout << ",";
			}
		}
	} else if(position == 1) {
		for(int i=r-1;i>=l;--i) {
			cout << v[i];
			if(i > l) {
				cout << ",";
			}
		}
	}
	cout << "]" << '\n';

	return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	while(T--) {
		cin >> p;
		cin >> n;
		cin >> ar;
		v = vint();
		position = 0;
		l = 0; r = n;
		sol();
	}

	return 0;
}