#include <iostream>
#include <string>
using namespace std;

string str;

bool check() {
    if (str.size() % 2 != 0)
        return false;
    int n = str.size() / 2;
    for(int i = 0; i < n; i++)
        if (str[i] != str[str.size() - i - 1])
            return false;
    return true;
}

int doit() {
    while (check() && str.size()) {
        string temp;
        for(int i = 0; i < str.size() / 2; i++)
            temp+=str[i];
        str = temp;
    }
    return str.size();
}

int main() {
    cin >> str;
    cout << doit() << endl;
    return 0;
}
