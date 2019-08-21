#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int k, s1, s2, st, ed, num;
char c1, c2, c3, c4;
double off;

int main() {
	cin >> k;
	if (k == 1)
		off = 0.95;
	else if (k == 0) 
		off = 0.5;
	else {
		cout << "0.00" << endl;
		return 0;
	}
	cin >> c1 >> s1 >> c2 >> s2;
	cin >> c3 >> st >> c4 >> ed;
	if (c3 == c4 && st == ed) {
		cout << "0.00" << endl;
		return 0;
	}
	if (c4 == 'A' && c3 == 'B')
		swap(st, ed);
	if (c3 == c4) 
		num = abs(ed - st);
	else
		num = abs(s1 - st) + abs(ed - s2);
	if (num <= 8)
		printf("%.2f", 2*off);
	else if (num>=9 && num<=12)
		printf("%.2f", 3*off);
	else if (num>=13 && num<=16)
		printf("%.2f", 4*off);
	else
		printf("%.2f", 5*off);
	return 0;
}