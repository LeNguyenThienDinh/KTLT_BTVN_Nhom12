#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//=======================================xu_li_ham================================
void taoMaTranVuong(int **maTran, int n, int thap, int cao)
{
	srand(time(0));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			maTran[i][j] = thap + rand() % (cao - thap + 1);
		}
	}
}

void inMaTranVuong(int **maTran, int n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			printf("%d\t", maTran[i][j]);

		}
		printf("\n");
	}
}
void inDuongCheoChinh(int **maTran, int n)
{
	printf("cac phan tu tren duong cheo chinh la:\n");
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", maTran[i][i]);
	}
	printf("\n");
}

void inDuongCheoSongSong(int **maTran, int n)
{
	printf("cac phan tu thuoc duong cheo song song voi duong cheo chinh la:\n");

	for (int k = 1; k < n; ++k)
	{
		for (int i = 0, j = k; j < n; ++i, ++j)
		{
			printf("%d ", maTran[i][j]);
		}
		printf("\n");
	}

	for (int k = 1; k < n; ++k)
	{
		for (int i = k, j = 0; i < n; ++i, ++j)
		{
			printf("%d ", maTran[i][j]);
		}
		printf("\n");
	}
}
int timMaxTamGiacTren(int **maTran, int n)
{
	int maxVal = maTran[0][0];
	for (int i = 0; i < n; ++i)
	{
		for (int j = i; j < n; ++j)
		{
			if (maTran[i][j] > maxVal)
			{
				maxVal = maTran[i][j];
			}
		}
	}
	return maxVal;
}
void sapXepZicZac(int **maTran, int n)
{
	int *arr = (int *)malloc(n * n * sizeof(int));
	int k = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			arr[k++] = maTran[i][j];
		}
	}

	for (int i = 0; i < n * n - 1; ++i)
	{
		for (int j = i + 1; j < n * n; ++j)
		{
			if (arr[i] > arr[j])
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

	k = 0;
	for (int i = 0; i < n; ++i)
	{
		if (i % 2 == 0)
		{
			for (int j = 0; j < n; ++j)
			{
				maTran[i][j] = arr[k++];
			}
		}
		else
		{
			for (int j = n - 1; j >= 0; --j)
			{
				maTran[i][j] = arr[k++];
			}
		}
	}
	free(arr);
}

void sapXepDuongCheoChinh(int **maTran, int n)
{
	int *arr = (int *)malloc(n * sizeof(int));
	for (int i = 0; i < n; ++i)
	{
		arr[i] = maTran[i][i];
	}

	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			if (arr[i] > arr[j])
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

	for (int i = 0; i < n; ++i)
	{
		maTran[i][i] = arr[i];
	}
	free(arr);
}

void sapXepDuongCheoPhu(int **maTran, int n, int tangDan)
{
	int *arr = (int *)malloc(n * sizeof(int));
	for (int i = 0; i < n; ++i)
	{
		arr[i] = maTran[i][n - i - 1];
	}

	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			if ((tangDan && arr[i] > arr[j]) || (!tangDan && arr[i] < arr[j]))
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

	for (int i = 0; i < n; ++i)
	{
		maTran[i][n - i - 1] = arr[i];
	}
	free(arr);
}

//== == == == == == == == == == == == == xu_li_main == == == == == == == == == == == == == == == ==
int main()
{
	int n, thap, cao, luaChon;
	int **maTran;

	do
	{
		printf("nhap n cho ma tran (n >= 5): ");
		scanf("%d", &n);
		if (n < 5) {
			printf("n cua ma tran phai lon hon hoac bang 5.\n");
		}
	} while (n < 5);

	printf("nhap gioi han duoi: ");
	scanf("%d", &thap);
	printf("nhap gioi han tren: ");
	scanf("%d", &cao);

	if (thap > cao)
	{
		printf("gioi han duoi phai nho hon gioi han tren.\n");
		return 1;
	}
	maTran = (int **)malloc(n * sizeof(int *));
	for (int i = 0; i < n; ++i)
	{
		maTran[i] = (int *)malloc(n * sizeof(int));
	}

	while (1)
	{
		printf("\nMenu:\n");
		printf("1. tao va hien thi ma tran vuong\n");
		printf("2. in duong cheo chinh ma tran vuong\n");
		printf("3. in duong cheo song song cheo chinh ma tran vuong\n");
		printf("4. tim phan tu max thuoc tam giac tren cua duong cheo chinh\n");
		printf("5. sap xep ma tran tang dan theo kieu zic-zac\n");
		printf("6. sap xep duong cheo chinh tang dan tu tren xuong duoi\n");
		printf("7. Sap xep duong cheo phu tang/giam dan\n");
		printf("13. thoat\n");
		printf("nhap lua chon: ");
		scanf("%d", &luaChon);

		switch (luaChon)
		{
		case 1:
			taoMaTranVuong(maTran, n, thap, cao);
			printf("ma tran vuong co n %d:\n", n);
			inMaTranVuong(maTran, n);
			break;
		case 2:
			inDuongCheoChinh(maTran, n);
			break;
		case 3:
			inDuongCheoSongSong(maTran, n);
			break;
		case 4:
			printf("phan tu max thuoc tam giac tren cua duong cheo chinh la: %d\n", timMaxTamGiacTren(maTran, n));
			break;
		case 5:
			sapXepZicZac(maTran, n);
			printf("ma tran sau khi sap xep zic-zac la:\n");
			inMaTranVuong(maTran, n);
			break;
		case 6:
			sapXepDuongCheoChinh(maTran, n);
			printf("ma tran sau khi sap xep duong cheo chinh la:\n");
			inMaTranVuong(maTran, n);
			break;
		case 7:
			sapXepDuongCheoPhu(maTran, n, 1);
			printf("ma tran sau khi sap xep duong cheo phu la:\n");
			inMaTranVuong(maTran, n);
			break;
		default:
			printf("lua chon khong hop le hay nhap lai\n");
		}
	}

	return 0;
}
