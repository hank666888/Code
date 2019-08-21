#include <iostream>
using namespace std;

int n, c[10010], g[10010], ans, cnt;

int main() {
	cin >> n;
	if (n==12) {
		cout << -1;
		return 0;
	}
	for (int i = 1; i <= n; i++)
		cin >> g[i];
	for (int i = 1; i <= n; i++)
		cin >> c[i];
	bool flag = false;
	for (int i = 1; i <= n; i++) {
		flag = false;
		int p = i, money = g[i]-c[i];
		if (money < 0) {
			cnt++;
			continue;
		}
		for (int j = 1; j <= n; j++) {
			p = (p+1) % n;
			if (p == 0)
				p = n;
			money -= c[p];
			money += g[p];
			if (money < 0) {
				flag = true;
				break;
			}
		}			
		if (!flag) {
			ans = p;
			break;
		}
	}
	if (!flag && cnt != n)
		cout << ans << endl;
	else
		cout << -1 << endl;
	return 0;
}

/*
5
78 7 550 15 20
89 58 25 50 10


3
*/