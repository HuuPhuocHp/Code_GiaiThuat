#include <iostream>
using namespace std;
bool checkChanLeXenKe(int a[], int n) {
    for (int i = 1; i < n; i++) {
        if ((a[i] % 2) == (a[i - 1] % 2)) {
            return false; 
        }
    }
    return true;
}
bool checkToanChan(int a[], int n) {
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 != 0) {
            return false; 
        }
    }
    return true;
}
int main() {
    int n;
    cout << "Nhap so phan tu n: ";
    cin >> n;
    int a[100];
    cout << "Nhap " << n << " so nguyen: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (checkChanLeXenKe(a, n)) {
        cout << "Day so co tinh chat chan le xen ke." << endl;
    } else {
        cout << "Day so KHONG co tinh chat chan le xen ke." << endl;
    }
    if (checkToanChan(a, n)) {
        cout << "Day so toan chan." << endl;
    } else {
        cout << "Day so KHONG toan chan." << endl;
    }
    return 0;
}
