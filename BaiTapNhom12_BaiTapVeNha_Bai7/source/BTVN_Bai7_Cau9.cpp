#include <stdio.h>
#include <conio.h>

double S1(int n) 
{
	double sum = 0.0;
	for (int i = 1; i <= n; ++i) 
	{
		sum += 1.0 / (i * (i + 1) * (i + 2));
	}
	return sum;
}

int S2(int n) 
{
	int sum = 0;
	for (int i = 1; i <= n; ++i)
	{
		sum += i * i;
	}
	return sum;
}

int sumRecursive(int n) 
{
	if (n == 1) return 1;
	return n + sumRecursive(n - 1);
}

int S3(int n) 
{
	if (n == 1) return 1;
	return sumRecursive(n) + S3(n - 1);
}

int S3_nonRecursive(int n)
{
	int sum = 0;
	for (int i = 1; i <= n; ++i)
	{
		sum += i * (i + 1) / 2;
	}
	return sum;
}


long long factorial(int n) 
{
	if (n == 0 || n == 1) return 1;
	return n * factorial(n - 1);
}

double S4(int n) 
{
	double sum = 0.0;
	for (int i = 1; i <= n; ++i) 
	{
		double term = ((2 * i - 1) + 2 * i) / (double)factorial(2 * i);
		if (i % 2 == 0) 
		{
			term = -term;
		}
		sum += term;
	}
	return sum;
}

int main() {
	int n;
	printf("Nhap so nguyen duong n: ");
	scanf("%d", &n);

	printf("S1(n) = %lf\n", S1(n));
	printf("S2(n) = %d\n", S2(n));
	printf("S3(n) theo de quy = %d\n", S3(n));
	printf("S3(n) theo khu de quy = %d\n", S3_nonRecursive(n));
	printf("S4(n) = %lf\n", S4(n));
	return 0;
}
