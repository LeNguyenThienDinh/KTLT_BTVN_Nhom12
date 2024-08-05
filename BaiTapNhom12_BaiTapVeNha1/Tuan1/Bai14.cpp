#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning(disable:4996)

static int currentYear = 2024;

struct Date {
    int day = 0;
    int month = 0;
    int year = 0;
};

struct NguoiLaoDong {
    char hoTen[50];
    Date ngaySinh;
    char gioiTinh[10];
    Date thoiGianNghiHuu;
    Date namDuTuoiNghiHuu;
};

Date tinhTuoiNghiHuu(int thangSinh, int namSinh, char* gioiTinh) {
    Date tuoiNghiHuu;

    if (strcmp(gioiTinh, "Nam") == 0) {
        if (thangSinh >= 1 && thangSinh <= 9 && namSinh == 1961) {
            tuoiNghiHuu = Date{ 0, 3, 60 };
        }
        else if (thangSinh >= 10 && thangSinh <= 6 && namSinh >= 1961 && namSinh <= 1962) {
            tuoiNghiHuu = Date{ 0, 6, 60 };
        }
        else if (thangSinh >= 7 && thangSinh <= 3 && namSinh >= 1962 && namSinh <= 1963) {
            tuoiNghiHuu = Date{ 0, 9, 60 };
        }
        else {
            tuoiNghiHuu = Date{ 0, 0, 62 };
        }
    }

    if (strcmp(gioiTinh, "Nu") == 0) {

        if (thangSinh >= 1 && thangSinh <= 8 && namSinh == 1966) {
            tuoiNghiHuu = Date{ 0, 4, 55 };
        }
        else if (thangSinh >= 9 && thangSinh <= 4 && namSinh >= 1966 && namSinh >= 1967) {
            tuoiNghiHuu = Date{ 0, 8, 55 };
        }
        else if (thangSinh >= 5 && thangSinh <= 12 && namSinh == 1967) {
            tuoiNghiHuu = Date{ 0, 0, 56 };
        }
        else if (thangSinh >= 1 && thangSinh <= 8 && namSinh == 1968) {
            tuoiNghiHuu = Date{ 0, 4, 56 };
        }
        else if (thangSinh >= 9 && thangSinh <= 5 && namSinh >= 1968 && namSinh <= 1969) {
            tuoiNghiHuu = Date{ 0, 8, 56 };
        }
        else if (thangSinh >= 6 && thangSinh <= 12 && namSinh == 1969) {
            tuoiNghiHuu = Date{ 0, 0, 57 };
        }
        else if (thangSinh >= 1 && thangSinh <= 8 && namSinh == 1970) {
            tuoiNghiHuu = Date{ 0, 4, 57 };
        }
        else if (thangSinh >= 9 && thangSinh <= 4 && namSinh >= 1970 && namSinh <= 1971) {
            tuoiNghiHuu = Date{ 0, 8, 57 };
        }
        else if (thangSinh >= 5 && thangSinh <= 12 && namSinh == 1971) {
            tuoiNghiHuu = Date{ 0, 0, 58 };
        }
        else if (thangSinh >= 1 && thangSinh <= 8 && namSinh == 1972) {
            tuoiNghiHuu = Date{ 0, 4, 58 };
        }
        else if (thangSinh >= 9 && thangSinh <= 4 && namSinh >= 1972 && namSinh <= 1973) {
            tuoiNghiHuu = Date{ 0, 8, 58 };
        }
        else if (thangSinh >= 5 && thangSinh <= 12 && namSinh == 1973) {
            tuoiNghiHuu = Date{ 0, 0, 59 };
        }
        else if (thangSinh >= 1 && thangSinh <= 8 && namSinh == 1974) {
            tuoiNghiHuu = Date{ 0, 4, 59 };
        }
        else if (thangSinh >= 9 && thangSinh <= 4 && namSinh >= 1974 && namSinh <= 1975) {
            tuoiNghiHuu = Date{ 0, 8, 59 };
        }
        else {
            tuoiNghiHuu = Date{ 0, 0, 60 };
        }
    }

    return tuoiNghiHuu;
}

