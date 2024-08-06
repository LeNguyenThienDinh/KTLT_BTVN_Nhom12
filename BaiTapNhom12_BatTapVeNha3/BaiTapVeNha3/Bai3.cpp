#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    char hoTen[50];
    char soDienThoai[15];
    int soVeNguoiLon;
    int soVeTreEm;
    char tenPhim[50];
    char phongChieu[10];
    char xuatChieu[10];
    int tienPhaiTra;
} KhachHang;

void docDanhSachKhachHang(KhachHang dskh[], int* n, const char* filename);
void xuatDanhSachKhachHang(KhachHang dskh[], int n);
void tinhTienKhachHang(KhachHang* kh);
void tinhTienTatCaKhachHang(KhachHang dskh[], int n);
int tinhTongDoanhThu(KhachHang dskh[], int n);
void tinhDoanhThuTungPhim(KhachHang dskh[], int n);
void xuatKhachHangTheoPhongVaXuat(KhachHang dskh[], int n, char* phong, char* xuat);
void sapXepTheoTienPhaiTra(KhachHang dskh[], int n);
void sapXepTheoTienPhaiTraBubbleSort(KhachHang dskh[], int n);
void sapXepTheoTienPhaiTraInsertionSort(KhachHang dskh[], int n);
void sapXepTheoTienPhaiTraSelectionSort(KhachHang dskh[], int n);
void sapXepTheoHoTen(KhachHang dskh[], int n);
int binarySearch(KhachHang dskh[], int n, char* hoTen);

int main() {
    KhachHang dskh[MAX];
    int n;

    docDanhSachKhachHang(dskh, &n, "danhsachkhachhang.txt");
    xuatDanhSachKhachHang(dskh, n);

    tinhTienTatCaKhachHang(dskh, n);
    printf("\nDanh sách khách hàng sau khi tính tiền:\n");
    xuatDanhSachKhachHang(dskh, n);

    int tongDoanhThu = tinhTongDoanhThu(dskh, n);
    printf("\nTổng doanh thu của rạp phim: %d\n", tongDoanhThu);

    printf("\nDoanh thu của từng phim:\n");
    tinhDoanhThuTungPhim(dskh, n);

    char phong[10], xuat[10];
    printf("\nNhập phòng chiếu: ");
    scanf_s("%s", phong);
    printf("Nhập xuất chiếu: ");
    scanf_s("%s", xuat);
    xuatKhachHangTheoPhongVaXuat(dskh, n, phong, xuat);

    sapXepTheoTienPhaiTraBubbleSort(dskh, n);
    printf("\nDanh sách khách hàng sau khi sắp xếp theo tiền phải trả tăng dần (Bubble Sort):\n");
    xuatDanhSachKhachHang(dskh, n);

    sapXepTheoHoTen(dskh, n);
    printf("\nDanh sách khách hàng sau khi sắp xếp theo họ tên tăng dần:\n");
    xuatDanhSachKhachHang(dskh, n);

    char tenCanTim[50] = "Nguyen Van An";
    int viTri = binarySearch(dskh, n, tenCanTim);
    if (viTri != -1) {
        printf("\nTìm thấy khách hàng có họ tên \"%s\" tại vị trí %d\n", tenCanTim, viTri);
    }
    else {
        printf("\nKhông tìm thấy khách hàng có họ tên \"%s\"\n", tenCanTim);
    }

    return 0;
}

void docDanhSachKhachHang(KhachHang dskh[], int* n, const char* filename) {
    FILE* file;
    if (fopen_s(&file, filename, "r") != 0) {
        printf("Không thể mở file %s\n", filename);
        exit(1);
    }
    fscanf_s(file, "%d", n);
    for (int i = 0; i < *n; i++) {
        fscanf_s(file, " %[^\n]", dskh[i].hoTen);
        fscanf_s(file, " %s", dskh[i].soDienThoai);
        fscanf_s(file, "%d", &dskh[i].soVeNguoiLon);
        fscanf_s(file, "%d", &dskh[i].soVeTreEm);
        fscanf_s(file, " %[^\n]", dskh[i].tenPhim);
        fscanf_s(file, " %s", dskh[i].phongChieu);
        fscanf_s(file, " %s", dskh[i].xuatChieu);
    }
    fclose(file);
}

