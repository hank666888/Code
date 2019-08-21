#include <iostream>
using namespace std;

int f[11][11][11][11], a[11][11], n;

int main() {
	cin >> n;
	int x, y, z;
	while (cin >> x >> y >> z, x && y && z) a[x][y] = z;
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			for (int k=1; k<=n; k++)
				for (int l=1; l<=n; l++) {
					f[i][j][k][l] = max(max(f[i-1][j][k-1][l], f[i-1][j][k][l-1]), max(f[i][j-1][k-1][l], f[i][j-1][k][l-1]))+a[i][j];
					if (i != k || j != l) f[i][j][k][l] += a[k][l];
				}
	cout << f[n][n][n][n] << endl;
	return 0;
}