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