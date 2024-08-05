#include <stdio.h>

int main() {
    float a, b;
    float* pa, * pb;
    float tong, hieu, tich, thuong;

    printf("Nhap vao hai so thuc a, b: ");
    scanf_s("%f %f", &a, &b);

    pa = &a;
    pb = &b;

    tong = *pa + *pb;
    hieu = *pa - *pb;
    tich = *pa * *pb;

    if (*pb != 0) {
        thuong = *pa / *pb;
    }
    else {
        printf("Khong the chia cho 0.\n");
    }

    printf("Dia chi cua pa: %x\n", pa);
    printf("Dia chi cua pb: %x\n", pb);

    printf("Tong a + b = %.2f, duoc luu tai dia chi: %x\n", tong, (void*)&tong);
    printf("Hieu a - b = %.2f, duoc luu tai dia chi: %x\n", hieu, (void*)&hieu);
    printf("Tich a * b = %.2f, duoc luu tai dia chi: %x\n", tich, (void*)&tich);
    printf("Thuong a / b = %.2f, duoc luu tai dia chi: %x\n", thuong, (void*)&thuong);

    return 0;
}