#include <iostream>
using namespace std;

const int INF = 1e9;
long long n, m, a[1010][1010], f[1010], b[1010], ans = -INF, sum[1010][1010];

int main() {
	cin >> n >> m;
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++) {
			cin >> a[i][j];
			if (a[i][j] == 0)
				a[i][j] = -INF;
			sum[j][i] = sum[j][i-1]+a[i][j];
		}
	for (int i=1; i<=n; i++)
		for (int j=i; j<=n; j++) 
			for (int k=1; k<=m; k++) {
				b[k] = sum[k][j]-sum[k][i-1];
				f[k] = max(b[k], f[k-1]+b[k]);
				ans = max(ans, f[k]);
			}
	if (ans < 0) ans = 0;
	cout << ans << endl;
	return 0;
}