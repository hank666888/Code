#include <iostream>
#include <string>
using namespace std;

long long n;
string s;

int main() {
	cin >> s >> n;
	int l = s.size();
	while (l < n) {
		long long i = l;
		while (n > i*2) i *= 2;
		n -= i+1;
		if (n == 0) n = i;
	}
	cout << s[n-1] << endl;
	return 0;
}