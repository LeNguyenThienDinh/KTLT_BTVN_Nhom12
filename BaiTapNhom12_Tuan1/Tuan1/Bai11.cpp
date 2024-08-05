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