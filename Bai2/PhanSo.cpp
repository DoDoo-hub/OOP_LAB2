#include <iostream>
#include "PhanSo.h"
using namespace std;

int UCLN(int a,int b){
    if(b==0) return a;
    return UCLN(b,a%b);
}

void PhanSo::Nhap(){
    cout<< "Nhap tu: ";
    cin>>iTu;
    do{
        cout<< "Nhap mau (khac 0): ";
        cin>>iMau;
    }while (iMau==0);
}

void PhanSo::Xuat(){
    if(iTu==0) cout<<0;
    else cout<< iTu << "/" << iMau;
}

void PhanSo::RutGon(){
    // Chia cả tử và mẫu cho ước chung lớn nhất để rút gọn
    int ucln=UCLN(abs(iTu),abs(iMau));
    iTu/=ucln;
    iMau/=ucln;

    // Đưa dấu về tử
    if (iMau<0){
        iTu=-iTu;
        iMau=-iMau;
    }
}

PhanSo PhanSo::Tong(PhanSo ps){
    // Quy đồng rồi cộng 2 phân số, rút gọn kết quả
    PhanSo kq;
    kq.iTu= iTu * ps.iMau + ps.iTu * iMau;
    kq.iMau = iMau * ps.iMau;
    kq.RutGon();
    return kq;
}

PhanSo PhanSo::Hieu(PhanSo ps){
    // Quy đồng rồi trừ 2 phân số, rút gọn kết quả
    PhanSo kq;
    kq.iTu = iTu * ps.iMau - ps.iTu * iMau;
    kq.iMau = iMau * ps.iMau;
    kq.RutGon();
    return kq;
}

PhanSo PhanSo::Tich(PhanSo ps){
    // Nhân 2 phân số rồi rút gọn kết quả
    PhanSo kq;
    kq.iTu = iTu * ps.iTu;
    kq.iMau = iMau * ps.iMau;
    kq.RutGon();
    return kq;

}

PhanSo PhanSo::Thuong(PhanSo ps){
    // Phép chia=Phép nhân ps thứ nhất với nghịch đảo ps thứ 2
    PhanSo kq;
    kq.iTu = iTu * ps.iMau;
    kq.iMau = iMau * ps.iTu;
    kq.RutGon();

    // Khi chia cho phân số 0, kết quả sau khi tính toán và rút gọn là 1/0
    //In ra thông báo lỗi, và trả về giá trị 1/0(mặc định hiểu là phép chia cho 0)
    if(kq.iMau==0) //Điều kiện nhận biết chia cho ps 0
        cout<< "\nLoi: Khong the chia cho 0";
    return kq;

}

int PhanSo::SoSanh(PhanSo ps){
    //Quy đồng 2 ps, so sánh tử số sau quy đồng
    int left = iTu * ps.iMau;
    int right = ps.iTu * iMau;

    if (left > right) return 1;
    if (left == right) return 0;
    return -1;

} //Output  1: >, 0: =, -1: <
