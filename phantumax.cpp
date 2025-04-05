#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> findTopKPositions(const vector<int>& arr, int k) {
    vector<pair<int, int>> indexedArr; // Lưu giá trị và chỉ số
    for (int i = 0; i < arr.size(); i++) {
        indexedArr.push_back({arr[i], i});
    }

    sort(indexedArr.begin(), indexedArr.end(), greater<pair<int, int>>());

    vector<int> result;
    for (int i = 0; i < k; i++) {
        result.push_back(indexedArr[i].second);
    }
    return result;
}

int main() {
    vector<int> arr = {5, 9, 1, 8, 2, 6, 4, 7, 3};
    int k = 3;
    vector<int> topK = findTopKPositions(arr, k);

    cout << "Vi tri cua " << k << " phan tu lon nhat: ";
    for (int pos : topK) {
        cout << pos << " ";
    }
    return 0;
}
