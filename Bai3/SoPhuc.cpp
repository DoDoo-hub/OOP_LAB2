#include <iostream>
#include "SoPhuc.h"
#include <cmath>
using namespace std;

void SoPhuc::Nhap(){
    cout<< "Nhap phan thuc: ";
    cin>>iThuc;
    cout<< "Nhap phan ao: ";
    cin>>iAo;
}

void SoPhuc::Xuat(){
    if(iThuc==0 && iAo==0) cout<<0; // cả phần thực và ảo đều=0 =>số phức=0

    if(isnan(iThuc) && isnan(iAo)){ // kết quả của phép chia cho 0(không xác định)
        cout<< "Khong xac dinh (Chia cho 0)";
        return ;
    }

    //Định dạng lại cách in
    if(iThuc!=0)
        cout<<iThuc;
    if(iAo!=0){
        if(iThuc!=0){
            cout<< (iAo<0?" - ":" + ");
            cout<< abs(iAo);
        }
        else cout<< iAo;

        cout<<"i";
    }
}

SoPhuc SoPhuc::Tong(SoPhuc sp){
    SoPhuc kq;
    kq.iThuc= iThuc + sp.iThuc;
    kq.iAo= iAo + sp.iAo;
    return kq;
}
SoPhuc SoPhuc::Hieu(SoPhuc sp){
    SoPhuc kq;
    kq.iThuc= iThuc - sp.iThuc;
    kq.iAo= iAo - sp.iAo;
    return kq;
}

SoPhuc SoPhuc::Tich(SoPhuc sp){
    SoPhuc kq;
    //Sau khi nhân phân phối và thay i*i=-1 thì ta có kết quả:
    kq.iThuc= iThuc*sp.iThuc - iAo*sp.iAo;
    kq.iAo= iThuc*sp.iAo + iAo*sp.iThuc;
    return kq;
}

SoPhuc SoPhuc::Thuong(SoPhuc sp){
    SoPhuc kq;
    //Chia 2 số phức: nhân cả tử và mẫu với số phức liên hợp của mẫu số, ta có kết quả:
    double mau= sp.iThuc*sp.iThuc + sp.iAo*sp.iAo;
    if(mau==0){  // Trường hợp chia cho 0, gán kq= giá trị "Không xác định" NaN (Not a Number)
        kq.iThuc=NAN;
        kq.iAo=NAN;
        return kq;
    }

    kq.iThuc= (iThuc*sp.iThuc + iAo*sp.iAo) / mau;
    kq.iAo= (iAo*sp.iThuc - iThuc*sp.iAo) / mau;
    return kq;
}
