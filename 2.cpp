#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> ages(N);
    for (int i = 0; i < N; i++) {
        cin >> ages[i];
    }

    vector<int> result(N, -1); // Initialize the result vector with -1 for each person
    stack<int> s; // Create a stack to store indices of people

    for (int i = 0; i < N; i++) {
        while (!s.empty() && ages[i] > ages[s.top()]) {
            // If the current person is older than the person at the top of the stack,
            // update the result for the person at the top of the stack and pop them from the stack
            result[s.top()] = ages[i];
            s.pop();
        }
        // Push the current person's index onto the stack
        s.push(i);
    }

    for (int i = 0; i < N; i++) {
        cout << result[i] << " ";
    }

    cout << endl;

    return 0;
}





