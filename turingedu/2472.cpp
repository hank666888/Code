#include <iostream>
#include <string>
using namespace std;

string str;
int x, a[1001], b[1001], h, c[1002];

int main() {
	cin >> str;
	for (int i = 0; i < str.size(); i++)
		if (str[i] == '-') {
			x = i;
			break;
		}
	for (int i = x - 1; i >= 0; i--)
		a[1001 - x + i] = str[i] - '0';
	for (int i = str.size() - 1; i >= x + 1; i--)
		b[1001 - str.size() + i] = str[i] - '0';
	x = 0;
	for (int i = 1000; i > 0; i--) {
		if (a[i] - x >= b[i]) {
			c[i] = a[i] - b[i] - x;
			x = 0;
		}
		else {
			c[i] = a[i] - x + 10 - b[i];
			x = 1;
		}
	}
	int h = 0;
	while (c[h] == 0)
		h++;
	for (int i = h; i <= 1000; i++)
		cout << c[i];
	return 0;
}