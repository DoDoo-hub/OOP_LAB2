#include <iostream>
#include "GioPhutGiay.h"
using namespace std;

//Hàm main của class GioPhutGiay
int main(){
    GioPhutGiay time;
    cout << "Nhap gio phut giay: \n";
    time.Nhap();

    cout << "\nBay gio la: ";  // Thời gian
    time.Xuat();

    GioPhutGiay next_t;
    cout<<"\nSau 1 giay nua la: ";  //Thời gian sau 1 giây nữa
    next_t=time.TinhCongThemMotGiay();
    next_t.Xuat();

    return 0;
}
