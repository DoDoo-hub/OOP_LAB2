#include <iostream>
#include "NgayThangNam.h"
using namespace std;

bool NgayHopLe(int ngay,int thang,int nam)
{
    //Kiểm tra năm nhuận
    bool check_nhuan=0;   // 1: nhuận, 0: không nhuận
    if (nam%400==0 || (nam%4==0 && nam%100!=0))
        check_nhuan=1;

    // Xác định số ngày tối đa trong tháng
    int maxNgay;
    switch (thang) {
        case 2:
            maxNgay= check_nhuan?29:28;  //Tháng 2: nhuận:29, không nhuận:28
            break;
        case 4: case 6: case 9: case 11: //Tháng 4,6,9,11: max30 ngày
            maxNgay=30;
            break;
        default:  //Các tháng còn lại: max31 ngày
            maxNgay=31;
    }
    return (1<=ngay && ngay<=maxNgay);  //Nếu 1<=ngay<=maxNgay thì hợp lệ
}

void NgayThangNam::Nhap(){
    // Nhập năm>0
    do{
        cout<<"Nhap nam (nam>0): ";
        cin>>iNam;
    } while(iNam<=0);

    //Nhập tháng(1-12)
    do{
        cout<<"Nhap thang hop le: ";
        cin>>iThang;
    } while(1>iThang || iThang>12);

    //Nhập ngày hợp lệ dựa theo tháng và năm đã có
    cout<<"Nhap ngay hop le: ";
    cin>>iNgay;
    while(!NgayHopLe(iNgay,iThang,iNam)){
        cout<<"Ngay khong ton tai, hay nhap lai: ";
        cin>>iNgay;
    }
}

void NgayThangNam::Xuat(){
    //Xuất theo định dạng Ngày/Tháng/Năm
    cout<<iNgay<<"/"<<iThang<<"/"<<iNam<<endl;
}

NgayThangNam NgayThangNam::NgayThangNamTiepTheo(){
    NgayThangNam next= *this; //Tạo bản sao từ đối tượng hiện tại
    next.iNgay++;

    //Nếu ngày vượt quá số ngày tối đa của tháng, chuyển qua tháng mới
    if(!NgayHopLe(next.iNgay,next.iThang,next.iNam)){
        next.iNgay=1;
        next.iThang++;
    }
    //Nếu tháng vượt quá 12, chuyển qua năm mới
    if(next.iThang>12){
        next.iThang=1;
        next.iNam++;
    }

    return next;  //Trả về đối tượng ngày tiếp theo
}



