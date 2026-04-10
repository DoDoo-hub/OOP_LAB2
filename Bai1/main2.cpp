#include <iostream>
#include "NgayThangNam.h"
using namespace std;

//Hàm main của class NgayThangNam
int main(){
    NgayThangNam date;
    cout << "Nhap ngay thang nam: \n";
    date.Nhap();

    cout << "\nNgay thang nam hien tai: ";
    date.Xuat();

    NgayThangNam next_d;
    cout<<"\nNgay thang nam tiep theo: ";
    next_d=date.NgayThangNamTiepTheo();
    next_d.Xuat();

    return 0;
}
