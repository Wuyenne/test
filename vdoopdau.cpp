#include <iostream>

using namespace std;

class Fraction {
private:
    float numerator; 
    float denominator; 

public:
    void inputFraction() {
        cout << "Nhap tu so: ";
        cin >> numerator;

        cout << "Nhap mau so: ";
        cin >> denominator;

        cin.ignore();
    }

    void outputFraction() const {
        cout << "So thuc: " << numerator << " / " << denominator << endl;
    }
};

int main() {
    Fraction fraction; 

    fraction.inputFraction();

    fraction.outputFraction();

    return 0;
}
