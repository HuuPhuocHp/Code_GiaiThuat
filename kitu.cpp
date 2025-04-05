#include <iostream>
using namespace std;
bool isVowel(char c) {
    c = tolower(c); // Chuyển về chữ thường để kiểm tra
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}
int main() {
    int n;
    cout << "Nhap so phan tu n: ";
    cin >> n;
    char a[100], b[100]; 
    int j = 0; 
    cout << "Nhap " << n << " ky tu: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (isVowel(a[i])) {
            b[j++] = a[i]; 
        }
    }
    if (j == 0) {
        cout << "Khong co nguyen am trong day!" << endl;
    } else {
        cout << "Day b chua cac nguyen am: ";
        for (int i = 0; i < j; i++) {
            cout << b[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
