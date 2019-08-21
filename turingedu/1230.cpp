#include <iostream>
#include <string>
using namespace std;

string s1, s2;
int a[201], b[201], x, c[202];
bool flag;

int main() {
	cin >> s1;
	cin >> s2;
	for (int i = s1.size() - 1; i >= 0; i--)
		a[201 - s1.size() + i] = s1[i] - '0';
	for (int i = s2.size() - 1; i >= 0; i--)
		b[201 - s2.size() + i] = s2[i] - '0';
	for (int i = 200; i >= 1; i--) {
		c[i] = a[i] + b[i] + x;
		x = c[i] / 10;
		c[i] = c[i] % 10;
	}
	int h = 0;
	while (c[h] == 0) h++;
	for (int i = h; i <= 200; i++)
		cout << c[i];
	return 0;
}