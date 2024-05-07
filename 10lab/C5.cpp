#include <bits/stdc++.h>
using namespace std;

void findMinOperations(int x, int y) {
    queue<pair<int, vector<int>>> q;
    set<int> visited;
    
    q.push({x, {x}});
    visited.insert(x);

    while (!q.empty()) {
        int current = q.front().first;
        vector<int> path = q.front().second;
        q.pop();

        if (current == y) {
            cout << path.size() - 1 << endl; 
            for (int num : path) {
                cout << num << " ";
            }
            return;
        }

        if (current - 1 > 0 && visited.count(current - 1) == 0) {
            q.push({current - 1, path});
            q.back().second.push_back(current - 1);
            visited.insert(current - 1);
        }
        if (2 * current <= y && visited.count(2 * current) == 0) {
            q.push({2 * current, path});
            q.back().second.push_back(2 * current);
            visited.insert(2 * current);
        }
    }
}

int main() {
    int x, y;
    cin >> x >> y;

    if (x > y) {
        cout << x - y << endl;
        for (int i = x; i >= y; i--) {
            cout << i << " ";
        }
    } else {
        findMinOperations(x, y);
    }

    return 0;
}