void ganTuoiNghiHuuCuaNguoiLaoDong(NguoiLaoDong& nguoiLaoDong) {
    int thangSinh = nguoiLaoDong.ngaySinh.month;
    int namSinh = nguoiLaoDong.ngaySinh.year;

    char* gioiTinh = nguoiLaoDong.gioiTinh;

    nguoiLaoDong.thoiGianNghiHuu = tinhTuoiNghiHuu(thangSinh, namSinh, gioiTinh);
}

Date tinhNamNghiHuu(NguoiLaoDong nguoiLaoDong) {
    int thangSinh = nguoiLaoDong.ngaySinh.month;
    int namSinh = nguoiLaoDong.ngaySinh.year;

    int thangNghiHuu = nguoiLaoDong.thoiGianNghiHuu.month;
    int namNghiHuu = nguoiLaoDong.thoiGianNghiHuu.year;

    Date namDuTuoiNghiHuu;

    if (thangSinh + thangNghiHuu > 12) {
        namDuTuoiNghiHuu = Date{ 0, 0, namSinh + namNghiHuu + 1 };
    }
    else {
        namDuTuoiNghiHuu = Date{ 0, 0, namSinh + namNghiHuu };
    }

    return namDuTuoiNghiHuu;
}

void ganNamDuTuoiNghiHuuCuaNguoiLaoDong(NguoiLaoDong& nguoiLaoDong) {
    nguoiLaoDong.namDuTuoiNghiHuu = tinhNamNghiHuu(nguoiLaoDong);
}

bool kiemTraGioiTinhNguoiLaoDong(char* gioiTinh) {
    if (strcmp(gioiTinh, "Nam") != 0 && strcmp(gioiTinh, "Nu") != 0) {
        return false;
    }
    return true;
}

void nhapThongTinNguoiLaoDong(NguoiLaoDong& nguoiLaoDong) {
    printf("Nhap ho ten: ");
    scanf("%s", nguoiLaoDong.hoTen, 50);

    do {
        printf("Nhap ngay sinh (dd/mm/yyyy): ");
        scanf("%d/%d/%d", &nguoiLaoDong.ngaySinh.day, &nguoiLaoDong.ngaySinh.month, &nguoiLaoDong.ngaySinh.year);

    } while (nguoiLaoDong.ngaySinh.year > currentYear);

    do {
        printf("Nhap gioi tinh (Nam/Nu): ");
        scanf("%s", nguoiLaoDong.gioiTinh, 10);
        if (!kiemTraGioiTinhNguoiLaoDong(nguoiLaoDong.gioiTinh)) {
            printf("Gioi tinh khong hop le! Vui long nhap lai.\n");
        }
    } while (!kiemTraGioiTinhNguoiLaoDong(nguoiLaoDong.gioiTinh));
}

void xuatThongTinNguoiLaoDong(NguoiLaoDong nguoiLaoDong) {

    printf("====================================\n");
    printf("Ho ten: %s\n", nguoiLaoDong.hoTen);
    printf("Ngay sinh: %d/%d/%d\n", nguoiLaoDong.ngaySinh.day, nguoiLaoDong.ngaySinh.month, nguoiLaoDong.ngaySinh.year);
    printf("Gioi tinh: %s\n", nguoiLaoDong.gioiTinh);
    printf("Tuoi nghi huu: %d\n", nguoiLaoDong.thoiGianNghiHuu.year);

    if (nguoiLaoDong.namDuTuoiNghiHuu.month != 0) {
        printf("Nam du tuoi nghi huu: %d/%d\n", nguoiLaoDong.namDuTuoiNghiHuu.month, nguoiLaoDong.namDuTuoiNghiHuu.year);
    }
    else
    {
        printf("Nam du tuoi nghi huu: %d\n", nguoiLaoDong.namDuTuoiNghiHuu.year);
    }
}

void bai14() {
    NguoiLaoDong nguoiLaoDong;

    nhapThongTinNguoiLaoDong(nguoiLaoDong);

    ganTuoiNghiHuuCuaNguoiLaoDong(nguoiLaoDong);
    ganNamDuTuoiNghiHuuCuaNguoiLaoDong(nguoiLaoDong);

    xuatThongTinNguoiLaoDong(nguoiLaoDong);
}

int main() {
    bai14();
    return 0;
}
