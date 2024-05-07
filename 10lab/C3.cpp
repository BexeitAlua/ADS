#include <bits/stdc++.h>
using namespace std;

queue<pair<int, vector<int>>> q;
set<int> s;

void findd(int x, int y) {
    q.push({x, {x}});

    while (!q.empty()) {
        int a = q.front().first;
        vector<int> temp = q.front().second;

        q.pop();

        if (a == y) {
            cout << temp.size() - 1 << endl;
            for (int i = 0; i < temp.size(); i++) {
                cout << temp[i] << " ";
            }
            return;
        }

        if (a - 1 > 0 && s.count(a - 1) != 1) {
            vector<int> new_temp = temp;
            new_temp.push_back(a - 1);
            q.push({a - 1, new_temp});
            s.insert(a - 1);
        }

        if (2 * a > 0 && s.count(2 * a) != 1) {
            vector<int> new_temp = temp;
            new_temp.push_back(2 * a);
            q.push({2 * a, new_temp});
            s.insert(2 * a);
        }
    }
}

int main() {
    int x, y;
    cin >> x >> y;

    findd(x, y);

    return 0;
}






