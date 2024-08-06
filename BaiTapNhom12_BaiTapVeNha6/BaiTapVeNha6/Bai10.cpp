#include <stdio.h>

// Hàm tính số Fibonacci thứ n
unsigned long long fibonacci(int n) {
    if (n <= 2) {
        return 1;
    }
    unsigned long long a = 1, b = 1, c;
    for (int i = 3; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

// Hàm xuất dãy số Fibonacci thuộc đoạn [m, n]
void fibonacci_in_range(int m, int n) {
    unsigned long long fib;
    int index = 1; // Chỉ số của số Fibonacci bắt đầu từ 1

    while (1) {
        fib = fibonacci(index);
        if (fib > n) break;
        if (fib >= m) {
            printf(" %llu ", fib);
        }
        index++;
    }
    printf("\n");
}

int main() {
    int m, n;
    printf("Nhap m: ");
    scanf_s("%d", &m);
    printf("Nhap n: ");
    scanf_s("%d", &n);
    printf("Day so Fibonacci trong doan la: ");
    if (m <= 0 || n <= 0 || m > n) {
        printf("Gia tri cua m va n phai duong va m phai nho hon n.\n");
        return 1;
    }
    fibonacci_in_range(m, n);
    return 0;
}
