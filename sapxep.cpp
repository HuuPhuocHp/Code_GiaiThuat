#include <iostream>
#include <cstring>
using namespace std;
struct NhanVien {
    char MaSo[11];  
    char Ho[11];    
    char Ten[51];   
    int Phai;       
    int ThamNien;   
};
struct PhongBan {
    NhanVien aNhanVien[100]; 
    int SoLuong;
};
void NhapPhongBan(PhongBan &pb) {
    cout << "Nhap so luong nhan vien: ";
    cin >> pb.SoLuong;
    while (pb.SoLuong < 1 || pb.SoLuong > 100) {
        cout << "So luong khong hop le! Nhap lai: ";
        cin >> pb.SoLuong;
    }
    for (int i = 0; i < pb.SoLuong; i++) {
        cout << "\nNhap thong tin nhan vien thu " << i + 1 << ":\n";
        cout << "Ma so: ";
        cin >> pb.aNhanVien[i].MaSo;
        cout << "Ho: ";
        cin.ignore();
        cin.getline(pb.aNhanVien[i].Ho, 11);
        cout << "Ten: ";
        cin.getline(pb.aNhanVien[i].Ten, 51);
        do {
            cout << "Phai (0 - Nu, 1 - Nam): ";
            cin >> pb.aNhanVien[i].Phai;
        } while (pb.aNhanVien[i].Phai != 0 && pb.aNhanVien[i].Phai != 1);
        do {
            cout << "So nam lam viec: ";
            cin >> pb.aNhanVien[i].ThamNien;
        } while (pb.aNhanVien[i].ThamNien < 0);
    }
}
void XuatPhongBan(PhongBan pb) {
    cout << "\nDanh sach nhan vien trong phong ban:\n";
    cout << "--------------------------------------------------------------\n";
    cout << "Ma So     | Ho         | Ten                  | Phai  | Tham Nien\n";
    cout << "--------------------------------------------------------------\n";
    for (int i = 0; i < pb.SoLuong; i++) {
        cout << pb.aNhanVien[i].MaSo << "  | ";
        cout << pb.aNhanVien[i].Ho << " | ";
        cout << pb.aNhanVien[i].Ten << " | ";
        cout << (pb.aNhanVien[i].Phai == 1 ? "Nam  " : "Nu   ") << " | ";
        cout << pb.aNhanVien[i].ThamNien << endl;
    }
}
void DemSiSo(PhongBan pb, int &sonam, int &sonu) {
    sonam = 0;
    sonu = 0;
    for (int i = 0; i < pb.SoLuong; i++) {
        if (pb.aNhanVien[i].Phai == 1)
            sonam++;
        else
            sonu++;
    }
}
void SapXepTangTheoThamNien(PhongBan &pb) {
    for (int i = 0; i < pb.SoLuong - 1; i++) {
        for (int j = 0; j < pb.SoLuong - i - 1; j++) {
            if (pb.aNhanVien[j].ThamNien > pb.aNhanVien[j + 1].ThamNien) {
                swap(pb.aNhanVien[j], pb.aNhanVien[j + 1]);
            }
        }
    }
}
int main() {
    PhongBan pb;
    int sonam, sonu;
    NhapPhongBan(pb);
    XuatPhongBan(pb);
    DemSiSo(pb, sonam, sonu);
    cout << "\nSo nam: " << sonam << ", So nu: " << sonu << endl;
    SapXepTangTheoThamNien(pb);
    cout << "\nDanh sach sau khi sap xep theo tham nien:\n";
    XuatPhongBan(pb);
    return 0;
}
