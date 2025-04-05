#include <iostream>
#include <vector>
using namespace std;

vector<int> findInversionArray(const vector<int>& arr) {
    vector<int> inversion(arr.size(), 0);
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] > arr[i]) {
                inversion[i]++;
            }
        }
    }
    return inversion;
}

int main() {
    vector<int> arr = {5, 9, 1, 8, 2, 6, 4, 7, 3};
    vector<int> inversion = findInversionArray(arr);

    cout << "Mang nghich the: ";
    for (int num : inversion) {
        cout << num << " ";
    }
    return 0;
}

