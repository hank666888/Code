#include <iostream>
using namespace std;

int n, m, a[55][55];

int main() {
	cin >> m >> n;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
	int sum = m, i = 0, j = 0;
	for (i = 0; i < m; i++) {
		bool change = (a[i][0] == 0);
		for (j = 0; j < n; j++) {
			if (change)
				a[i][j] = !a[i][j];
		}
	}
	for (j = 1; j < n; j++) {
		int cnt = 0;
		for (i = 0; i < m; i++) {
			if (a[i][j] == 1)
				cnt++;
		}
		int val = max(cnt, i-cnt);
		sum = sum*2+val;
	}
	cout << sum;
	return 0;
}