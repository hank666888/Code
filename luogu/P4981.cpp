#include <iostream>
using namespace std;

const int mod = 1e9 + 9;

long long t, n;

long long pow(long long a, long long b) {
	long long ret = 1;
	while (b) {
		if (b % 2 == 1) ret = (ret * a) % mod;
		a = a * a % mod;
		b /= 2;
	}
	return ret;
}

int main() {
	cin >> t;
	while (t--) {
		cin >> n;
		cout << pow(n, n-1) << endl;
	}
	return 0;
}