#include <iostream>
using namespace std;

int n, m, f[1010][1010], a[1010], b[1010], ans;

int main() {
	cin >> m;
	for (int i=1; i<=m; i++)
		cin >> a[i];
	cin >> n;
	for (int j=1; j<=n; j++)
		cin >> b[j];
	for (int i=1; i<=m; i++) {
		for (int j=1; j<=n; j++) {
			if (a[i] == b[j]) {
				int res = 0;
				for (int k=1; k<j; k++) 
					if (b[k] < b[j]) res = max(res, f[i-1][k]);
				f[i][j] = res+1;
			}
			else f[i][j] = f[i-1][j];
		}
	}
	for (int j=1; j<=n; j++)
		ans = max(ans, f[m][j]);
	cout << ans << endl;
	return 0;
}