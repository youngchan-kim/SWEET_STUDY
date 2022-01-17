//#include<stdio.h>
//
//int main() {
//	int N, a, b, X, i = 0;
//	N = 26;
//	X = N;//26
//	if (X < 10)
//		X * 10;
//	do
//	{
//		a = (X - (X % 10)) / 10;		//6		8
//		b = (X % 10);					//8		4
//		X = a + b;						//14	84	42
//		i++;
//		printf("%d, %d ", X, i);
//		if (X > 10)
//		{
//			a = b * 10;					//80	40		8
//			b = (X % 10);				//4		2		4
//			X = a + b;
//			printf("%d\n", X);
//		}
//		else if (X < 10)
//		{
//			a = b * 10;					//60	
//			X += a;						//8		
//			printf("%d\n", X);
//		}								//68	
//	} while (X != N);
//	return 0;
//}