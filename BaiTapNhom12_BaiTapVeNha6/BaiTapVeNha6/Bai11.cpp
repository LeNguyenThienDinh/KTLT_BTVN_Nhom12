#include <stdio.h>

//Đệ Quy
// Hàm đệ quy để tìm số Fibonacci lớn nhất nhỏ hơn n
unsigned long long fibonacci_largest_less_than_recursive(unsigned long long n, unsigned long long a, unsigned long long b) {
    unsigned long long c = a + b;
    if (c >= n) {
        return b; // Trả về số Fibonacci lớn nhất nhỏ hơn n
    }
    return fibonacci_largest_less_than_recursive(n, b, c);
}

int main() {
    unsigned long long n;
    printf("Nhap n: ");
    scanf_s("%llu", &n);

    if (n <= 1) {
        printf("Khong co so Fibonacci nho hon %llu\n", n);
        return 1;
    }

    unsigned long long result = fibonacci_largest_less_than_recursive(n, 1, 1);
    printf("So Fibonacci lon nhat nho hon %llu la: %llu\n", n, result);
    return 0;
}

////Khử Đệ Quy
//#include <stdio.h>
//
//// Hàm khử đệ quy để tìm số Fibonacci lớn nhất nhỏ hơn n
//unsigned long long fibonacci_largest_less_than_iterative(unsigned long long n) {
//    if (n <= 1) {
//        return 0; // Không có số Fibonacci nhỏ hơn hoặc bằng 1
//    }
//
//    unsigned long long a = 1, b = 1;
//    unsigned long long c;
//
//    while (1) {
//        c = a + b;
//        if (c >= n) {
//            return b; // Trả về số Fibonacci lớn nhất nhỏ hơn n
//        }
//        a = b;
//        b = c;
//    }
//}
//
//int main() {
//    unsigned long long n;
//    printf("Nhap n: ");
//    scanf_s("%llu", &n);
//
//    unsigned long long result = fibonacci_largest_less_than_iterative(n);
//    printf("So Fibonacci lon nhat nho hon %llu la: %llu\n", n, result);
//    return 0;
//}
