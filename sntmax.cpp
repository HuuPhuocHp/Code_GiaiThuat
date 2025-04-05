#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int findLargestPrime(const vector<vector<int>>& matrix) {
    int largestPrime = -1;
    for (const auto& row : matrix) {
        for (int num : row) {
            if (isPrime(num) && num > largestPrime) {
                largestPrime = num;
            }
        }
    }
    return largestPrime;
}

int main() {
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int largestPrime = findLargestPrime(matrix);

    if (largestPrime != -1) {
        cout << "So nguyen to lon nhat: " << largestPrime << endl;
    } else {
        cout << "Khong co so nguyen to trong ma tran." << endl;
    }
    return 0;
}

