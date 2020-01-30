#include <iostream>
using namespace std;

int n, m, k, d[1010][1010];

int main() {
	cin >> n >> m >> k;
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++) {
			int x;
			cin >> x;
			d[x][j] ++;
		}
	for (int i=1; i<=k; i++) {
		int ans = 0;
		for (int j=1; j<=m; j++)
			if (d[i][j]) ans ++;
		cout << ans << " ";
	}
	cout << endl;
	return 0;
}