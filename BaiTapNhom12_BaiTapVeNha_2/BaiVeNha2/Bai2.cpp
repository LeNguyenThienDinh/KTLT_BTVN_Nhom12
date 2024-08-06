#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int phan_nguyen;
    int tu_so;
    int mau_so;
} HonSo;

void taoMangNgauNhien(HonSo b[], int n);
void xuatDanhSachHonSo(HonSo b[], int n);
int linearSearch(HonSo b[], int n, HonSo x);
void sapXepChanLe(HonSo b[], int n);
int binarySearch(HonSo b[], int left, int right, HonSo x);
void chiaMang(HonSo b[], int n, int s1[], HonSo s2[]);
void xoaPhanTu(HonSo b[], int* n, int k);
void themHonSo(HonSo b[], int* n, HonSo x, int k);
void taoMangPhanSo(HonSo b[], int n, float c[]);
HonSo tongHonSo(HonSo b[], int n);
HonSo timMax(HonSo b[], int n);
HonSo timMin(HonSo b[], int n);
void xuatViTriChan(HonSo b[], int n);
void xuatViTriMaxMin(HonSo b[], int n);

int main() {
    srand(time(0));
    int n = 10;
    HonSo b[100];
    taoMangNgauNhien(b, n);
    printf("Danh sach hon so ngau nhien:\n");
    xuatDanhSachHonSo(b, n);

    HonSo x = { 2, 1, 3 };
    int idx = linearSearch(b, n, x);
    if (idx != -1) {
        printf("Tim thay hon so x tai vi tri %d\n", idx);
    }
    else {
        printf("Khong tim thay hon so x\n");
    }

    sapXepChanLe(b, n);
    printf("Danh sach sau khi sap xep chan le:\n");
    xuatDanhSachHonSo(b, n);

    idx = binarySearch(b, 0, n - 1, x);
    if (idx != -1) {
        printf("Tim thay hon so x tai vi tri %d (binary search)\n", idx);
    }
    else {
        printf("Khong tim thay hon so x (binary search)\n");
    }

    int s1[100];
    HonSo s2[100];
    chiaMang(b, n, s1, s2);

    xoaPhanTu(b, &n, 3);
    printf("Danh sach sau khi xoa phan tu thu 3:\n");
    xuatDanhSachHonSo(b, n);

    themHonSo(b, &n, x, 3);
    printf("Danh sach sau khi them hon so tai vi tri 3:\n");
    xuatDanhSachHonSo(b, n);

    float c[100];
    taoMangPhanSo(b, n, c);

    HonSo tong = tongHonSo(b, n);
    printf("Tong cac hon so: %d %d/%d\n", tong.phan_nguyen, tong.tu_so, tong.mau_so);

    HonSo max = timMax(b, n);
    printf("Hon so lon nhat: %d %d/%d\n", max.phan_nguyen, max.tu_so, max.mau_so);

    HonSo min = timMin(b, n);
    printf("Hon so nho nhat: %d %d/%d\n", min.phan_nguyen, min.tu_so, min.mau_so);

    xuatViTriChan(b, n);
    xuatViTriMaxMin(b, n);

    return 0;
}
void taoMangNgauNhien(HonSo b[], int n) {
    for (int i = 0; i < n; i++) {
        b[i].phan_nguyen = rand() % 10;
        b[i].tu_so = rand() % 10;
        b[i].mau_so = rand() % 9 + 1; // Mau so khac 0
    }
}

void xuatDanhSachHonSo(HonSo b[], int n) {
    for (int i = 0; i < n; i++) {
        printf("\n%d %d/%d ", b[i].phan_nguyen, b[i].tu_so, b[i].mau_so);
    }
    printf("\n");
}

int linearSearch(HonSo b[], int n, HonSo x) {
    for (int i = 0; i < n; i++) {
        if (b[i].phan_nguyen == x.phan_nguyen && b[i].tu_so == x.tu_so && b[i].mau_so == x.mau_so) {
            return i;
        }
    }
    return -1;
}
void sapXepChanLe(HonSo b[], int n) {
    int left = 0, right = n - 1;
    while (left < right) {
        while (left < n && b[left].phan_nguyen % 2 == 0) {
            left++;
        }
        while (right >= 0 && b[right].phan_nguyen % 2 != 0) {
            right--;
        }
        if (left < right) {
            HonSo temp = b[left];
            b[left] = b[right];
            b[right] = temp;
        }
    }
}
