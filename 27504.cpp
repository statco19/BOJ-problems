#include <bits/stdc++.h>

#define vt vector
#define en '\n'
#define ll long long
#define ld long double
#define pb push_back
#define pii pair<int,int>
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rev(c) (c).rbegin(), (c).rend()
#define mid (st+end)/2

using namespace std;
const int INF = 0x3f3f3f3f; const int mINF = 0xc0c0c0c0;
const ll LINF = 0x3f3f3f3f3f3f3f3f; const ll mLINF = 0xc0c0c0c0c0c0c0c0;
int T = 1;

typedef vector<int> seq_t;

void calculate_pi(vector<int>& pi, const seq_t& str) {
	pi[0] = -1;
	for (int i = 1, j = -1; i < str.size(); i++) {
		while (j >= 0 && str[i] != str[j + 1]) j = pi[j];
		if (str[i] == str[j + 1])
			pi[i] = ++j;
		else
			pi[i] = -1;
	}
}

vector<int> kmp(const seq_t& text, const seq_t& pattern) {
	vector<int> pi(pattern.size()), ans;
	if (pattern.size() == 0) return ans;
	calculate_pi(pi, pattern);
	for (int i = 0, j = -1; i < text.size(); i++) {
		while (j >= 0 && text[i] != pattern[j + 1]) j = pi[j];
		if (text[i] == pattern[j + 1]) {
			j++;
			if (j + 1 == pattern.size()) {
				ans.push_back(i - j);
				j = pi[j];
			}
		}
	}
	return ans;
}

void sol() {
	int N;
	cin >> N;
	vt<seq_t> v;
	for(int i=0; i<N; ++i) {
		int c;
		cin >> c;
		seq_t u(c);
		for(auto& x : u) cin >> x;

		seq_t r;
		for(int j=0; j<c-1; ++j) {
			r.pb(u[j+1]-u[j]);
		}
		v.pb(r);
	}

	int L;
	cin >> L;
	seq_t a(L);
	for(auto& x : a) cin >> x;
	seq_t b;
	for(int i=0; i<L-1; ++i) {
		b.pb(a[i+1]-a[i]);
	}

	vt<int> ans;
	for(int i=0; i<N; ++i) {
		seq_t t = kmp(v[i], b);
		if(sz(t) > 0) {
			ans.pb(i+1);
		}
	}

	if(sz(ans) == 0) cout << -1 << en;
	else {
		for(auto& x : ans) cout << x << ' ';
		cout << en;
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	while(T--) {
		sol();
	}

	return 0;
}