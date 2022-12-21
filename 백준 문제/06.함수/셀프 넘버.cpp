#include<stdio.h>

int Num(int n)
{
    int b = n;
    while (n != 0)
    {
       b += n % 10;
       n = n / 10;
    }
    return b;
}

int main()
{
    int a[10000];
    int i = 0;  

    for (int n = 1; n <= 10000; n++)
    {
       a[i] = Num(n);
       i++;
    }
  
    for (int n = 1; n <= 10000; n++)
    {
        int num = 0;
        for (int i = 0; i < 10000; i++)
        {
            if (a[i] == n)
            {
                num = 1;
                break;
            }
        }
        if (num == 0)
        {
            printf("%d\n", n);
        }
    }
 
    return 0;
}
