#include <iostream>
#include <string.h>
using namespace std;

class Nguoi {
private:
	char ht[30];
	int t;
	float tb;

public:
	Nguoi(){
		strcpy(t,"chua nhap");
		t=0;
		tb=0.0;
	}
	Nguoi(char ten[30],int tuoi,float diem){
				strcpy(this->ten,ten);
				this->t=t;
				this->tb=tb;
   } 
	void nhap()
			{
				cout<<"Nhap ten";
				cin.getline(ten,30);
				cout<<"Nhap tuoi";
				cin>>this->tuoi;
				cout<<"Nhap diem";
				cin>>diem;
			}
    string xetDanhHieu() const {
        if (diemTB >= 8)
            return "Gioi";
        else if (diemTB >= 7)
            return "Kha";
        else if (diemTB >= 5)
            return "Trung binh";
        else
            return "Kem";
    }
			void xuat();
				
};
void Nguoi::xuat(){
	cout<<"Ten "<<ten<<endl
		<<"Tuoi "<<this->tuoi<<endl
		<<"Diem "<<diem<<endl; 
}
int main(){
	Nguoi a;
	a.xuat();
	return 0;
}
