#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

void solveQuadraticEquation(double a, double b, double c) {
    if (a == 0) {
        if (b == 0) {
            if (c == 0) {
                cout << "Phuong trinh co vo so nghiem" << endl;
            } else {
                cout << "Phuong trinh vo nghiem" << endl;
            }
        } else {
            double x = -c / b;
            cout << "Phuong trinh co 1 nghiem" << endl;
            cout << fixed << setprecision(2) << x << endl;
        }
    } else {
        double delta = b * b - 4 * a * c;
        if (delta < 0) {
            cout << "Phuong trinh vo nghiem" << endl;
        } else if (delta == 0) {
            double x = -b / (2 * a);
            cout << "Phuong trinh co 1 nghiem" << endl;
            cout << fixed << setprecision(2) << x << endl;
        } else {
            double x1 = (-b - sqrt(delta)) / (2 * a);
            double x2 = (-b + sqrt(delta)) / (2 * a);
            if (x1 > x2) swap(x1, x2);
            cout << "Phuong trinh co 2 nghiem" << endl;
            cout << fixed << setprecision(2) << x1 << " " << x2 << endl;
        }
    }
}

int main() {
    double a, b, c;
    cout << "Nhap he so a, b, c: ";
    cin >> a >> b >> c;
    solveQuadraticEquation(a, b, c);  // Gọi hàm giải phương trình bậc 2
    return 0;
}
