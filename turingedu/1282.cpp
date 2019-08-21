#include <iostream>
using namespace std;

int n, a, b, h;

bool check(int s) {
	if ( (s - 1) * (a - b) + a >= h)
		return true;
	return false;
}

int main() {
	cin >> n;
	while (n--) {
		cin >> h >> a >> b;
		if (a < h && a <= b) {
			cout << "error" <<endl;
			continue;
		}
		if (a >= h)
			cout << 1 <<endl;
		int ans;
		if ( (h - a) % (a - b) != 0)
			ans = (h - a) / (a - b) + 2;
		else
			ans = (h - a) / (a - b) + 1;
		cout << ans << endl;
	}
	return 0;
}