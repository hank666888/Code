#include <iostream>
using namespace std;

int n, a[10010], sum;
string s;

bool check(int k) {
	int ret = 0;
	for (int i=1; i<=n; i++) {
		ret += a[i];
		if (ret > k) return false;
		if (ret == k) ret = 0;
	}
	return true;
}

int main() {
	cin >> n;
	cin >> s;
	for (int i=0; i<s.size(); i++) a[i+1] = s[i] - '0', sum += a[i+1];
	for (int i=2; i<=n; i++) 
		if (sum % i == 0 && check(sum / i)) {
			cout << "YES\n";
			return 0;
		}
	cout << "NO\n";
	return 0;
}