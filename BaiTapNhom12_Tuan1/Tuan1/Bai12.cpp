#include <stdlib.h>
#include <stdio.h>

struct PhanSo {
    int tu;
    int mau;
};

void khoiTaoMangPhanSo(PhanSo*& arr, int n) {
    arr = (PhanSo*)malloc(n * sizeof(PhanSo));
    if (arr == NULL) {
        printf("Cap phat bo nho that bai\n");
        exit(1);
    }
    for (int i = 0; i < n; i++) {
        arr[i].tu = rand() % 10;
        arr[i].mau = rand() % 10 + 1; 
    }
}

void xuatMangPhanSo(PhanSo* arr, int n) {
    printf("STT \t Gia tri\n");
    for (int i = 0; i < n; i++) {
        printf("%d \t %d/%d\n", i, arr[i].tu, arr[i].mau);
    }
}

int soSanhHaiPhanSo(PhanSo a, PhanSo b) {
    int tu1 = a.tu * b.mau;
    int tu2 = b.tu * a.mau;

    if (tu1 > tu2) { // a > b
        return 1;
    }
    else if (tu1 < tu2) { // a < b
        return -1;
    }
    else { // a == b
        return 0;
    }
}

void timPhanSoLonNhat(PhanSo* arr, int n) {
    PhanSo max = arr[0];
    for (int i = 1; i < n; i++) {
        if (soSanhHaiPhanSo(arr[i], max) == 1) {
            max = arr[i];
        }
    }
    printf("Phan so lon nhat la: %d/%d\n", max.tu, max.mau);
}

void timPhanSoNhoNhat(PhanSo* arr, int n) {
    PhanSo min = arr[0];
    for (int i = 1; i < n; i++) {
        if (soSanhHaiPhanSo(arr[i], min) == -1) {
            min = arr[i];
        }
    }
    printf("Phan so nho nhat la: %d/%d\n", min.tu, min.mau);
}

void bai12() {
    PhanSo* arr;
    int n;
    printf("Nhap so luong phan so: ");
    scanf_s("%d", &n);

    khoiTaoMangPhanSo(arr, n);
    xuatMangPhanSo(arr, n);

    printf("\nCau a:\n");
    timPhanSoLonNhat(arr, n);
    timPhanSoNhoNhat(arr, n);

    printf("\nCau b:\n");
    xoaPhanTuTaiViTriK(arr, n, 3);
    printf("Danh sach mang sau khi xoa phan tu tai vi tri k = 3\n");
    xuatMangPhanSo(arr, n);

    printf("\nCau c:\n");
    PhanSo x;
    x.tu = 2;
    x.mau = 3;
    themPhanTuXTaiViTriK(arr, n, 3, x);
    printf("Danh sach mang sau khi them phan tu x(2/3) tai vi tri k = 3\n");
    xuatMangPhanSo(arr, n);

    free(arr);
}

int main() {
    bai12();
    return 0;
}