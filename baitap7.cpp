#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Nguoi {
public:
    string ho_ten;
    string nam_sinh;

    void nhap() {
        cout << "Nhap ho t�n: ";
        cin.ignore();
        getline(cin, ho_ten);
        cout << "Nhap nam sinh: ";
        cin >> nam_sinh;
    }

    void hien_thi() {
        cout << "Ho t�n: " << ho_ten << endl;
        cout << "Nam sinh: " << nam_sinh << endl;
    }
};

class Thisinh : public Nguoi {
public:
    string so_bao_danh;
    float diem_toan, diem_ly, diem_hoa;

    void nhap() {
        Nguoi::nhap();
        cout << "Nhap so b�o danh: ";
        cin >> so_bao_danh;
        cout << "Nhap �iem to�n: ";
        cin >> diem_toan;
        cout << "Nhap �iem ly: ";
        cin >> diem_ly;
        cout << "Nhap �iem h�a: ";
        cin >> diem_hoa;
    }

    void hien_thi() {
        Nguoi::hien_thi();
        cout << "So b�o danh: " << so_bao_danh << endl;
        cout << "�iem to�n: " << diem_toan << endl;
        cout << "�iem ly: " << diem_ly << endl;
        cout << "�iem h�a: " << diem_hoa << endl;
    }

    float tong_diem() {
        return diem_toan + diem_ly + diem_hoa;
    }
};

int main() {
    int n;
    cout << "Nhp so luong th� sinh: ";
    cin >> n;
    vector<Thisinh> danh_sach;

    for (int i = 0; i < n; ++i) {
        cout << "\nNhap th�ng tin th� sinh thu " << i + 1 << ":\n";
        Thisinh thisinh;
        thisinh.nhap();
        danh_sach.push_back(thisinh);
    }

    cout << "\nDanh s�ch th� sinh c� tong �iem tang dan:\n";
    sort(danh_sach.begin(), danh_sach.end(), [](const Thisinh &a, const Thisinh &b) {
        return a.tong_diem() < b.tong_diem();
    });

    for (const Thisinh &thisinh : danh_sach) {
        thisinh.hien_thi();
        cout << "Tong �iem: " << thisinh.tong_diem() << endl << endl;
    }

    string so_bao_danh_tim_kiem;
    cout << "\nNhap so b�o danh can tim: ";
    cin >> so_bao_danh_tim_kiem;

    bool tim_thay = false;
    for (const Thisinh &thisinh : danh_sach) {
        if (thisinh.so_bao_danh == so_bao_danh_tim_kiem) {
            cout << "\nTh�ng tin th� sinh c?n t?m:\n";
            thisinh.hien_thi();
            tim_thay = true;
            break;
        }
    }

    if (!tim_thay) {
        cout << "\nKh�ng tim thay th� sinh c� so b�o danh " << so_bao_danh_tim_kiem << endl;
    }

    int so_thi_sinh_dat_yeu_cau = 0;
    for (const Thisinh &thisinh : danh_sach) {
        if (thisinh.diem_toan >= 5 && thisinh.diem_ly >= 5 && thisinh.diem_hoa >= 5) {
            so_thi_sinh_dat_yeu_cau++;
        }
    }

    float phan_tram_dat_yeu_cau = (static_cast<float>(so_thi_sinh_dat_yeu_cau) / n) * 100;
    cout << "\nPhan tram th� sinh �at y�u cau: " << phan_tram_dat_yeu_cau << "%" << endl;

    return 0;
}

