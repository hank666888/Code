#include <iostream>
using namespace std;

int n, v, f[100010], w[10010];

int main() {
	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> w[i];
		v += w[i];
	}
	for (int i=1; i<=n; i++)
		for (int j=v/2; j>=w[i]; j--)
			f[j] = max(f[j], f[j-w[i]]+w[i]);
	cout << v-2*f[v/2] << endl;
	return 0;
}