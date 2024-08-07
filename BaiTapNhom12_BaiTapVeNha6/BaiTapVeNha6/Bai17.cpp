#include <stdio.h>

// Hàm đệ quy để tính giá trị của X_n
unsigned long long X_recursive(int n) {
    if (n == 1) {
        return 1; // Giá trị cơ sở
    }
    if (n == 2) {
        return 1; // Giá trị cơ sở
    }

    // Đệ quy tính giá trị của X_n theo công thức
    return X_recursive(n - 1) + (n - 1) * X_recursive(n - 2);
}

int main() {
    int n;
    printf("Nhap n: ");
    scanf_s("%d", &n);

    if (n < 1) {
        printf("Gia tri cua n phai la so nguyen duong.\n");
        return 1;
    }

    unsigned long long result = X_recursive(n);
    printf("X(%d) = %llu\n", n, result);

    return 0;
}
