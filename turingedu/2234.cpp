#include <iostream>
using namespace std;

int x, y, s = 1, cnt, ans;

int main() {
	cin >> x >> y;
	while (true) {
		cnt++;
		if (cnt % 2 == 1) {
			if (x + s >= y && y >= x) {
				ans += y - x;
				break;
			}
			else
				ans += 2 * s;
		}
		else {
			if (x - s <= y && y <= x) {
				ans += x - y;
				break;
			}
			else
				ans += 2 * s;
		}
		s *= 2;
	}
	cout << ans << endl;
	return 0;
}