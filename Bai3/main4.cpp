#include <iostream>
#include "SoPhuc.h"
#include <cmath>
using namespace std;

//Hàm main của class SoPhuc
int main(){
    SoPhuc a,b;
    cout<< "Nhap so phuc A:\n";
    a.Nhap();

    cout<< "Nhap so phuc B:\n";
    b.Nhap();

    cout<< "\nSo phuc A: ";
    a.Xuat();

    cout<< "\nSo phuc B: ";
    b.Xuat();

    // Tính toán
    SoPhuc tong = a.Tong(b);
    SoPhuc hieu = a.Hieu(b);
    SoPhuc tich = a.Tich(b);

    cout << "\n\nTong: ";
    tong.Xuat();

    cout << "\nHieu: ";
    hieu.Xuat();

    cout << "\nTich: ";
    tich.Xuat();

    SoPhuc thuong = a.Thuong(b);
    cout << "\nThuong: ";
    thuong.Xuat();

    return 0;
}
