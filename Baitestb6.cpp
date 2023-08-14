#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring> 

using namespace std;

class Oto {
private:
    char maOto[10];
    char loaiOto[25];
    string ngaySanXuat;
    int soLuong;
    long long giaMotChiec;

public:
    Oto() {}
    Oto(const char ma[10], const char loai[25], const string& ngay, int sl, long long gia) {
        strcpy(maOto, ma);
        strcpy(loaiOto, loai);
        ngaySanXuat = ngay;
        soLuong = sl;
        giaMotChiec = gia;
    }

    long long TinhTongTien() const { 
        double thueVAT;
        if (giaMotChiec > 10000)
            thueVAT = 0.1;
        else if (giaMotChiec > 7000)
            thueVAT = 0.07;
        else if (giaMotChiec > 3000)
            thueVAT = 0.05;
        else
            thueVAT = 0;

        long long tongTien = soLuong * giaMotChiec * (1 + thueVAT);
        return tongTien;
    }

    friend istream& operator>>(istream& is, Oto& oto) {
        cout << "Nhap ma oto: ";
        is >> oto.maOto;
        cout << "Nhap loai oto: ";
        is >> oto.loaiOto;
        cout << "Nhap ngay san xuat (dd/mm/yyyy): ";
        is >> oto.ngaySanXuat;
        cout << "Nhap so luong: ";
        is >> oto.soLuong;
        cout << "Nhap gia mot chiec: ";
        is >> oto.giaMotChiec;
        return is;
    }

    bool operator>(const Oto& other) const { 
        return TinhTongTien() > other.TinhTongTien();
    }

    void XuatThongTin() const { 
        cout << "Ma oto: " << maOto << endl;
        cout << "Loai oto: " << loaiOto << endl;
        cout << "Ngay san xuat: " << ngaySanXuat << endl;
        cout << "So luong: " << soLuong << endl;
        cout << "Gia mot chiec: " << giaMotChiec << endl;
        cout << "Tong tien: " << TinhTongTien() << endl;
    }
};

bool CompareByTongTien(const Oto& a, const Oto& b) {
    return a > b;
}

int main() {
    vector<Oto> dsOto;
    int n;

    cout << "Nhap so luong oto: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        Oto oto;
        cin >> oto;
        dsOto.push_back(oto);
    }

    cout << "Danh sach oto truoc khi sap xep: " << endl;
    for (const auto& oto : dsOto) {
        oto.XuatThongTin();
        cout << endl;
    }

    sort(dsOto.begin(), dsOto.end(), CompareByTongTien);

    cout << "Danh sach oto sau khi sap xep tang dan theo tong tien: " << endl;
    for (const auto& oto : dsOto) {
        oto.XuatThongTin();
        cout << endl;
    }

    return 0;
}
