#include <iostream>
#include <string>
using namespace std;

void trim(string& s) {
    int i = 0;
    while (i < s.size() && s.at(i) == ' ') {
        i++;
    }
    s.erase(0, i);
    i = 0;
    while (s.size() > 0 && s.at(s.size() - 1 - i) == ' ') {
        i++;
    }
    s.erase(s.size() - i, i);
}

int main() {
    string s = "ciao mondo   ";

    trim(s);
    cout << s << endl;
    return 0;
}
