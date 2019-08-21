#include <iostream>
using namespace std;

const int INF = 1e9;

int n, sum, a[10010], b[10010], f[10010], g[10010], ans1 = -INF, ans1 = -INF;
bool flag;

int main() {
	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		b[i] = -a[i];
		if (a[i] > 0)
			flag = true;
		sum += a[i];
	}
	for (int i=1; i<=n; i++) {
		f[i] = max(f[i-1]+a[i], a[i]);
		g[i] = max(g[i-1]+b[i], b[i]);
		ans1 = max(ans1, f[i]);
		ans2 = max(ans2, g[i]);
	}
	if (flag) cout << max(ans1, sum+ans2);
	else cout << ans1 << endl;
	return 0;
}