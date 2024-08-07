#include <stdio.h>

// Hàm đệ quy để tính giá trị của x_n
unsigned long long x_recursive(int n) {
    if (n == 0) {
        return 1; // Giá trị cơ sở x0
    }
    if (n == 1) {
        return 2; // Giá trị cơ sở x1
    }

    // Đệ quy tính giá trị của x_n theo công thức
    unsigned long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += (n - i) * x_recursive(i);
    }
    return sum;
}

int main() {
    int n;
    printf("Nhap n: ");
    scanf_s("%d", &n);

    if (n < 0) {
        printf("Gia tri cua n phai la so nguyen khong am.\n");
        return 1;
    }

    unsigned long long result = x_recursive(n);
    printf("X(%d) = %llu\n", n, result);

    return 0;
}
