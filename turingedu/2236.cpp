#include <iostream>
#include <algorithm>
using namespace std;

int n, m, t[100010], q[100010], ans, s[100010], x;

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> t[i];
	for (int i = 1; i <= n; i++) {
		x = 1;
		for (int j = 2; j <= m; j++) {
			if (s[x] > s[j])
				x = j;
		}
		s[x] = s[x] + t[i];
	}
	for (int i = 1; i <= m; i++)
		ans = max(ans, s[i]);
	cout << ans << endl;
	return 0;
}
