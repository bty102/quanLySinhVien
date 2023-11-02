#include "D:/hoctap/C++/projects/quanLySinhVien/headerFiles/quanLySinhVien.h"
void chuanHoaHoTen(std::string &str)
{
    //chuan hoa ki tu trang
    while(str.find("  ") != std::string::npos)
    {
        str.erase(str.find("  "), 1);
    }
    if(str[0] == ' ')
        str.erase(0, 1);
    int leng = str.size();
    if(str[leng-1] == ' ')
        str.erase(leng-1, 1);
    //Cac ki tu o dau la hoa, cac ki tu con lai la thuong
    for(int i = 0; i <= str.size()-1; i++)//chuyen tat ca thanh thuong
    {
        if(str[i] >= 'A' and str[i] <= 'Z')//str[i] la hoa
        {
            //chuyen str[i] thanh thuong
            str[i] += 32;
        }
    }
    str[0] -= 32;//chuyen str[0] thanh hoa
    for(int i = 1; i <= str.size()-1; i++)//chuyen cac ki tu dau con lai thanh hoa
    {
        if(str[i] == ' ')//chuyen str[i+1] thanh hoa
            str[i+1] -= 32;
    }
}
void loadDataFromFile(sinhVien *&rHead, int &rSlPT)
{
    //mo file de doc
    std::ifstream inp("D:/hoctap/C++/projects/quanLySinhVien/data/danhSachSV.txt");
    if(inp.fail())
    {
        std::cout << "Mo file that bai!\n";
        exit(1);
    }
    //du lieu trong file se co dang: ho Va Ten;tuoi;diem
    std::string inf1SV;
    while(std::getline(inp, inf1SV))
    {
        if(inf1SV == "")
            continue;
        // std::string fname = inf1SV.substr(0, inf1SV.find(';'));
        // int age = std::stoi(inf1SV.substr(inf1SV.find(';')+1, inf1SV.rfind(';')-inf1SV.find(';')-1));
        // double mark = std::stod(inf1SV.substr(inf1SV.rfind(';')+1));
        int pos_1 = inf1SV.find(';'), pos_2 = inf1SV.rfind(';');
        std::string fname = inf1SV.substr(0, pos_1);
        chuanHoaHoTen(fname);
        int age = std::stoi(inf1SV.substr(pos_1+1, pos_2-pos_1-1));
        double mark = std::stod(inf1SV.substr(pos_2+1));
        chenCuoi(rHead, rSlPT, fname, age, mark);      
    }
    inp.close();
}
void menu()
{
    std::cout << "Danh sach thao tac:\n";
    std::cout << "[1] In danh sach sinh vien\n";
    std::cout << "[2] Them\n";
    std::cout << "[3] Sua\n";
    std::cout << "[4] Xoa\n";
    std::cout << "[5] Tim kiem\n";
    std::cout << "[6] Sap xep\n";
    std::cout << "[7] Thong ke\n";
    std::cout << "[8] Sao luu\n";
    std::cout << "[9] Thoat\n";
}
void hienThiSV(sinhVien *dcSV)
{
    //std::cout << dcSV->stt << " " << dcSV->hoTen << " " << dcSV->tuoi << " " << dcSV->diem << std::endl;
    std::cout << "\t| " << std::setw(5) << std::left << dcSV->stt << " | "
                        << std::setw(30) << std::left << dcSV->hoTen << " | "
                        << std::setw(4) << std::left << dcSV->tuoi << " | "
                        << std::setw(10) << std::left << dcSV->diem << " |\n";
}
void hienThiDanhSachSV(sinhVien *first)
{
    while(first != NULL)
    {
        //std::cout << first->stt << " " << first->hoTen << " " << first->tuoi << " " << first->diem << std::endl;
        hienThiSV(first);
        first = first->next;
	}
}
void chenCuoi(sinhVien *&rHead, int &slPT, std::string HoTen, int Tuoi, double Diem)
{
	//tao ra mot sinh vien moi 
    sinhVien *temp = new sinhVien;
    temp->stt = slPT + 1;
    temp->hoTen = HoTen;
	temp->tuoi = Tuoi;
	temp->diem = Diem;
	temp->next = NULL;

    //thuc hien chen vao cuoi 
    if(rHead == NULL)//danh sach rong 
        rHead = temp;//head = temp;
    else//danh sach khac rong 
    {
        //tim mot con tro tro den sinh vien cuoi 
        sinhVien *pC = rHead;//tao ra mot ban sao cua h va no chua dia chi cua node dau 
        while(pC->next != NULL)
        {
            pC = pC -> next;
        }
        //pC la con tro tro den sinh vien cuoi 
        pC->next = temp;//cho next cua sinh vien cuoi tro den sinh vien vua moi tao 
    }
    std::cout << "Da them mot sinh vien vao danh sach\n";
	slPT++;
}
void sua(sinhVien *first, int Stt, std::string HoTen, int Tuoi, double Diem)
{
    while(first != NULL)
    {
        if(first->stt == Stt)
        {
            if(HoTen != "*")
            {
                chuanHoaHoTen(HoTen);
                first->hoTen = HoTen;
                std::cout << "da thay doi ho ten cua sinh vien\n";
            }
            if(Tuoi != -1)
            {
                first->tuoi = Tuoi;
                std::cout << "Da thay doi tuoi cua sinh vien\n";
            }
            if(Diem != -1.0)
            {
                first->diem = Diem;
                std::cout << "Da thay doi diem cua sinh vien\n";		
            }
            return;
        }
        first = first->next;
    }
	std::cout << "Sua thong tin khong thanh cong\n";
}
void xoa(sinhVien *&rHead, int Stt, int &SLPT)
{
    sinhVien *temp = rHead;
    sinhVien *lTemp = rHead;
    while(temp != NULL)
    {
        if(temp->stt == Stt)
        {
            if(Stt == 1)//xoa dau
            {
                rHead = rHead->next;
                delete temp;
            }
            else
            {
                lTemp->next = lTemp->next->next;
                delete temp;
            }
            std::cout << "Da xoa mot sinh vien\n";
            //cap nhat stt
            sinhVien *first = rHead;
            int soThuTu = 1;
            while(first != NULL)
            {
                first->stt = soThuTu;
                soThuTu++;
                first = first->next;
            }
            //giam so luong phan tu
            SLPT--;
            return;
        }
        lTemp = temp;
        temp = temp->next;
    }
    std::cout << "Xoa khong thanh cong\n";
}
void timKiem(sinhVien *first, std::string findStr)
{
    bool timThay = false;
    while(first != NULL)
    {
        if(first->hoTen.find(findStr) != std::string::npos)//co tim thay chuoi findStr tring ho ten cua SV
        {
            hienThiSV(first);
            if(!timThay)
                timThay = true;
        }
        first = first->next;
    }
    if(!timThay)
        std::cout << "\t\t\t\tKhong tim thay\n";
}
char chuCaiDauTen(std::string hoVaTen)
{
    return ((hoVaTen.rfind(' ') != std::string::npos)? hoVaTen[hoVaTen.rfind(' ')+1] : hoVaTen[0]);
}
void hoanDoiHaiSV(sinhVien* SV_A, sinhVien *SV_B)
{
    std::swap(SV_A->hoTen, SV_B->hoTen);
    std::swap(SV_A->tuoi, SV_B->tuoi);
    std::swap(SV_A->diem, SV_B->diem);
}
void sapXep(sinhVien *first, int loaiSX)
{
    for(sinhVien *tmp1 = first; tmp1->next != NULL;tmp1 = tmp1->next)
    {
        for(sinhVien *tmp2 = tmp1->next; tmp2 != NULL;tmp2 = tmp2->next)
        {
            if(loaiSX == 1 and (chuCaiDauTen(tmp1->hoTen) > chuCaiDauTen(tmp2->hoTen)))
            {
                // std::swap(tmp1->hoTen, tmp2->hoTen);
                // std::swap(tmp1->tuoi, tmp2->tuoi);
                // std::swap(tmp1->diem, tmp2->diem);
                hoanDoiHaiSV(tmp1, tmp2);
            }
            if(loaiSX == 2 and (tmp1->tuoi > tmp2->tuoi))
            {
                // std::swap(tmp1->hoTen, tmp2->hoTen);
                // std::swap(tmp1->tuoi, tmp2->tuoi);
                // std::swap(tmp1->diem, tmp2->diem);
                hoanDoiHaiSV(tmp1, tmp2);
            }
            if(loaiSX == 3 and (tmp1->diem > tmp2->diem))
            {
                // std::swap(tmp1->hoTen, tmp2->hoTen);
                // std::swap(tmp1->tuoi, tmp2->tuoi);
                // std::swap(tmp1->diem, tmp2->diem);
                hoanDoiHaiSV(tmp1, tmp2);
            }
        }
    }
    std::cout << "Da sap xep\n";
}
void thongKe(sinhVien *first, int slPT)
{
    if(first == NULL)//danh sach rong
    {
        std::cout << "\tDanh sach rong => Khong the thong ke\n";
    }
    else
    {
        sinhVien *st_first = first;
        double tongDiemCaLop = 0, diemMax = first->diem;
        int SLSVGioi = 0, SLSVKha = 0, SLSVKem = 0;
        //diem cua SV thuoc [0; 10]
        //[0; 3.5) => Kem
        //[3.5; 6.5) => Kha
        //[6.5; 10] => Gioi
        while(first != NULL)
        {
            tongDiemCaLop += first->diem;
            if(first->diem >= 0 and first->diem < 3.5)
                SLSVKem++;
            else if(first->diem < 6.5)
                SLSVKha++;
            else
                SLSVGioi++;
            if(first->diem > diemMax)
                diemMax = first->diem;
            first = first->next;
        }
        std::cout << "Diem trung binh ca lop: " << tongDiemCaLop/slPT << std::endl;
        std::cout << "Ty le sinh vien gioi: " << ((1.0*SLSVGioi)/slPT)*100 << "%\n";
        std::cout << "Ty le sinh vien kha: " << ((1.0*SLSVKha)/slPT)*100 << "%\n";
        std::cout << "Ty le sinh vien kem: " << ((1.0*SLSVKem)/slPT)*100 << "%\n";
        std::cout << "Nhung sinh vien co diem cao nhat (" << diemMax << ") la:\n";
        std::cout << "\t+------------------------------------------------------------+\n";
        std::cout << "\t| " << std::setw(5) << std::left << "Stt" << " | "
                            << std::setw(30) << std::left << "Ho va ten" << " | "
                            << std::setw(4) << std::left << "Tuoi" << " | "
                            << std::setw(10) << std::left << "Diem" << " |\n";
        std::cout << "\t+------------------------------------------------------------+\n";
        while(st_first != NULL)
        {
            if(st_first->diem == diemMax)
                hienThiSV(st_first);
            st_first = st_first->next;
        }
        std::cout << "\t+------------------------------------------------------------+\n";
    }
}
void saoLuu(sinhVien *first)
{
    std::ofstream out("D:/hoctap/C++/projects/quanLySinhVien/data/danhSachSV.txt");
    if(out.fail())
    {
        std::cout << "Mo file that bai!\n";
        exit(1);
    }
    while(first != NULL)
    {
        //du lieu trong file se co dang: ho Va Ten;tuoi;diem
        out << first->hoTen << ";" << first->tuoi << ";" << first->diem << std::endl;
        first = first->next;
    }
    std::cout << "Da sao luu xong\n";
    out.close();
}
void stopAndClear()
{
    system("pause");
    system("cls");
}
