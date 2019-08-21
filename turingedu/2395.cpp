#include <iostream>
#include <string>
using namespace std;

string s;
long long a, b;
int k;

int main() {
    cin >> s;
    for (int i = 0; i < s.size(); i++){
        if (s[i] == '*') {
            k = i;
            break;
        }
        a *= 10;
        a += (int)(s[i] - '0');
    }
    for (int i = k + 1; i < s.size(); i++){
        b *= 10;
        b += (int)(s[i] - '0');
    }
    cout << a * b << endl;
    return 0;
}
