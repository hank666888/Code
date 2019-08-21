#include <iostream>
using namespace std;

int n, m, f[55][55][3001], x;

int main() {
	cin >> n >> m;
	f[0][1][3000] = 1;
	for (int i = 1; i <= n; i++) {
		f[n][1][3000] = 1;
		for (int j = 1; j <= m; j++) {
			x = 0;
			for (int k = 3000; k >= 1; k--) {
				f[i][j][k] = f[i-1][j][k] + f[i][j-1][k] + x;
				x = f[i][j][k] / 10;
				f[i][j][k] = f[i][j][k] % 10;
			}
		}
	}
	/*x = 0;
	for (int k = 3000; k >= 1; k--) {
		f[1][m][k] = f[1][m][k] + f[1][m][k] + x;
		x = f[1][m][k] / 10;
		f[1][m][k] = f[1][m][k] % 10;
	}*/
	int h = 0;
	while (f[n][m][h] == 0) h++;
	for (int i = h; i <= 3000; i++)
		cout << f[n][m][i];
	return 0;
}