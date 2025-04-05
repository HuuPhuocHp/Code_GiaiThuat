#include <iostream>
#include <cstring>
using namespace std;
void ChenKyTu(char s[], int k, char c) {
    int n = strlen(s);
    
    if (k >= 0 && k <= n) {
        for (int i = n; i >= k; i--) {
            s[i + 1] = s[i];
        }
        s[k] = c;  
    } else {
        cout << "Vị trí k không hợp lệ!" << endl;
    }
}
int main() {
    char s[1002]; 
    int k;
    char c;
    cout << "Nhap chuoi: ";
    cin.getline(s, 1002);  
    cout << "Nhap vi tri k (0 <= k <= " << strlen(s) << "): ";
    cin >> k;  // Nhập vị trí k
    cout << "Nhap ky tu c: ";
    cin >> c;  // Nhập ký tự c
    ChenKyTu(s, k, c); 
    cout << "Chuoi sau khi chen ky tu tai vi tri " << k << ": " << s << endl;
    return 0;
}
