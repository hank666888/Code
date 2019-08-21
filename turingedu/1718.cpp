#include <iostream>
#include <string>
using namespace std;

int n;
string str;

bool check() {
    for (int i = 0; i < str.size(); i++) {
        if (str[i] != str[str.size()-1-i])
            return false;
    }
    return true;
}

int main() {
    cin >> n;
    while (n--) {
        cin >> str;
        if (check())
            cout << "T\n";
        else
            cout << "F\n";
    }
    return 0;
}
