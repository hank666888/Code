#include <iostream>
using namespace std;

long long n, a[1010], ans = 1e9, s;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++) {
		s = 0;
		for (int j = 1; j <= n; j++) {
			if (j >= i)
				s += (j-i) * a[j];
			else
				s += (n-i+j) * a[j];
		}
		ans = min(ans, s);
	}
	cout << ans << endl;
	return 0;
}