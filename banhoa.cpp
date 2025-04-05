#include <iostream>
#include <cstring>
using namespace std;
struct LoaiHoa {
    char Ten[30];   // Tên loại hoa
    int SoLuong;    // Số lượng tồn kho
    char DVT[10];   // Đơn vị tính (bó, cành,...)
    float DonGia;   // Đơn giá của loại hoa
};

// Khai báo cấu trúc DanhSachLoaiHoa
struct DanhSachLoaiHoa {
    LoaiHoa dsHoa[20]; // Danh sách tối đa 20 loại hoa
    int SoLuong;       // Số loại hoa hiện có
};

// Hàm nhập danh sách các loại hoa
void NhapDanhSach(DanhSachLoaiHoa &ds) {
    cout << "Nhap so luong loai hoa: ";
    cin >> ds.SoLuong;

    while (ds.SoLuong < 1 || ds.SoLuong > 20) {
        cout << "So luong khong hop le! Nhap lai: ";
        cin >> ds.SoLuong;
    }

    for (int i = 0; i < ds.SoLuong; i++) {
        cout << "\nNhap thong tin loai hoa thu " << i + 1 << ":\n";
        
        cout << "Ten loai: ";
        cin.ignore();
        cin.getline(ds.dsHoa[i].Ten, 30);

        cout << "So luong: ";
        cin >> ds.dsHoa[i].SoLuong;
        cout << "Don vi tinh: ";
        cin.ignore();
        cin.getline(ds.dsHoa[i].DVT, 10);
        cout << "Don gia: ";
        cin >> ds.dsHoa[i].DonGia;
    }
}
void XuatDanhSach(DanhSachLoaiHoa ds) {
    cout << "\nDanh sach cac loai hoa trong cua hang:\n";
    cout << "----------------------------------------------------\n";
    cout << "Ten loai          | So luong | DVT    | Don gia\n";
    cout << "----------------------------------------------------\n";
    for (int i = 0; i < ds.SoLuong; i++) {
        cout << ds.dsHoa[i].Ten << " | ";
        cout << ds.dsHoa[i].SoLuong << " | ";
        cout << ds.dsHoa[i].DVT << " | ";
        cout << ds.dsHoa[i].DonGia << endl;
    }
}
int TimLoaiHoa(DanhSachLoaiHoa ds, char *tenloai) {
    for (int i = 0; i < ds.SoLuong; i++) {
        if (strcmp(ds.dsHoa[i].Ten, tenloai) == 0) {
            return i; 
        }
    }
    return -1; 
}
void XuLyBanHoa(DanhSachLoaiHoa &ds, char *tenloai, int soluong) {
    int vitri = TimLoaiHoa(ds, tenloai);
    if (vitri == -1) {
        cout << "Khong co loai hoa nay trong cua hang.\n";
        return;
    }
    if (ds.dsHoa[vitri].SoLuong < soluong) {
        cout << "Khong du so luong hoa de ban.\n";
        return;
    }
    float tongTien = soluong * ds.dsHoa[vitri].DonGia;
    ds.dsHoa[vitri].SoLuong -= soluong;
    cout << "Ban thanh cong! Tong tien: " << tongTien << " VND\n";
}
int main() {
    DanhSachLoaiHoa ds;
    char tenloai[30];
    int soluong;
    NhapDanhSach(ds);
    XuatDanhSach(ds);
    cout << "\nNhap ten loai hoa can mua: ";
    cin.ignore();
    cin.getline(tenloai, 30);
    cout << "Nhap so luong can mua: ";
    cin >> soluong;
    XuLyBanHoa(ds, tenloai, soluong);
    XuatDanhSach(ds);
    return 0;
}
