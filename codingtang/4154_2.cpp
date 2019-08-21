#include <iostream>
using namespace std;

int n, a[11][11], f[31][11][11];

int main() {
	cin >> n;
	int x, y, z;
	while (cin >> x >> y >> z, x && y && z) a[x][y] = z;
	for (int i=1; i<=2*n-1; i++)
		for (int j=1; j<=n; j++)
			for (int k=1; k<=n; k++) {
				f[i][j][k] = max(max(f[i-1][j-1][k-1], f[i-1][j][k-1]), max(f[i-1][j-1][k], f[i-1][j][k]));
				f[i][j][k] += a[j][i-j+1];
				if (j != k) f[i][j][k] += a[k][i-k+1];
			}
	cout << f[2*n-1][n][n] << endl;
	return 0;
}