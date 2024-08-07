#include <stdio.h>

// Hàm đệ quy để tính giá trị phần tử thứ n của cấp số nhân
unsigned long long geometric_recursive(int n, unsigned long long a, unsigned long long q) {
    if (n == 1) {
        return a;
    }
    return q * geometric_recursive(n - 1, a, q);
}

int main() {
    int n;
    unsigned long long a, q;

    printf("Nhap gia tri a (hang dau): ");
    scanf_s("%llu", &a);
    printf("Nhap gia tri q (cong boi): ");
    scanf_s("%llu", &q);
    printf("Nhap n (chi so cua phan tu can tinh): ");
    scanf_s("%d", &n);

    if (n < 1) {
        printf("Chi so n phai lon hon hoac bang 1.\n");
        return 1;
    }

    unsigned long long result = geometric_recursive(n, a, q);
    printf("U_%d = %llu\n", n, result);

    return 0;
}
