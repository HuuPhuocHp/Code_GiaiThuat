#include <iostream>
#include <vector>
using namespace std;

void sortEvenOdd(vector<int>& arr) {
    int left = 0, right = arr.size() - 1;
    while (left < right) {
        while (left < right && arr[left] % 2 == 0) left++;
        while (left < right && arr[right] % 2 != 0) right--;
        if (left < right) {
            swap(arr[left], arr[right]);
        }
    }
}

int main() {
    vector<int> arr = {5, 9, 1, 8, 2, 6, 4, 7, 3};
    sortEvenOdd(arr);

    cout << "Chan dau, le cuoi: ";
    for (int num : arr) {
        cout << num << " ";
    }
    return 0;
}

