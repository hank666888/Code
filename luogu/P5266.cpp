#include <iostream>
#include <map>
using namespace std;

int t;
std::map<string, int> sys;

int main() {
	cin >> t;
	while (t--) {
		int k;
		cin >> k;
		if (k == 1) {
			string name;
			int score;
			cin >> name >> score;
			sys[name] = score;
			cout << "OK\n";
		}
		if (k == 2) {
			string name;
			cin >> name;
			if (!sys.count(name)) cout << "Not found\n";
			else cout << sys[name] << endl;
		}
		if (k == 3) {
			string name;
			cin >> name;
			if (!sys.count(name)) cout << "Not found\n";
			else {
				sys.erase(name);
				cout << "Deleted successfully\n";
			}
		}
		if (k == 4) cout << sys.size() << endl;
	}
	return 0;
}