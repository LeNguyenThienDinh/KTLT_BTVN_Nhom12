#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#pragma warning(disable:4996)

void nhapChuoi(char* st) {
    printf("Nhap chuoi: ");
    fgets(st, 100, stdin);
    st[strcspn(st, "\n")] = '\0';  
}

void kiemTraBoNho(char* st) {
    if (st == NULL) {
        printf("Cap phat bo nho that bai\n");
        exit(1); 
    }
}

void xuatChuoiConTro(const char* st) {
    while (*st != '\0') {
        printf("%c", *st);
        st++;
    }
    printf("\n");
}

void giaiPhongBoNho(char* st) {
    free(st);
    st = NULL;
}
void chuyenChuoiInHoa(char* st) {
    for (int i = 0; st[i] != '\0'; i++) {
        if (st[i] >= 'a' && st[i] <= 'z') {
            st[i] = st[i] - ('a' - 'A');
        }
    }

    printf("\nb. Chuoi sau khi chuyen thanh chu hoa: ");
    xuatChuoiConTro(st);
}

void bai10() {
    char* st = (char*)malloc(100 * sizeof(char));
    kiemTraBoNho(st);

    nhapChuoi(st);

    printf("a. Gia tri tung ky tu cua chuoi: ");
    xuatChuoiConTro(st);

    // Sao lưu chuỗi ban đầu
    char* originalSt = (char*)malloc(100 * sizeof(char));
    kiemTraBoNho(originalSt);
    strcpy(originalSt, st);

    chuyenChuoiInHoa(st);

    // Khôi phục chuỗi gốc từ bản sao lưu
    strcpy(st, originalSt);

    chuyenKyTuInHoaSauKhoangTrang(st);

    giaiPhongBoNho(originalSt);
    giaiPhongBoNho(st);
}

int main() {
    bai10();
    return 0;
}