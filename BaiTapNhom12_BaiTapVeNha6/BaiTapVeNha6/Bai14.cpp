#include <stdio.h>

// Hàm đệ quy để tính giá trị của U(n)
unsigned long long U_recursive(int n) {
    if (n < 6) {
        return n; // Nếu n < 6, trả về giá trị n
    }
    return U_recursive(n - 5) + U_recursive(n - 4) + U_recursive(n - 3) + U_recursive(n - 2) + U_recursive(n - 1);
}

int main() {
    int n;
    printf("Nhap n: ");
    scanf_s("%d", &n);

    if (n <= 0) {
        printf("Gia tri cua n phai la so nguyen duong.\n");
        return 1;
    }

    unsigned long long result = U_recursive(n);
    printf("U(%d) = %llu\n", n, result);

    return 0;
}
