#include <iostream>
using namespace std;

int f[201][101], n, x;

int main() {
	cin >> n;
	f[1][100] = 2;
	for (int i = 2; i <= n; i++) {
		f[i][100] = 2;
		x = 0;
		for (int j = 100; j >= 1; j--) {
			f[i][j] = f[i][j] + f[i-1][j] + f[i-1][j] + x;
			x = f[i][j] / 10;
			f[i][j] = f[i][j] % 10;
		}
	}
	int h = 0;
	while(f[n][h] == 0) h++;
	for (int i = h; i <= 100; i++)
		cout << f[n][i];
	return 0;
}