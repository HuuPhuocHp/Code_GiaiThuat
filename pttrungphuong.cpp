#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

// Hàm giải phương trình bậc 2
void solveQuarticEquation(double a, double b, double c) {
    vector<double> solutions;

    // Trường hợp a = 0 -> phương trình trở thành bậc nhất
    if (a == 0) {
        if (b == 0) {
            if (c == 0) {
                cout << "Phuong trinh co vo so nghiem" << endl;
            } else {
                cout << "Phuong trinh vo nghiem" << endl;
            }
        } else {
            double y = -c / b;
            if (y >= 0) {
                solutions.push_back(sqrt(y));  // Thêm nghiệm dương
                solutions.push_back(-sqrt(y)); // Thêm nghiệm âm
            }
            if (solutions.empty()) {
                cout << "Phuong trinh vo nghiem" << endl;
            } else {
                cout << "Phuong trinh co " << solutions.size() << " nghiem" << endl;
                sort(solutions.begin(), solutions.end());  // Sắp xếp nghiệm
                for (double sol : solutions) {
                    cout << fixed << setprecision(2) << sol << " ";
                }
                cout << endl;
            }
        }
    } else {
        // Tính delta để xác định nghiệm
        double delta = b * b - 4 * a * c;
        if (delta < 0) {
            cout << "Phuong trinh vo nghiem" << endl;
        } else if (delta == 0) {
            double y = -b / (2 * a);
            if (y >= 0) {
                solutions.push_back(sqrt(y));  // Thêm nghiệm dương
                solutions.push_back(-sqrt(y)); // Thêm nghiệm âm
            }
        } else {
            double y1 = (-b - sqrt(delta)) / (2 * a);
            double y2 = (-b + sqrt(delta)) / (2 * a);
            if (y1 >= 0) {
                solutions.push_back(sqrt(y1));  // Thêm nghiệm dương
                solutions.push_back(-sqrt(y1)); // Thêm nghiệm âm
            }
            if (y2 >= 0) {
                solutions.push_back(sqrt(y2));  // Thêm nghiệm dương
                solutions.push_back(-sqrt(y2)); // Thêm nghiệm âm
            }
        }

        if (solutions.empty()) {
            cout << "Phuong trinh vo nghiem" << endl;
        } else {
            cout << "Phuong trinh co " << solutions.size() << " nghiem" << endl;
            sort(solutions.begin(), solutions.end());  // Sắp xếp nghiệm
            for (double sol : solutions) {
                cout << fixed << setprecision(2) << sol << " ";
            }
            cout << endl;
        }
    }
}

int main() {
    double a, b, c;
    cout << "Nhap he so a, b, c: ";
    cin >> a >> b >> c;
    solveQuarticEquation(a, b, c);  // Gọi hàm giải phương trình bậc 2
    return 0;
}
