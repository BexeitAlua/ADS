#include <iostream>
#include <vector>
using namespace std;

struct Date {
    int year, month, day;
};

bool compareDates(const string& date1, const string& date2) {
    Date d1, d2;
    sscanf(date1.c_str(), "%d-%d-%d", &d1.day, &d1.month, &d1.year);
    sscanf(date2.c_str(), "%d-%d-%d", &d2.day, &d2.month, &d2.year);

    if (d1.year != d2.year) {
        return d1.year < d2.year;
    }
    if (d1.month != d2.month) {
        return d1.month < d2.month;
    }
    return d1.day < d2.day;
}

void merge(vector<string>& dates, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<string> L(n1), R(n2);

    for (int i = 0; i < n1; i++) {
        L[i] = dates[left + i];
    }
    for (int i = 0; i < n2; i++) {
        R[i] = dates[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (compareDates(L[i], R[j])) {
            dates[k] = L[i];
            i++;
        } else {
            dates[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        dates[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        dates[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<string>& dates, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(dates, left, mid);
        mergeSort(dates, mid + 1, right);
        merge(dates, left, mid, right);
    }
}

int main() {
    int n;
    cin >> n;

    vector<string> dates(n);
    for (int i = 0; i < n; i++) {
        cin >> dates[i];
    }

    mergeSort(dates, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << dates[i] << endl;
    }

    return 0;
}
