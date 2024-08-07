#include <stdio.h>

// Hàm đệ quy để tính giá trị của A_n
unsigned long long A_recursive(int n) {
    if (n == 1) {
        return 1; // Giá trị cơ sở
    }

    // Kiểm tra nếu n là số chẵn
    if (n % 2 == 0) {
        int k = n / 2;
        return k + A_recursive(k) + 2;
    }
    else { // Nếu n là số lẻ
        int k = n / 2;
        return k * k + A_recursive(k) * A_recursive(k + 1) + 1;
    }
}

int main() {
    int n;
    printf("Nhap n: ");
    scanf_s("%d", &n);

    if (n < 1) {
        printf("Gia tri cua n phai la so nguyen duong.\n");
        return 1;
    }

    unsigned long long result = A_recursive(n);
    printf("A(%d) = %llu\n", n, result);

    return 0;
}
