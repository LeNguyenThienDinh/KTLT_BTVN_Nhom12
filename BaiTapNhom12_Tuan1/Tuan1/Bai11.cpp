#include <stdlib.h>
#include <stdio.h>

void nhapM1C_SoNguyen(int*& a, int n) {
    a = (int*)malloc(n * sizeof(int));
    if (a == NULL) {
        printf("Cap phat bo nho that bai\n");
        exit(1);
    }
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 100;
    }
}

void xuatM1C_SoNguyen_b11(int* a, int n) {
    printf("Phan tu so\t|\tGia tri\t|\t Dia chi\n");
    for (int i = 0; i < n; i++) {
        printf("%d \t\t\t %d \t\t %p\n", i, a[i], (void*)&a[i]);
    }
}

void xuatSoCucTieu(int* a, int n) {
    int count = 0;
    printf("\na. Cac so cuc tieu trong mang la: ");
    if (n < 3) {
        printf("Khong co so cuc tieu trong mang");
        return;
    }
    for (int i = 1; i < n - 1; i++) {
        if (a[i] < a[i - 1] && a[i] < a[i + 1]) {
            printf("%d ", a[i]);
            count++;
        }
    }
    if (count == 0) {
        printf("Khong co so cuc tieu trong mang");
    }
}

void xoaPhanTuTaiViTriK(int*& a, int& n, int k) {
    for (int i = k; i < n - 1; i++) {
        a[i] = a[i + 1];
    }
    n--;
    a = (int*)realloc(a, n * sizeof(int));
    if (a == NULL && n > 0) {
        printf("Cap phat bo nho that bai\n");
        exit(1);
    }
}

void thucThiXoaPhanTuTaiViTriK(int*& a, int& n, int k) {
    if (k < 0 || k >= n) {
        printf("Vi tri k khong hop le.\n");
        return;
    }
    xoaPhanTuTaiViTriK(a, n, k);
    printf("\nb. Mang sau khi xoa phan tu tai vi tri %d la: \n", k);
    xuatM1C_SoNguyen_b11(a, n);
}

void themPhanTuTaiViTriK(int*& a, int& n, int k, int x) {
    if (k < 0 || k > n) {
        printf("Vi tri k khong hop le.\n");
        return;
    }
    n++;
    a = (int*)realloc(a, n * sizeof(int));
    if (a == NULL) {
        printf("Cap phat bo nho that bai\n");
        exit(1);
    }
    for (int i = n - 1; i > k; i--) {
        a[i] = a[i - 1];
    }
    a[k] = x;
    printf("\nb. Mang sau khi them phan tu %d tai vi tri %d la: \n", x, k);
    xuatM1C_SoNguyen_b11(a, n);
}

void bai11() {
    int* a;
    int n = 10;
    nhapM1C_SoNguyen(a, n);
    xuatM1C_SoNguyen_b11(a, n);

    xuatSoCucTieu(a, n);

    thucThiXoaPhanTuTaiViTriK(a, n, 3);

    themPhanTuTaiViTriK(a, n, 3, 100);

    chuyenSoChanLenDauSoLeXuongCuoi(a, n);

    kiemTraMangCoChuaChanLeXenKe(a, n);

    free(a);  // Free allocated memory
    printf("\n");
}

int main() {
    bai11();
    return 0;
}