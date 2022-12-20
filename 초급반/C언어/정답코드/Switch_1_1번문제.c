#include<stdio.h>
#include<Windows.h>//system("cls"),system("pause")

void main()
{
	int Select, Kor, Math, Eng, Sum;
	float Avg;
	char Name[20];
	int Flag = 0, Check = 0;


	while (1)
	{
		system("cls");
		printf("===================\n");
		printf("    학생성적관리    \n");
		printf("===================\n");
		printf("  1.학생 이름 등록\n");
		printf("  2.3과목 점수등록\n");
		printf("  3.점수확인\n");
		printf("  4.종료\n");
		printf("===================\n");
		printf("입력 : ");
		scanf("%d", &Select);

		switch (Select)
		{
			case 1:
				system("cls");
				printf("이름 입력 : ");
				scanf("%s", Name);
				Flag = 1;
				break;

			case 2:
				system("cls");
				printf("세과목의 성적을 입력하시오\n");
				printf("국어 : ");
				scanf("%d\n", &Kor);
				printf("수학 : ");
				scanf("%d\n", &Math);
				printf("영어 : ");
				scanf("%d\n", &Eng);
				Sum = Kor + Math + Eng;
				Avg = (float)Sum / 3;
				Check = 1;
				break;


			case 3:
				system("cls");
				if (Flag == 0 && Check == 0) 
					printf("이름을 입력하세요.\n점수를 입력하세요.\n");

				else if(Flag == 0 && Check == 1)
					printf("이름을 입력하세요.\n");

				else if(Flag == 1 && Check == 0)
					printf("점수를 입력하세요.\n");

				else if (Flag == 1 && Check == 1)
				{
					printf("====================\n");
					printf("%s님의 점수\n국어 점수 : %d \n수학 점수 : %d \n영어 점수 %d \n합계 점수 %d \n평균 점수 %.2f\n", Name, Kor, Math, Eng, Sum, Avg);
					printf("====================\n");
				}
				system("pause");
				break;


			case 4:
				return;
		}
	}
}