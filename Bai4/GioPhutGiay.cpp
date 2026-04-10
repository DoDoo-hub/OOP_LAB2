#include <iostream>
#include "GioPhutGiay.h"
using namespace std;

void GioPhutGiay::Nhap(){
    // giophutgiay lớn nhất là: 23:59:59, thêm 1s nữa sẽ là 00:00:00 của ngày mới
    //Định dạng theo đồng hồ điện tử
    do{
        cout<<"Nhap gio hop le: ";
        cin>>iGio;
    } while(0>iGio || iGio>23);

    do{
        cout<<"Nhap phut hop le: ";
        cin>>iPhut;
    } while(0>iPhut || iPhut>59);

    do{
        cout<<"Nhap giay hop le: ";
        cin>>iGiay;
    } while(0>iGiay || iGiay>59);
}

void GioPhutGiay::Xuat(){
    cout<<iGio<<" gio "<<iPhut<<" phut "<<iGiay<<" giay "<<endl;
}

GioPhutGiay GioPhutGiay::TinhCongThemMotGiay(){
    GioPhutGiay next= *this;  //Tạo bản sao từ đối tượng hiện tại
    next.iGiay++;

    //Kiểm tra và xử lý các ngưỡng bị tràn
    if(next.iGiay>59)  //Reset giây và sang phút tiếp theo
    {
        next.iGiay=0;
        next.iPhut++;
    }

    if(next.iPhut>59)  //Reset phút và sang giờ tiếp theo
    {
        next.iPhut=0;
        next.iGio++;
    }

    //Reset giờ (chuyển sang ngày mới)
    if(next.iGio>23)
    {
        next.iGio=0;
    }

    return next;
}
