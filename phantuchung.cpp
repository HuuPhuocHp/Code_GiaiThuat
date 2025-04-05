#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> findCommonElements(const vector<int>& x, const vector<int>& y, const vector<int>& z) {
    vector<int> temp, common;
    // Tìm giao của x và y
    set_intersection(x.begin(), x.end(), y.begin(), y.end(), back_inserter(temp));
    // Tìm giao của kết quả trước đó và z
    set_intersection(temp.begin(), temp.end(), z.begin(), z.end(), back_inserter(common));
    return common;
}

int main() {
    int nx, ny, nz;
    cout << "Nhap so phan tu cua 3 day nx, ny, nz: ";
    cin >> nx >> ny >> nz;

    vector<int> x(nx), y(ny), z(nz);

    cout << "Nhap day x: ";
    for (int i = 0; i < nx; i++) cin >> x[i];

    cout << "Nhap day y: ";
    for (int i = 0; i < ny; i++) cin >> y[i];

    cout << "Nhap day z: ";
    for (int i = 0; i < nz; i++) cin >> z[i];

    vector<int> common = findCommonElements(x, y, z);

    if (common.empty()) {
        cout << "Khong co phan tu chung" << endl;
    } else {
        cout << "Cac phan tu chung: ";
        for (int elem : common) {
            cout << elem << " ";
        }
        cout << endl;
    }

    return 0;
}
