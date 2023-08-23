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
        cout << "Nh?p th�ng tin �?c gi? tr? em:" << endl;
        cout << "M? s�ch: "; cin >> maSach;
        cout << "T�n s�ch: "; cin >> tenSach;
        cout << "T�c gi?: "; cin >> tacGia;
        cout << "T�n �?c gi?: "; cin >> tenDocGia;
        cout << "Tu?i: "; cin >> tuoi;

        do {
            cout << "Ng�y m�?n: "; cin >> ngayMuon;
        } while (!kiemTraNgayHopLe(ngayMuon));

        do {
            cout << "Ng�y tr?: "; cin >> ngayTra;
        } while (!kiemTraNgayHopLe(ngayTra));

        cout << "T�n ng�?i gi�m h?: "; cin >> tenNguoiGiamHo;
    }

    void hienThiThongTin() {
        cout << "�?c gi? tr? em" << endl;
        cout << "M? s�ch: " << maSach << endl;
        cout << "T�n s�ch: " << tenSach << endl;
        cout << "T�c gi?: " << tacGia << endl;
        cout << "T�n �?c gi?: " << tenDocGia << endl;
        cout << "Tu?i: " << tuoi << endl;
        cout << "Ng�y m�?n: " << ngayMuon << endl;
        cout << "Ng�y tr?: " << ngayTra << endl;
        cout << "T�n ng�?i gi�m h?: " << tenNguoiGiamHo << endl;
        cout << "Ph�: " << tinhPhi() << endl;
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
        cout << "Nh?p th�ng tin �?c gi? ng�?i l?n:" << endl;
        cout << "M? s�ch: "; cin >> maSach;
        cout << "T�n s�ch: "; cin >> tenSach;
        cout << "T�c gi?: "; cin >> tacGia;
        cout << "T�n �?c gi?: "; cin >> tenDocGia;
        cout << "Tu?i: "; cin >> tuoi;

        do {
            cout << "Ng�y m�?n: "; cin >> ngayMuon;
        } while (!kiemTraNgayHopLe(ngayMuon));

        do {
            cout << "Ng�y tr?: "; cin >> ngayTra;
        } while (!kiemTraNgayHopLe(ngayTra));
    }

    void hienThiThongTin() {
        cout << "�?c gi? ng�?i l?n" << endl;
        cout << "M? s�ch: " << maSach << endl;
        cout << "T�n s�ch: " << tenSach << endl;
        cout << "T�c gi?: " << tacGia << endl;
        cout << "T�n �?c gi?: " << tenDocGia << endl;
        cout << "Tu?i: " << tuoi << endl;
        cout << "Ng�y m�?n: " << ngayMuon << endl;
        cout << "Ng�y tr?: " << ngayTra << endl;
        cout << "Ph�: " << tinhPhi() << endl;
    }

    bool kiemTraNgayHopLe(int ngay) {
        return (ngay >= 1 && ngay <= 31);
    }
};

int main() {
    int n;
    cout << "Nh?p s? l�?ng �?c gi?: ";
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
        cout << "Ph�: " << docGia->tinhPhi() << endl;
        tongPhi += docGia->tinhPhi();
        cout << endl;
    }

    cout << "T?ng ph�: " << tongPhi << endl;

    for (const auto docGia : dsDocGia) {
        delete docGia;
    }

    return 0;
}

