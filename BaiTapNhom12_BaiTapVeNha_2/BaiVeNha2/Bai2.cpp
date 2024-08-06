#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int phan_nguyen;
    int tu_so;
    int mau_so;
} HonSo;

void taoMangNgauNhien(HonSo b[], int n);
void xuatDanhSachHonSo(HonSo b[], int n);
int linearSearch(HonSo b[], int n, HonSo x);
void sapXepChanLe(HonSo b[], int n);
int binarySearch(HonSo b[], int left, int right, HonSo x);
void chiaMang(HonSo b[], int n, int s1[], HonSo s2[]);
void xoaPhanTu(HonSo b[], int* n, int k);
void themHonSo(HonSo b[], int* n, HonSo x, int k);
void taoMangPhanSo(HonSo b[], int n, float c[]);
HonSo tongHonSo(HonSo b[], int n);
HonSo timMax(HonSo b[], int n);
HonSo timMin(HonSo b[], int n);
void xuatViTriChan(HonSo b[], int n);
void xuatViTriMaxMin(HonSo b[], int n);

int main() {
    srand(time(0));
    int n = 10;
    HonSo b[100];
    taoMangNgauNhien(b, n);
    printf("Danh sach hon so ngau nhien:\n");
    xuatDanhSachHonSo(b, n);

    HonSo x = { 2, 1, 3 };
    int idx = linearSearch(b, n, x);
    if (idx != -1) {
        printf("Tim thay hon so x tai vi tri %d\n", idx);
    }
    else {
        printf("Khong tim thay hon so x\n");
    }

    sapXepChanLe(b, n);
    printf("Danh sach sau khi sap xep chan le:\n");
    xuatDanhSachHonSo(b, n);

    idx = binarySearch(b, 0, n - 1, x);
    if (idx != -1) {
        printf("Tim thay hon so x tai vi tri %d (binary search)\n", idx);
    }
    else {
        printf("Khong tim thay hon so x (binary search)\n");
    }

    int s1[100];
    HonSo s2[100];
    chiaMang(b, n, s1, s2);

    xoaPhanTu(b, &n, 3);
    printf("Danh sach sau khi xoa phan tu thu 3:\n");
    xuatDanhSachHonSo(b, n);

    themHonSo(b, &n, x, 3);
    printf("Danh sach sau khi them hon so tai vi tri 3:\n");
    xuatDanhSachHonSo(b, n);

    float c[100];
    taoMangPhanSo(b, n, c);

    HonSo tong = tongHonSo(b, n);
    printf("Tong cac hon so: %d %d/%d\n", tong.phan_nguyen, tong.tu_so, tong.mau_so);

    HonSo max = timMax(b, n);
    printf("Hon so lon nhat: %d %d/%d\n", max.phan_nguyen, max.tu_so, max.mau_so);

    HonSo min = timMin(b, n);
    printf("Hon so nho nhat: %d %d/%d\n", min.phan_nguyen, min.tu_so, min.mau_so);

    xuatViTriChan(b, n);
    xuatViTriMaxMin(b, n);

    return 0;
}
void taoMangNgauNhien(HonSo b[], int n) {
    for (int i = 0; i < n; i++) {
        b[i].phan_nguyen = rand() % 10;
        b[i].tu_so = rand() % 10;
        b[i].mau_so = rand() % 9 + 1; // Mau so khac 0
    }
}

