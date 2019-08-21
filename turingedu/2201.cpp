#include <iostream>
#include <algorithm>
using namespace std;

int n, m, t[100010], q[100010], ans, s[100010];

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> t[i];
	sort(t+1, t+1+n);
	for (int i = 1; i <= n; i++) {
		int point = i % m;
		if (point == 0)
			point = m;
		s[point] = s[point] + t[i];
		ans = ans + s[point];
	}
	cout << ans << endl;
	return 0;
}