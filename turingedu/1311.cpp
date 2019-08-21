#include <iostream>
#include <string>
using namespace std;

char c;
int sum = 0, ret;

int main() {
	for (int i = 1; i <= 10; i++) {
		cin >> c;
		int x = 0;
		if (c == 'X')
			x = 10;
		else if (c == '?')
			ret = i;
		else
			x = c - '0';
		sum += x * (11 - i);
	}
	//cout << sum << endl;
	for (int i = 0; i <= 10; i++) {
		if (ret != 10 && i == 10)
			break;
		if ((sum + i * (11 - ret)) % 11 == 0) {
			if (i != 10)
				cout << i << endl;
			else
				cout << "X" << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}
//1568?1111X