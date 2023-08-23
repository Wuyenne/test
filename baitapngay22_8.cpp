#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

class DocGia {
protected:
    string maSach;
    string tenSach;
    string tacGia;
    string tenDocGia;
    int tuoi;
    int ngayMuon;
    int ngayTra;

public:
    virtual float tinhPhi() = 0;
    virtual void nhapThongTin() = 0;
    virtual void hienThiThongTin() = 0;
};

class DocGiaTreEm : public DocGia {
private:
    string tenNguoiGiamHo;

public:
    float tinhPhi() {
        return 2 * (ngayTra - ngayMuon);
    }

    void nhapThongTin() {
        cout << "Nh?p thông tin ð?c gi? tr? em:" << endl;
        cout << "M? sách: "; cin >> maSach;
        cout << "Tên sách: "; cin >> tenSach;
        cout << "Tác gi?: "; cin >> tacGia;
        cout << "Tên ð?c gi?: "; cin >> tenDocGia;
        cout << "Tu?i: "; cin >> tuoi;

        do {
            cout << "Ngày mý?n: "; cin >> ngayMuon;
        } while (!kiemTraNgayHopLe(ngayMuon));

        do {
            cout << "Ngày tr?: "; cin >> ngayTra;
        } while (!kiemTraNgayHopLe(ngayTra));

        cout << "Tên ngý?i giám h?: "; cin >> tenNguoiGiamHo;
    }

    void hienThiThongTin() {
        cout << "Ð?c gi? tr? em" << endl;
        cout << "M? sách: " << maSach << endl;
        cout << "Tên sách: " << tenSach << endl;
        cout << "Tác gi?: " << tacGia << endl;
        cout << "Tên ð?c gi?: " << tenDocGia << endl;
        cout << "Tu?i: " << tuoi << endl;
        cout << "Ngày mý?n: " << ngayMuon << endl;
        cout << "Ngày tr?: " << ngayTra << endl;
        cout << "Tên ngý?i giám h?: " << tenNguoiGiamHo << endl;
        cout << "Phí: " << tinhPhi() << endl;
    }

    bool kiemTraNgayHopLe(int ngay) {
        return (ngay >= 1 && ngay <= 31);
    }
};

class DocGiaNguoiLon : public DocGia {
public:
    float tinhPhi() {
        return 3 * (ngayTra - ngayMuon);
    }

    void nhapThongTin() {
        cout << "Nh?p thông tin ð?c gi? ngý?i l?n:" << endl;
        cout << "M? sách: "; cin >> maSach;
        cout << "Tên sách: "; cin >> tenSach;
        cout << "Tác gi?: "; cin >> tacGia;
        cout << "Tên ð?c gi?: "; cin >> tenDocGia;
        cout << "Tu?i: "; cin >> tuoi;

        do {
            cout << "Ngày mý?n: "; cin >> ngayMuon;
        } while (!kiemTraNgayHopLe(ngayMuon));

        do {
            cout << "Ngày tr?: "; cin >> ngayTra;
        } while (!kiemTraNgayHopLe(ngayTra));
    }

    void hienThiThongTin() {
        cout << "Ð?c gi? ngý?i l?n" << endl;
        cout << "M? sách: " << maSach << endl;
        cout << "Tên sách: " << tenSach << endl;
        cout << "Tác gi?: " << tacGia << endl;
        cout << "Tên ð?c gi?: " << tenDocGia << endl;
        cout << "Tu?i: " << tuoi << endl;
        cout << "Ngày mý?n: " << ngayMuon << endl;
        cout << "Ngày tr?: " << ngayTra << endl;
        cout << "Phí: " << tinhPhi() << endl;
    }

    bool kiemTraNgayHopLe(int ngay) {
        return (ngay >= 1 && ngay <= 31);
    }
};

int main() {
    int n;
    cout << "Nh?p s? lý?ng ð?c gi?: ";
    cin >> n;

    vector<DocGia *> dsDocGia;

    for (int i = 0; i < n; ++i) {
        DocGia *docGiaTreEm = new DocGiaTreEm();
        docGiaTreEm->nhapThongTin();
        dsDocGia.push_back(docGiaTreEm);
    }

    for (int i = 0; i < n; ++i) {
        DocGia *docGiaNguoiLon = new DocGiaNguoiLon();
        docGiaNguoiLon->nhapThongTin();
        dsDocGia.push_back(docGiaNguoiLon);
    }

    float tongPhi = 0.0;
    for (const auto docGia : dsDocGia) {
        docGia->hienThiThongTin();
        cout << "Phí: " << docGia->tinhPhi() << endl;
        tongPhi += docGia->tinhPhi();
        cout << endl;
    }

    cout << "T?ng phí: " << tongPhi << endl;

    for (const auto docGia : dsDocGia) {
        delete docGia;
    }

    return 0;
}

