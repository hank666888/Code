#include <iostream>
using namespace std;

int f[10001][3001];
int n,x;

int main() {
	cin >> n;
	f[1][3000] = 1;
	f[2][3000] = 2;
	f[3][3000] = 4;
	for (int i = 4; i <= n; i++) {
		x = 0;
		for (int j = 3000; j >= 1; j--) {
			f[i][j] = f[i-3][j] + f[i-2][j] + f[i-1][j] + x;
			x = f[i][j] / 10;
			f[i][j] = f[i][j] % 10;
		}
	}
	int h = 0;
	while(f[n][h] == 0) h++;
	for (int i = h; i <= 3000; i++)
		cout << f[n][i];
	return 0;
}