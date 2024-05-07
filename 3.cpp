#include <iostream>
#include <string>

using namespace std;

string processString(const string& s) {
    string result;
    
    for (size_t i = 0; i < s.length(); i++) {
        char c = s[i];
        if (c == '#') {
            if (!result.empty()) {
                result.erase(result.length() - 1);
            }
        } else {
            result.push_back(c);
        }
    }
    
    return result;
}

int main() {
    string s1, s2;
    
    cin >> s1 >> s2;
    
    string processedS1 = processString(s1);
    string processedS2 = processString(s2);
    
    if (processedS1 == processedS2) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    
    return 0;
}
