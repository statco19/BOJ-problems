#include <bits/stdc++.h>
using namespace std;

#define vt vector
#define ll long long
#define pb push_back
#define pf push_front
#define all(c) (c).begin(), (c).end()
#define rev(c) (c).rbegin(), (c).rend()
#define sz(x) (int)(x).size()
#define mset(ar, val) memset(ar, val, sizeof(ar))
#define vi vector<int>
#define vvi vector<vector<int>>
#define vll vector<long long>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define en '\n'
#define ioa insert_or_assign
#define umap unordered_map
#define prq priority_queue
#define F first
#define S second

#define F_OR(i, a, b, s) for (int i=(a); (s)>0?i<(b):i>(b); i+=(s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)

#define E_ACH2(x, a) for (auto &x : a)
#define E_ACH3(x, y, a) for (auto &[x, y] : a)
#define E_ACH4(x, y, z, a) for (auto &[x, y, z] : a)
#define E_ACHC(...) GET5(__VA_ARGS__, E_ACH4, E_ACH3, E_ACH2)
#define EACH(...) E_ACHC(__VA_ARGS__)(__VA_ARGS__)

string to_string(char c) {
    return string(1, c);
}
string to_string(bool b) {
    return b?"true":"false";
}
string to_string(const char* s) {
    return string(s);
}
string to_string(string s) {
    return s;
}
string to_string(vt<bool> v) {
    string res;
    FOR(sz(v))
        res+=char('0'+v[i]);
    return res;
}

vector<string> split (const string &s, char delim) {
    vector<string> result;
    stringstream ss (s);
    string item;

    while (getline (ss, item, delim)) {
        result.push_back (item);
    }

    return result;
}

vector<string> split (const string &s, string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> res;

    while ((pos_end = s.find (delimiter, pos_start)) != string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr (pos_start));
    return res;
}

const int d4r[4] = {-1,0,1,0}; const int d4c[4] = {0,1,0,-1};
const int d8r[8] = {-1,-1,0,1,1,1,0,-1}; const int d8c[8] = {0,1,1,1,0,-1,-1,-1};
const int INF = 0x3f3f3f3f; const int mINF = 0xc0c0c0c0;
const ll LINF = 0x3f3f3f3f3f3f3f3f; const ll mLINF = 0xc0c0c0c0c0c0c0c0;
int T = 1;

const int mod = 1e9;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a%b); }

vt<int> getFactors(int x) {
    vt<int> v;
    int y = x;
    for (ll i = 2; i*i <= x; ++i) {
        //cout << y % i << en;
        while (y % i == 0) {
            v.pb((int)i);
            y /= i;
        }
    }
    if (y != 1) v.pb(y);

    return v;
}

void sol() {
    int N, M;
    cin >> N;

    vt<int> v(N);
    unordered_map<int, int> um1;  // {prime, exp_cnt}
    for (int &x : v) cin >> x;
    for (int i = 0; i < v.size(); ++i) {
        vt<int> fac = getFactors(v[i]);
        for (int p : fac) {
            um1[p]++;
        }
    }

    cin >> M;
    v.resize(M);
    unordered_map<int, int> um2;
    for (int &x : v) cin >> x;
    for (int i = 0; i < v.size(); ++i) {
        vt<int> fac = getFactors(v[i]);
        for (int p : fac) {
            um2[p]++;
        }
    }

    bool overflow = 0;
    ll g = 1LL;
    for (auto p = um1.begin(); p != um1.end(); ++p) {
        int fac = p->first;
        if (um2.find(fac) != um2.end()) {
            auto q = um2.find(fac);
            for (int i = 0; i < min(p->second, q->second); ++i) {
                if (g * fac >= 1e9) overflow = 1;
                g = g % mod * fac % mod;
            }
        }
    }

    if (overflow) {
        string s = to_string(g % mod);
        for (int i = 0; i + s.size() < 9; ++i) {
            cout << '0';
        }
        cout << s << en;
    }
    else {
        cout << g % mod << en;
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
