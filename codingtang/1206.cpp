#include <iostream>
#include <cstring>
using namespace std;

int n, v, c[1010], w[1010], f[1010][1010];

int main() {
	while (cin >> n >> v, n || v) {
		for (int i = 1; i <= n; i++)
			cin >> c[i] >> w[i];
		for (int i = 1; i <= n; i++)
			for (int j = 0; j <= v; j++)
				if (j < c[i])
					f[i][j] = f[i-1][j];
				else
					f[i][j] = max(f[i-1][j], f[i-1][j-c[i]] + w[i]);
		cout << f[n][v] << endl;
		memset(f, 0, sizeof(f));
	}
	return 0;
}