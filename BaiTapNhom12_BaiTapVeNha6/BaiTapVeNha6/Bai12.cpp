#include <stdio.h>

// Hàm đệ quy để tính số hạng thứ n của dãy x và y
void compute_recursive(int n, unsigned long long* x, unsigned long long* y) {
    if (n == 0) {
        *x = 1;
        *y = 0;
        return;
    }

    unsigned long long x_prev, y_prev;
    compute_recursive(n - 1, &x_prev, &y_prev);

    *x = x_prev + y_prev;
    *y = 3 * x_prev + 2 * y_prev;
}

int main() {
    int n;
    unsigned long long x, y;

    printf("Nhap n: ");
    scanf_s("%d", &n);

    if (n < 0) {
        printf("Gia tri cua n phai la so nguyen duong.\n");
        return 1;
    }

    compute_recursive(n, &x, &y);
    printf("x_%d = %llu\n", n, x);
    printf("y_%d = %llu\n", n, y);

    return 0;
}
