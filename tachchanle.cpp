#include <iostream>
using namespace std;
int main() {
    int n;
    cout << "Nhap so phan tu n: ";
    cin >> n;
    int a[100], b[100], c[100]; 
    int evenCount = 0, oddCount = 0; 
    cout << "Nhap " << n << " so nguyen: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] % 2 == 0) {
            b[evenCount++] = a[i]; 
        } else {
            c[oddCount++] = a[i]; 
        }
    }
    cout << "Day b (so chan): ";
    if (evenCount == 0) {
        cout << "Khong co so chan!";
    } else {
        for (int i = 0; i < evenCount; i++) {
            cout << b[i] << " ";
        }
    }
    cout << endl;
    cout << "Day c (so le): ";
    if (oddCount == 0) {
        cout << "Khong co so le!";
    } else {
        for (int i = 0; i < oddCount; i++) {
            cout << c[i] << " ";
        }
    }
    cout << endl;
    return 0;
}
