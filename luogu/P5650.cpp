#include <iostream>
#include <string>
using namespace std;

const int MAXN = 100010;

int f[MAXN], ans = -1;
string s;

int main() {
	cin >> s;
	if (s[0] == '0') f[0] = 1;
	else f[0] = -1;
	for (int i=1; i<s.size(); i++) {
		if (s[i] == '0') f[i] = max(1, f[i-1]+1);
		else f[i] = max(-1, f[i-1]-1);
		ans = max(ans, f[i]);
	}
	cout << ans << endl;
	return 0;
}