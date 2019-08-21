#include <iostream>
#include <cmath>
using namespace std;

int n, a[110]; 

int change(int first, int last) {
	int ret = 0;
	for (int i = last; i >= first; i--)
		ret += a[i]*pow(2, last-i);
	return ret;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n-2; i++) {
		for (int j = i+2; j < n; j++) {
			int x = change(0,i), y = change(i+1, j-1), z = change(j, n-1);
			if (x == y && y == z) {
				cout << i << " " << j << endl;
				return 0;
			}
		}
	}
	cout << -1 << " " << -1 << endl;
	return 0;
}