#include <iostream>
#include <map>
using namespace std;

int n, q;
std::map<string, string> ans;

int main() {
	cin >> n >> q;
	for (int i=1; i<=n; i++) {
		string s1, s2;
		cin >> s1 >> s2;
		ans[s1] = s2;
	}
	while (q--) {
		string s, s1, s2, s3, s4;
		cin >> s >> s1 >> s2 >> s3 >> s4;
		if (ans[s] == s1) cout << "A" << endl;
		if (ans[s] == s2) cout << "B" << endl;
		if (ans[s] == s3) cout << "C" << endl;
		if (ans[s] == s4) cout << "D" << endl;
	}
	return 0;
}