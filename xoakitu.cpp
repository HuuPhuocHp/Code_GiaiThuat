
#include <iostream>
#include <cstring>
using namespace std;
void XoaKyTu(char s[], int k) {
    int n = strlen(s);
    if (k >= 0 && k < n) {
        for (int i = k; i < n; i++) {
            s[i] = s[i + 1];
        }
    } else {
        cout << "Vị trí k không hợp lệ!" << endl;
    }
}
int main() {
    char s[1001];  // Chuỗi tối đa 1000 ký tự
    int k;
    cout << "Nhap chuoi: ";
    cin.getline(s, 1001); 
    cout << "Nhap vi tri k (0 <= k < " << strlen(s) << "): ";
    cin >> k;  
    XoaKyTu(s, k); 
    cout << "Chuoi sau khi xoa ky tu tai vi tri " << k << ": " << s << endl;
    return 0;
}
