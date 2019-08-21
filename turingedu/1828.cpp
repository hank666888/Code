#include <iostream>
using namespace std;

int k;
double s, n, ans;

int main() {
	cin >> n >> k;
	while (k > 0) {
		s += n+n/2.0;
		if (k == 1)
			s -= n/2.0;
		n /= 2.0;
		ans = n;
		k--;
	}	
	printf("%.2f %.2f", s, ans);
	return 0;
}