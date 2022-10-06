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

ll ans;
bool neg;
string s;
deque<ll> nums;
deque<char> op;

ll cal(ll a, ll b, char op) {
	if(op == '*') return a*b;
	else if(op == '/') return a/b;
	else if(op == '+') return a+b;
	else return a-b;
}

void sol() {
	if(s[0] == '-') {
		neg = 1;
		s = s.substr(1);
	}

	string n;
	for(int i=0;i<s.size();++i) {
		char c = s[i];
		if(0<=c-'0' && c-'0'<=9) {
			n += c;
		} else {
			nums.push_back(stoll(n));
			n = "";
			op.push_back(c);
		}
	}
	if(n != "") {
		nums.push_back(stoll(n));
		n = "";
	}
	if(neg) {
		nums[0] *= -1;
	}
	if(nums.size() == 1 && op.size() == 0) {
		ans = nums.front();
		return;
	}

	while(nums.size() > 2) {
		int p1=0,p2=0;
		ll res1=0,res2=0;
		char op1 = op[0];
		if(op1 == '*' || op1 == '/') p1 = 1;
		char op2 = op[op.size()-1];
		if(op2 == '*' || op2 == '/') p2 = 1;

		ll a1 = nums[0], a2 = nums[1];
		ll b1 = nums[nums.size()-2], b2 = nums[nums.size()-1];

		res1 = cal(a1,a2,op1);
		res2 = cal(b1,b2,op2);
		if(p1>p2) {
			nums.pop_front();
			nums.pop_front();
			op.pop_front();
			nums.push_front(res1);
		} else if(p2>p1) {
			nums.pop_back();
			nums.pop_back();
			op.pop_back();
			nums.push_back(res2);
		} else if(p1==p2) {
			if(res1 >= res2) {
			nums.pop_front();
			nums.pop_front();
			op.pop_front();
			nums.push_front(res1);
			} else {
				nums.pop_back();
				nums.pop_back();
				op.pop_back();
				nums.push_back(res2);
			}
		}
	}

	ll a = nums.front();
	ll b = nums.back();
	char o = op.back();
	ans = cal(a,b,o);

	return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> s;
	sol();
	cout << ans << '\n';

	return 0;
}