void xuatDanhSachHonSo(HonSo b[], int n) {
    for (int i = 0; i < n; i++) {
        printf("\n%d %d/%d ", b[i].phan_nguyen, b[i].tu_so, b[i].mau_so);
    }
    printf("\n");
}
//1. Tìm hỗn số x trong mảng b theo giải thuật Linear Search.
int linearSearch(HonSo b[], int n, HonSo x) {
    for (int i = 0; i < n; i++) {
        if (b[i].phan_nguyen == x.phan_nguyen && b[i].tu_so == x.tu_so && b[i].mau_so == x.mau_so) {
            return i;
        }
    }
    return -1;
}
//2. Sắp xếp b sao cho các phần tử có phần nguyên chẵn lên đầu, phần tử có phần nguyên lẻ ở cuối mảng.
void sapXepChanLe(HonSo b[], int n) {
    int left = 0, right = n - 1;
    while (left < right) {
        while (left < n && b[left].phan_nguyen % 2 == 0) {
            left++;
        }
        while (right >= 0 && b[right].phan_nguyen % 2 != 0) {
            right--;
        }
        if (left < right) {
            HonSo temp = b[left];
            b[left] = b[right];
            b[right] = temp;
        }
    }
}
//3. Tìm hỗn số x theo giải thuật binary search trong mảng b đã được sắp xếp tang/giảm. 
int binarySearch(HonSo b[], int left, int right, HonSo x) {
    if (right >= left) {
        int mid = left + (right - left) / 2;
        if (b[mid].phan_nguyen == x.phan_nguyen && b[mid].tu_so == x.tu_so && b[mid].mau_so == x.mau_so) {
            return mid;
        }
        if (b[mid].phan_nguyen < x.phan_nguyen || (b[mid].phan_nguyen == x.phan_nguyen && b[mid].tu_so < x.tu_so)) {
            return binarySearch(b, mid + 1, right, x);
        }
        return binarySearch(b, left, mid - 1, x);
    }
    return -1;
}
//4. Chia mảng b thành 2 mảng s1 và s2, với s1 chứa các phần nguyên, s2 chứa phân số.
void chiaMang(HonSo b[], int n, int s1[], HonSo s2[]) {
    for (int i = 0; i < n; i++) {
        s1[i] = b[i].phan_nguyen;
        s2[i].phan_nguyen = 0;
        s2[i].tu_so = b[i].tu_so;
        s2[i].mau_so = b[i].mau_so;
    }
}
//5. Xóa phần tử thứ k trong mảng b. 
void xoaPhanTu(HonSo b[], int* n, int k) {
    if (k < 0 || k >= *n) return;
    for (int i = k; i < *n - 1; i++) {
        b[i] = b[i + 1];
    }
    (*n)--;
}
//6. Thêm hỗn số x vào mảng b tại vị trí k. 
void themHonSo(HonSo b[], int* n, HonSo x, int k) {
    if (k < 0 || k > *n) return;
    for (int i = *n; i > k; i--) {
        b[i] = b[i - 1];
    }
    b[k] = x;
    (*n)++;
}
//7. Tạo mảng c chứa các phần tử là phân số được đổi từ các phần tử hỗn số của mảng b.
void taoMangPhanSo(HonSo b[], int n, float c[]) {
    for (int i = 0; i < n; i++) {
        c[i] = (float)b[i].tu_so / b[i].mau_so;
    }
}
//8. Tính tổng các phần tử của mảng b. 
HonSo tongHonSo(HonSo b[], int n) {
    HonSo tong = { 0, 0, 1 };
    for (int i = 0; i < n; i++) {
        tong.phan_nguyen += b[i].phan_nguyen;
        tong.tu_so = tong.tu_so * b[i].mau_so + b[i].tu_so * tong.mau_so;
        tong.mau_so *= b[i].mau_so;
    }
    return tong;
}
//9. Tìm phần tử lớn nhất/nhỏ nhất của b. 
HonSo timMax(HonSo b[], int n) {
    HonSo max = b[0];
    for (int i = 1; i < n; i++) {
        if (b[i].phan_nguyen > max.phan_nguyen || (b[i].phan_nguyen == max.phan_nguyen && b[i].tu_so > max.tu_so)) {
            max = b[i];
        }
    }
    return max;
}
 
HonSo timMin(HonSo b[], int n) {
    HonSo min = b[0];
    for (int i = 1; i < n; i++) {
        if (b[i].phan_nguyen < min.phan_nguyen || (b[i].phan_nguyen == min.phan_nguyen && b[i].tu_so < min.tu_so)) {
            min = b[i];
        }
    }
    return min;
}
//10. Xuất vị trí phần tử có phần nguyên chẵn của b.
void xuatViTriChan(HonSo b[], int n) {
    printf("Vi tri cac hon so co phan nguyen chan:\n");
    for (int i = 0; i < n; i++) {
        if (b[i].phan_nguyen % 2 == 0) {
            printf("%d ", i);
        }
    }
    printf("\n");
}