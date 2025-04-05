#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void sortEvenOdd(vector<int>& arr) {
    vector<int> evens, odds;
    for (int num : arr) {
        if (num == 0) continue;
        if (num % 2 == 0) evens.push_back(num);
        else odds.push_back(num);
    }

    sort(evens.begin(), evens.end());
    sort(odds.begin(), odds.end(), greater<int>());

    int evenIdx = 0, oddIdx = 0;
    for (int& num : arr) {
        if (num == 0) continue;
        if (evenIdx < evens.size()) {
            num = evens[evenIdx++];
        } else {
            num = odds[oddIdx++];
        }
    }
}

int main() {
    vector<int> arr = {5, 9, 0, 8, 2, 6, 4, 7, 3};
    sortEvenOdd(arr);

    cout << "Sap xep chan tang dan, le giam dan: ";
    for (int num : arr) {
        cout << num << " ";
    }
    return 0;
}

