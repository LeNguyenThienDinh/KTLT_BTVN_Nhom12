#include <stdio.h>

double S1(int n) {
    double sum = 0.0;
    for (int i = 1; i <= n; i++) {
        sum += 1.0 / (i * (i + 1) * (i + 2));
    }
    return sum;
}

int S2(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i * i;
    }
    return sum;
}

int S3(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i * (i + 1) / 2;
    }
    return sum;
}


int main() {
    int n;
    printf("Nhap n: ");
    scanf_s("%d", &n);
    printf("S1(%d) = 1/(1*2*3) + 1/(2*3*4) + ... + 1/(%d*(%d+1)*(%d+2)) = %lf\n", n, n, n, n, S1(n));
    printf("S2(%d) = 1^2 + 2^2 + ... + %d^2 = %d\n", n, n, S2(n));
    printf("S3(%d) = 1 + (1+2) + (1+2+3) + ... + (1+2+3+...+%d) = %d\n", n, n, S3(n));

    return 0;
}
