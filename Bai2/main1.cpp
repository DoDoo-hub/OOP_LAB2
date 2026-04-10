#include <iostream>
#include "PhanSo.h"
using namespace std;

int main(){
    PhanSo a,b;
    cout << "Nhap phan so A:\n";
    a.Nhap();

    cout << "Nhap phan so B:\n";
    b.Nhap();

    cout << "\nPhan so A: ";
    a.RutGon();
    a.Xuat();

    cout << "\nPhan so B: ";
    b.RutGon();
    b.Xuat();

    // Tính toán
    PhanSo tong = a.Tong(b);
    PhanSo hieu = a.Hieu(b);
    PhanSo tich = a.Tich(b);

    cout << "\n\nTong: ";
    tong.Xuat();

    cout << "\nHieu: ";
    hieu.Xuat();

    cout << "\nTich: ";
    tich.Xuat();

    PhanSo thuong = a.Thuong(b);
    cout << "\nThuong: ";
    thuong.Xuat();

    // So sánh
    cout<< "\nSo sanh: ";
    int cmp = a.SoSanh(b);
    if (cmp == 1)
        cout << "A > B";
    else if (cmp == 0)
        cout << "A = B";
    else
        cout << "A < B";

    return 0;
}
