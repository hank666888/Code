#include <iostream>
#include <cmath>
using namespace std;

char c;
int w, l;

int main() {
	while (cin >> c) {
		if (c == 'W')
			w++;
		else
			l++;
		if ( (w == 11 && l <= 9) || (l == 11 && w <= 9) || ( ( l > 11 || w > 11 ) && abs(l - w) >= 2 ) ) {
			cout << w << ":" << l << endl;
			l = 0, w = 0;
		}
	}
	if(w != 0 || l != 0)
		cout << w << ":" << l << endl;
	return 0;
}