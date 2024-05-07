#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isBalanced(const string& s) {
    stack<char> st;

    for (size_t i = 0; i < s.length(); i++) {
        char c = s[i];
        if (st.empty() || st.top() != c) {
            st.push(c);
        } else {
            st.pop();
        }
    }

    return st.empty();
}

int main() {
    string s;
    cin >> s;

    if (isBalanced(s)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
