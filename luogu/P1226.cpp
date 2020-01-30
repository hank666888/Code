#include <iostream>
#define _for(i, a, b) for (int i=(a); i<=(b); i++)
using namespace std;

typedef long long LL;

int b, p, k;

int pow_mod(int a, int n, int m) {
	if (n == 0) return 1%m;
	int x = pow_mod(a, n/2, m);
	LL ans = (LL)x*x % m;
	if (n%2 == 1) ans = ans*a % m;
	return (int)ans;
}

int main() {
	cin >> b >> p >> k;
	cout << b << "^" << p << " mod " << k << "=" << pow_mod(b, p, k) << endl;
	return 0;
}