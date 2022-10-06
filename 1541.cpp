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

string s;
int ans;

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
	vector<string> v = split(s,'-');
	int sum;
	for(int i=0;i<v.size();++i) {
		vector<string> add = split(v[i], '+');
		sum = 0;
		for(int j=0;j<add.size();++j) {
			sum += stoi(add[j]);
		}
		if(i > 0) {
			ans -= sum;
		} else {
			ans += sum;
		}
	}
	cout << ans << '\n';

	return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> s;
	sol();

	return 0;
}