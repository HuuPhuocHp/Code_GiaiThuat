#include <iostream>
using namespace std;
void mergeArrays(double a[], int n, double b[], int m, double c[]) {
    int i = 0, j = 0, k = 0;
    while (i < n && j < m) {
        if (a[i] < b[j]) {
            c[k++] = a[i++];
        } else {
            c[k++] = b[j++];
        }
    }
    while (i < n) {
        c[k++] = a[i++];
    }
    while (j < m) {
        c[k++] = b[j++];
    }
}
int main() {
    int n, m;
    cout << "Nhap so phan tu cua mang a: ";
    cin >> n;
    double a[100];
    cout << "Nhap " << n << " so thuc tang dan: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << "Nhap so phan tu cua mang b: ";
    cin >> m;
    double b[100];
    cout << "Nhap " << m << " so thuc tang dan: ";
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    double c[200]; 
    mergeArrays(a, n, b, m, c);
    cout << "Day c sau khi tron: ";
    for (int i = 0; i < n + m; i++) {
        cout << c[i] << " ";
    }
    cout << endl;
    return 0;
}
