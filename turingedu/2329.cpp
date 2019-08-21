#include <iostream>
using namespace std;

int n, k, a[10010], s[10010];
bool flag;

int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s[i] = s[i-1] + a[i];
	}
	for (int i = 0; i <= n-1; i++) {
		for (int j = 2; j <= n; j++) {
			if (s[j] - s[i] == k) {
				flag = true;
				cout << i+1 << " " << j << endl;
				break;
			}
		}
		if (flag)
			break;
	}
	if (!flag)
		cout << "No Solution" << endl;
	return 0;
}