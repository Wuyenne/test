#include <iostream>
#include <string.h>
using namespace std;

class GV {
private:
    char ht[30];
    int tuoi;
    char bangcap[15];
	char chuyennganh[20];
    float bacluong,lcb;

public:
	
    GV(char ht[]="", int tuoi=0,char *bangcap="",char *chuyennganh="", float bacluong=0.0) {
        strcpy(this->ht,ht);
        this->tuoi=tuoi; 
        strcpy(bangcap,bangcap);
        strcpy(this->chuyennganh, chuyennganh);
        this->bacluong = bacluong;
    }

    void nhapthongtin() {
        cout << "Nhap ho ten: ";
        fflush(stdin); 
        cin.getline(ht,30);
        
        cout << "Nhap tuoi: ";
        cin >>this->tuoi;
        cin.ignore(); 

        cout << "Nhap bang cap: ";
        cin.getline(this->bangcap,15);

        cout << "Nhap chuyen nganh: ";
        cin.getline(this->chuyennganh,20);

        cout << "Nhap bac luong: ";
        cin >> this->bacluong;
        cin.ignore(); 
    }

    void hienthithongtin() {
        cout << "Ho ten: " << this->ht <<endl;
        cout << "Tuoi: " << this->tuoi <<endl;
        cout << "Bang cap: " << this->bangcap <<endl;
        cout << "Chuyen nganh: " << this->chuyennganh << endl;
        cout << "Bac luong: " << this->bacluong <<endl;
        cout<<  "Luong co ban"<<this->lcb; 
    }

    float tinhluongcoban() {
        return this->bacluong * 610;
    }
};

/*bool compareChuyenNganh(const GV& gv1, const GV& gv2) {
    return strcmp(gv1.chuyennganh, gv2.chuyennganh) < 0;
}*/

int main() {
	GV gv; 
    int n;
    cout << "Nhap so luong giang vien (n): ";
    cin >> n;
    cin.ignore(); 

    GV danhSachGiaoVien;
    for (int i = 0; i < n; i++) {
        GV giaoVien;
        cout << "\nNhap thong tin cho giang vien thu " << i + 1 << ":\n";
        giaoVien.nhapthongtin();
    }

 
    cout << "\nDanh sach cac giang vien co tien luong nho hon 2000:\n";
    for ( int i = 0; i < n; i++) {
        if (gv.tinhluongcoban() < 2000) {
            gv.hienthithongtin();
            cout << "Luong co ban: " << gv.tinhluongcoban() << endl;
        }
    }

   
    //sort(danhSachGiaoVien.begin(), danhSachGiaoVien.end(), compareChuyenNganh);

    
    cout << "\nDanh sach giang vien sap xep theo chuyen nganh:\n";
    for ( int i = 0; i < n; i++) {
        gv.hienthithongtin();
        cout << "Luong co ban: " << gv.tinhluongcoban() <<endl;
    }

    return 0;
}

