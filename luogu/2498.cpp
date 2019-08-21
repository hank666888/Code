#include <iostream>
using namespace std;

int l, n, a[10010], ans1, ans2;

int main() {
	cin >> l >> n;
	for (int i=1; i<=n; i++)
		cin >> a[i];
	for (int i=1; i<=n; i++) {
		ans1 = max(ans1, min(l-a[i], a[i]));
		ans2 = max(ans2, max(l-a[i], a[i]));
	}
	cout << ans1 << " " << ans2 << endl;
	return 0;
}