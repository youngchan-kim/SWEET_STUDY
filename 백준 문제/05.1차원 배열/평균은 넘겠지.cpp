#include<stdio.h>

int main()
{
	int case_c, student_n, sum, count;
	int student_score[1000];
	double avg;
	scanf("%d", &case_c);

	for (int i = 0; i < case_c; i++)
	{
		sum = 0, count = 0;


		scanf("%d", &student_n);
		for (int j = 0; j < student_n; j++)
		{
			scanf("%d", &student_score[j]);

			sum += student_score[j];
		}
		avg = sum / student_n;

		for (int k = 0; k < student_n; k++)
		{
			if (avg < student_score[k])
			{
				count++;
			}
		}
		printf("%.3f%%\n", (float)count / student_n * 100);
	}
	return 0;
}