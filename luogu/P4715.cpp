#include <iostream>
using namespace std;

int n, m, a[1010], mx_1, mx_2, ans_1, ans_2;

int main() {
	cin >> n;
	m = 1<<n;
	for (int i=1; i<=m; i++) cin >> a[i];
	for (int i=1; i<=m/2; i++) {
		if (mx_1 < a[i]) {
			mx_1 = a[i];
			ans_1 = i;
		}
	}
	for (int i=m/2+1; i<=m; i++) {
		if (mx_2 < a[i]) {
			mx_2 = a[i];
			ans_2 = i;
		}
	}
	cout << (mx_1<mx_2 ? ans_1 : ans_2) << endl;
	return 0;
}