void xuatDanhSachKhachHang(KhachHang dskh[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Họ tên: %s\n", dskh[i].hoTen);
        printf("Số điện thoại: %s\n", dskh[i].soDienThoai);
        printf("Số vé người lớn: %d\n", dskh[i].soVeNguoiLon);
        printf("Số vé trẻ em: %d\n", dskh[i].soVeTreEm);
        printf("Tên phim: %s\n", dskh[i].tenPhim);
        printf("Phòng chiếu: %s\n", dskh[i].phongChieu);
        printf("Xuất chiếu: %s\n", dskh[i].xuatChieu);
        printf("Tiền phải trả: %d\n", dskh[i].tienPhaiTra);
        printf("-------------------------------\n");
    }
}

void tinhTienKhachHang(KhachHang* kh) {
    kh->tienPhaiTra = kh->soVeNguoiLon * 40000 + kh->soVeTreEm * 20000;
}

void tinhTienTatCaKhachHang(KhachHang dskh[], int n) {
    for (int i = 0; i < n; i++) {
        tinhTienKhachHang(&dskh[i]);
    }
}

int tinhTongDoanhThu(KhachHang dskh[], int n) {
    int tongDoanhThu = 0;
    for (int i = 0; i < n; i++) {
        tongDoanhThu += dskh[i].tienPhaiTra;
    }
    return tongDoanhThu;
}

void tinhDoanhThuTungPhim(KhachHang dskh[], int n) {
    int doanhThuPhim[MAX] = { 0 };
    char tenPhim[MAX][50];
    int phimCount = 0;

    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < phimCount; j++) {
            if (strcmp(tenPhim[j], dskh[i].tenPhim) == 0) {
                doanhThuPhim[j] += dskh[i].tienPhaiTra;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy_s(tenPhim[phimCount], dskh[i].tenPhim);
            doanhThuPhim[phimCount] += dskh[i].tienPhaiTra;
            phimCount++;
        }
    }

    for (int i = 0; i < phimCount; i++) {
        printf("Phim %s: %d VND\n", tenPhim[i], doanhThuPhim[i]);
    }
}

void xuatKhachHangTheoPhongVaXuat(KhachHang dskh[], int n, char* phong, char* xuat) {
    printf("\nDanh sách khách hàng đặt vé ở phòng chiếu %s và xuất chiếu %s:\n", phong, xuat);
    for (int i = 0; i < n; i++) {
        if (strcmp(dskh[i].phongChieu, phong) == 0 && strcmp(dskh[i].xuatChieu, xuat) == 0) {
            printf("Họ tên: %s\n", dskh[i].hoTen);
            printf("Số điện thoại: %s\n", dskh[i].soDienThoai);
            printf("Số vé người lớn: %d\n", dskh[i].soVeNguoiLon);
            printf("Số vé trẻ em: %d\n", dskh[i].soVeTreEm);
            printf("Tên phim: %s\n", dskh[i].tenPhim);
            printf("Phòng chiếu: %s\n", dskh[i].phongChieu);
            printf("Xuất chiếu: %s\n", dskh[i].xuatChieu);
            printf("Tiền phải trả: %d\n", dskh[i].tienPhaiTra);
            printf("-------------------------------\n");
        }
    }
}

void sapXepTheoTienPhaiTraBubbleSort(KhachHang dskh[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (dskh[j].tienPhaiTra > dskh[j + 1].tienPhaiTra) {
                KhachHang temp = dskh[j];
                dskh[j] = dskh[j + 1];
                dskh[j + 1] = temp;
            }
        }
    }
}

void sapXepTheoTienPhaiTraInsertionSort(KhachHang dskh[], int n) {
    for (int i = 1; i < n; i++) {
        KhachHang key = dskh[i];
        int j = i - 1;
        while (j >= 0 && dskh[j].tienPhaiTra > key.tienPhaiTra) {
            dskh[j + 1] = dskh[j];
            j--;
        }
        dskh[j + 1] = key;
    }
}

void sapXepTheoTienPhaiTraSelectionSort(KhachHang dskh[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (dskh[j].tienPhaiTra < dskh[minIdx].tienPhaiTra) {
                minIdx = j;
            }
        }
        KhachHang temp = dskh[minIdx];
        dskh[minIdx] = dskh[i];
        dskh[i] = temp;
    }
}

void sapXepTheoHoTen(KhachHang dskh[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (strcmp(dskh[j].hoTen, dskh[j + 1].hoTen) > 0) {
                KhachHang temp = dskh[j];
                dskh[j] = dskh[j + 1];
                dskh[j + 1] = temp;
            }
        }
    }
}

int binarySearch(KhachHang dskh[], int n, char* hoTen) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        int cmp = strcmp(dskh[mid].hoTen, hoTen);
        if (cmp == 0) {
            return mid;
        }
        else if (cmp < 0) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;
}
