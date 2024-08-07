//#include <stdio.h>
////Phương pháp Đệ Quy Đơn Giản
//// Hàm đệ quy đơn giản để tính giá trị của Y_n
//unsigned long long Y_recursive(int n) {
//    if (n == 1) {
//        return 1; // Giá trị cơ sở
//    }
//    if (n == 2) {
//        return 2; // Giá trị cơ sở
//    }
//    if (n == 3) {
//        return 3; // Giá trị cơ sở
//    }
//    // Đệ quy tính giá trị của Y_n
//    return Y_recursive(n - 1) + 2 * Y_recursive(n - 2) + 3 * Y_recursive(n - 3);
//}
//
//int main() {
//    int n;
//    printf("Nhap n: ");
//    scanf_s("%d", &n);
//
//    if (n < 1) {
//        printf("Gia tri cua n phai la so nguyen duong.\n");
//        return 1;
//    }
//
//    unsigned long long result = Y_recursive(n);
//    printf("Y(%d) = %llu\n", n, result);
//
//    return 0;
//}

//Phương pháp Đệ Quy với Memoization

#include <stdio.h>

#define MAX_N 1000 // Định nghĩa kích thước mảng đủ lớn

// Hàm đệ quy với memoization để tính giá trị của Y_n
unsigned long long Y_memoization(int n, unsigned long long* memo) {
    if (n == 1) {
        return 1; // Giá trị cơ sở
    }
    if (n == 2) {
        return 2; // Giá trị cơ sở
    }
    if (n == 3) {
        return 3; // Giá trị cơ sở
    }

    if (memo[n] != 0) {
        return memo[n]; // Trả về giá trị đã tính nếu đã có
    }

    // Tính giá trị của Y_n và lưu vào mảng memo
    memo[n] = Y_memoization(n - 1, memo) + 2 * Y_memoization(n - 2, memo) + 3 * Y_memoization(n - 3, memo);
    return memo[n];
}

int main() {
    int n;
    printf("Nhap n: ");
    scanf_s("%d", &n);

    if (n < 1) {
        printf("Gia tri cua n phai la so nguyen duong.\n");
        return 1;
    }

    // Khai báo mảng để lưu trữ các giá trị Y
    unsigned long long memo[MAX_N] = { 0 };

    unsigned long long result = Y_memoization(n, memo);
    printf("Y(%d) = %llu\n", n, result);

    return 0;
}
