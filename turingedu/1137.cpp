#include <iostream>
#include <string>
using namespace std;

string s;
int tong[27];

int change(char c) {
    return int(c - 'a') + 1;
}

int main() {
    getline(cin, s);
    for (int i = 0; i < s.size(); i++) {
        if(s[i] >= 'a' && s[i] <= 'z')
            tong[change(s[i])]++;
    }
    for (int i = 1; i <= 26; i++) {
        if (tong[i]) {
            cout << char(i - 1 + 'a') << " " << tong[i] << endl;
        }
    }
    return 0;
}
