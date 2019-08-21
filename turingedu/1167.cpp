#include <iostream>
using namespace std;

int f[5001][5001];
int n,x;

int main() {
	cin >> n;
	f[1][5000] = 1;
	f[2][5000] = 2;
	for (int i = 3; i <= n; i++) {
		x = 0;
		for (int j = 5000; j >= 1; j--) {
			f[i][j] = f[i-2][j] + f[i-1][j] + x;
			x = f[i][j] / 10;
			f[i][j] = f[i][j] % 10;
		}
	}
	int h = 0;
	while(f[n][h] == 0) h++;
	for (int i = h; i <= 5000; i++)
		cout << f[n][i];
	return 0;
}