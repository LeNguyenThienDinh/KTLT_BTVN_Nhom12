#include <stdio.h>

// Hàm đệ quy để tính giá trị của A_n
unsigned long long A_recursive(int n, unsigned long long* A) {
    if (n == 1) {
        A[1] = 1; // Giá trị cơ sở
        return 1;
    }

    if (A[n] != 0) {
        return A[n]; // Trả về giá trị đã tính nếu đã có
    }

    // Tính giá trị của A_n bằng cách sử dụng tổng của các phần tử trước đó
    unsigned long long sum = 0;
    for (int i = 1; i < n; ++i) {
        sum += A_recursive(i, A); // Tính đệ quy các giá trị trước
    }

    A[n] = n * sum;
    return A[n];
}

int main() {
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);

    if (n < 1) {
        printf("Gia tri cua n phai la so nguyen duong.\n");
        return 1;
    }

    // Khai báo mảng để lưu trữ các giá trị A
    unsigned long long A[n + 1];
    for (int i = 0; i <= n; ++i) {
        A[i] = 0; // Khởi tạo giá trị của mảng
    }

    unsigned long long result = A_recursive(n, A);
    printf("A(%d) = %llu\n", n, result);

    return 0;
}
