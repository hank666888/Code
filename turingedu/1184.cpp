#include <iostream>
#include <algorithm>
using namespace std;

int n, m, a[2000010], b[1000010];

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= m; i++)
		cin >> b[i];
	for (int i = n + 1; i <= n + m; i++) {
		a[i] = b[i - n];
	}
	sort(a + 1, a + 1 + (n + m));
	for (int i = n + m; i >= 1; i--)
		cout << a[i] << " ";
	return 0;
}