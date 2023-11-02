#pragma once
#include "library.h"
#include <fstream>
struct sinhVien
{
    int stt;
    std::string hoTen;
    int tuoi;
    double diem;
    sinhVien *next;
};
void chuanHoaHoTen(std::string &str);
/*
@ham load du lieu tu file de dua vao danh sach
@Parameter
> rHead: tham chieu den head
> rSlPT: tham chieu den soLuongSV
*/
void loadDataFromFile(sinhVien *&rHead, int &rSlPT);
//ham hien thi danh sach cac thao tac
void menu();
/*
@ham hien thi thong tin cua mot SV
@Parameter:
> dcSV: dia chi cua SV muon hien thi 
*/
void hienThiSV(sinhVien *dcSV);
/*
@ham hien thi danh sach sinh vien
@Parameter:
> first: chua dia chi cua sinh vien dau danh sach
*/
void hienThiDanhSachSV(sinhVien *first);
/*
@ham chen mot sinh vien vao cuoi danh sach
@Parameter:
> rHead: tham chieu den head
> slPT: tham chieu den soLuongSV
> HoTen: ho ten cua sinh vien can chen
> Tuoi: tuoi cua sinh vien can chen
> Diem: diem cua sinh vien can chen
*/
void chenCuoi(sinhVien *&rHead, int &slPT, std::string HoTen, int Tuoi, double Diem);
/*
@ham sua doi thong tin cua mot sinh vien
@Parameter:
> first: chua dia chi cua sinh vien dau tien
> Stt: so thu tu cua sinh vien can sua
> HoTen: ho ten thay the(giu nguyen ho ten cu neu HoTen = "*")
> Tuoi: tuoi thay the(giu nguyen tuoi cu neu Tuoi = -1)
> Diem: diem thay the(giu nguyen diem cu neu Diem = -1.0)
*/
void sua(sinhVien *first, int Stt, std::string HoTen, int Tuoi, double Diem);
/*
@ham xoa mot sinh vien khoi danh sach
@Parameter:
> rHead: tham chieu den head
> Stt: so thu tu cua sinh vien muon xoa
> SLPT: tham chieu den soLuongSV 
*/
void xoa(sinhVien *&rHead, int Stt, int &SLPT);
/*
@ham tim kiem nhung sinh vien co ho ten phu hop voi chuoi cho truoc
@Parameter:
> first: chua dia chi SV dau 
> findStr: chuoi de tim kiem
*/
void timKiem(sinhVien *first, std::string findStr);
/*
@ham lay chu cai dau ten
@Parameter:
> hoVaTen: ho ten cua SV can lay chu cai dau 
*/
char chuCaiDauTen(std::string hoVaTen);
/*
@ham hoan doi vi tri cua hai SV
@Parameter:
> SV_A, SV_B: chua dia chi cua hai SV can hoan doi
*/
void hoanDoiHaiSV(sinhVien* SV_A, sinhVien *SV_B);
/*
@ham sap xep danh sach sinh vien
@Parameter:
> first: chua dia chi SV dau 
> loaiSX: 
        = 1 (sap xep theo chu cai dau cua ten tu A den Z)
        = 2 (sap xep theo tuoi tang dan)
        = 3 (sap xep theo diem tang dan)
*/
void sapXep(sinhVien *first, int loaiSX);
/*
@ham thong ke:
    - DTB ca lop
    - Ti le SV gioi
    - Ti le SV kha
    - Ti le SV kem
    - Diem cao nhat va nhung SV co diem cao nhat
@Parameter:
> first: chua dia chi SV dau 
> slPT: so luong sinh vien cua lop 
*/
void thongKe(sinhVien *first, int slPT);
/*
@ham sao luu danh sach sinh vien
@Parameter:
> first: chua dia chi cua SV dau DS
*/
void saoLuu(sinhVien *first);
void stopAndClear();
