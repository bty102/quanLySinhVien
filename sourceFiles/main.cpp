#include "D:/hoctap/C++/projects/quanLySinhVien/headerFiles/library.h"
#include "D:/hoctap/C++/projects/quanLySinhVien/headerFiles/quanLySinhVien.h"
int main()
{
    sinhVien * head = NULL;
    int soLuongSV = 0;
    loadDataFromFile(head, soLuongSV);
    while(true)
    {
        menu();
        int stm;
        std::cout << "Nhap lenh: ";
        std::cin >> stm;
        if(stm == 1)//in ds sinh vien
        {
            std::cout << "\t+------------------------------------------------------------+\n";
            std::cout << "\t| " << std::setw(5) << std::left << "Stt" << " | "
                                << std::setw(30) << std::left << "Ho va ten" << " | "
                                << std::setw(4) << std::left << "Tuoi" << " | "
                                << std::setw(10) << std::left << "Diem" << " |\n";
            std::cout << "\t+------------------------------------------------------------+\n";
            hienThiDanhSachSV(head);
            std::cout << "\t+------------------------------------------------------------+\n";
            // system("pause");
            // system("cls");
            stopAndClear();
        }
        else if(stm == 2)//them
        {
            std::string HT;
            int T;
            double D;
            std::cin.ignore();
            std::cout << "Nhap ho va ten: ";
            std::getline(std::cin, HT);
            chuanHoaHoTen(HT);
            std::cout << "Nhap tuoi: ";
            std::cin >> T;
            std::cout << "Nhap diem: ";
            std::cin >> D;
            chenCuoi(head, soLuongSV, HT, T, D);
            // system("pause");
            // system("cls");
            stopAndClear();
        }
        else if(stm == 3)//sua
        {
            std::cout << "Nhap so thu tu cua SV muon sua: ";
            int stt;
            std::cin >> stt;
            std::string rfname;
            int rage;
            double rmark;
            std::cout << "Nhap ho va ten muon sua(Nhap * neu khong muon thay doi): ";
            std::cin.ignore();
            std::getline(std::cin, rfname);
            std::cout << "Nhap tuoi muon sua(Nhap -1 neu khong muon thay doi): ";
            std::cin >> rage;
            std::cout << "Nhap diem muon sua(Nhap -1.0 neu khong muon thay doi): ";
            std::cin >> rmark;
            sua(head, stt, rfname, rage, rmark);
            // system("pause");
            // system("cls");
            stopAndClear();
        }
        else if(stm == 4)//xoa
        {
            int stt;
            std::cout << "Nhap so thu tu cua SV muon xoa: ";
            std::cin >> stt;
            xoa(head, stt, soLuongSV);
            // system("pause");
            // system("cls");
            stopAndClear();
        }
        else if(stm == 5)//tim kiem
        {
            std::string chuoiTim;
            std::cout << "Nhap chuoi: ";
            std::cin.ignore();
            std::getline(std::cin, chuoiTim);
            std::cout << "\t+------------------------------------------------------------+\n";
            std::cout << "\t| " << std::setw(5) << std::left << "Stt" << " | "
                                << std::setw(30) << std::left << "Ho va ten" << " | "
                                << std::setw(4) << std::left << "Tuoi" << " | "
                                << std::setw(10) << std::left << "Diem" << " |\n";
            std::cout << "\t+------------------------------------------------------------+\n";
            timKiem(head, chuoiTim);
            std::cout << "\t+------------------------------------------------------------+\n";
            // system("pause");
            // system("cls");
            stopAndClear();
        }
        else if(stm == 6)//sap xep
        {
            int lXS;
            std::cout << "Cac loai sap xep:\n";
            std::cout << "[1] sap xep theo chu cai dau cua ten tu A den Z\n";
            std::cout << "[2] sap xep theo tuoi tang dan\n";
            std::cout << "[3] sap xep theo diem tang dan\n";
            std::cout << "Chon loai sap xep: ";
            std::cin >> lXS;
            if(lXS == 1 or lXS == 2 or lXS == 3)
            {
                sapXep(head, lXS);
                // system("pause");
                // system("cls");
                stopAndClear();
            }
            else
            {
                std::cout << "loai sap xep khong hop le\n";
                // system("pause");
                // system("cls");
                stopAndClear();
            }
        }
        else if(stm == 7)//thong ke
        {
            thongKe(head, soLuongSV);
            // system("pause");
            // system("cls");
            stopAndClear();
        }
        else if(stm == 8)//sao luu
        {
            saoLuu(head);
            // system("pause");
            // system("cls");
            stopAndClear();
        }
        else if(stm == 9)
        {
            break;
        }
        else
        {
            std::cout << "Lenh khong hop le\n";
            // system("pause");
            // system("cls");
            stopAndClear();
        }
    }
    return 0;
}
