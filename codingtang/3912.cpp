#include <iostream>
using namespace std;

int n, a[10010], i=1, ans, f[10010];

int main() {
	while (cin >> a[i]) {
		f[i] = 1;
		for (int j=1; j<i; j++)
			if (a[i] <= a[j] && f[j]+1 > f[i])
				f[i] = f[j]+1;
		ans = max(f[i], ans);
		i++;
	}
	cout << ans << endl;
	return 0;
}	