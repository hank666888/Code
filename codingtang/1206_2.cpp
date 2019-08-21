#include <iostream>
#include <cstring>
using namespace std;

int n, v, f[10010], w[10010], c[10010];

int main() {
	while (cin >> n >> v, n || v) {
		memset(f, 0, sizeof(f));
		for (int i=1; i<=n; i++)
			cin >> c[i] >> w[i];
		for (int i=1; i<=n; i++)
			for (int j=v; j>=c[i]; j--)
				f[j] = max(f[j], f[j-c[i]]+w[i]);
		cout << f[v] << endl;
	}
	return 0;
}