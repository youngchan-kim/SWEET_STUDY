#include<stdio.h>

void main()
{
	int Num = 10;
	float Fnum = 10.5;
	double Dnum = 10.1;
	char ch = 'a';

	printf("%d + %.2f = %d\n", Num, Fnum, Num + (int)num );
	printf("%.2f + %.2lf = %d\n", Fnum, Dnum, (int)Fnum + (int)Dnum);
	printf("%c + %d = %.2lf\n", ch, Num, ch + (float)Num );
}