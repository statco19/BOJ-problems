#include <bits/stdc++.h>
using namespace std;

void sol() {
	int n;
	cin >> n;
	int ans = 0;
	if(n % 5 == 0) {
		ans = n / 5;
		cout << ans << '\n';
		return;
	}

	while(n % 5) {
		n -= 2;
		ans++;
	}
	ans += n / 5;
	if(n < 0) {
		ans = -1;
		cout << ans << '\n';
		return;
	}
	n %= 5;
	if(n > 0) {
		ans = -1;
		cout << ans << '\n';
		return;
	}

	cout << ans << '\n';

	return;	
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	sol();

	return 0;
}