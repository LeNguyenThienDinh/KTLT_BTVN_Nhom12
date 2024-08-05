#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void khoiTaoMangNgauNhien(int* a, int n, int min, int max) {
    for (int i = 0; i < n; i++) {
        a[i] = rand() % (max - min + 1) + min; // Giá trị ngẫu nhiên trong khoảng [min, max]
    }
}

float chiaHaiSo(int a, int b) {
    if (b == 0) {
        return 0;
    }
    return (float)a / b;
}

void xuatMang(int* a, int* b, int n) {
    printf("STT \t Gia tri mang A \t Gia tri mang B \t Ket qua(a/b)\n");
    for (int i = 0; i < n; i++) {
        printf("%d \t\t %d \t\t\t %d \t\t %.3f\n", i, a[i], b[i], chiaHaiSo(a[i], b[i]));
    }
}

void bai13() {
    srand(time(0));

    int n = 10;
    int a[10];
    int b[10];

    khoiTaoMangNgauNhien(a, n, 0, 100);
    khoiTaoMangNgauNhien(b, n, 0, 100);

    xuatMang(a, b, n);
}

int main() {
    bai13();
    return 0;
}