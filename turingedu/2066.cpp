#include <iostream>
#include <string>
using namespace std;

string str, ans, now;
bool flag;

int main() {
    getline(cin, str);
    for (int i = 0; i < str.size(); i++) {
        if(str[i] != ' ') {
            flag = false;
            now += str[i];
        }
        if ( (str[i] == ' ' || i == str.size()-1 ) && !flag) {
            flag = true;
            if (ans.size() < now.size())
                ans = now;
            now = "";
        }
    }
    cout << ans << " " << ans.size();
    return 0;
}
