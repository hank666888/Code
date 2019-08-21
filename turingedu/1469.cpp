#include <iostream>
#include <cmath>
using namespace std;

int a, prime[110], n, f[110];

bool isprime(int x) {
	if (x == 0 || x == 1)
		return false;
	for (int i = 2; i <= sqrt(x); i++)
		if (x%i == 0)
			return false;
	return true;
}

int main() {
	cin >> a;
	for (int i = 1; i <= a; i++)
		if (isprime(i))
			prime[++n] = i;
	f[0] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = prime[i]; j <= a; j++) {
			f[j] += f[j-prime[i]];
		}
	cout << f[a] << endl;
	return 0;
}