#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

void main_map();   //----메인맵으로 메인함수와 바로 연결되있는 함수
void mini_map(); //----키값받아서 화면 전환함수
void random();     //----난수 받는 함수
void reset();      //----바뀐값 0으로 초기화 함수

void up();      //----윗면
void right();   //----오른쪽면
void left();    //----왼쪽면
void behind();  //----뒷면
void front();   //----정면
void print();   //----위의 면들 출력하는 함수 

void snow_move();   //눈 내리는 함수
void stay_y();     // 눈이 바닥에 다으면 다시 위에서 내려오게하기

int map[10][10][10] = { 0 };  //맵
int c1, second_1, second_2;    //시간 설정변수
int y_1, y_2, y_3, y_4, y_5, y_6;  // 눈 내린 후 자리
int i, j, k, m, a, b, b_1;   //for문에 들어갈 변수 선언 m은 면호출하기위함
int x, y, x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6;   //눈위치변수
int again_1, again_2, key;   // count_1~3은 키값 세주는 변수, key는 키값 받는 변수

void main()
{
	srand(time(NULL));
	main_map();
	system("cls");
	printf("\n  [ΜΕＲΥ ＣΗＲΙＳΤΜΑＳ♩♬♪]");
	printf("\n        [X-mas]  - END - \n");
}

void main_map()
{
	again_1 = 1;
	while (again_1 > 0)
	{
		m = 0;
		random(); //----랜덤으로 위치지정
		printf("몇초동안 눈이 내렸으면 하나요? : ");
		scanf_s(" %d", &second_1);
		printf("몇초간격으로 내릴까요?\t(Sleep단위 → 100 = 0.1초) : ");
		scanf_s(" %d", &second_2);
		system("cls");
		snow_move();  //----눈내림
		again_2 = 1;
		while (again_2 > 0) mini_map(); //----키값받아 면 전환
	}

}

void random()  //----눈 위치 랜덤생성
{
	x1 = rand() % 10;
	y1 = rand() % 10;
	x2 = rand() % 10;
	y2 = rand() % 10;
	x3 = rand() % 10;
	y3 = rand() % 10;
	x4 = rand() % 10;
	y4 = rand() % 10;
	x5 = rand() % 10;
	y5 = rand() % 10;
	x6 = rand() % 10;
	y6 = rand() % 10;
}

void mini_map()
{
	printf("\n              ☜ 왼쪽   오른쪽 ☞\n");
	printf(" \n처음화면 : [Space bar] \t 종    료 : [소문자 x]\n");
	key = getch();
	system("cls");
	if (key == 77)   m++;
	if (key == 75)   m--;
	if (m == -4 || m == 4)m = 0;
	if (m == 0) front();            //-----정면:m = 0
	if (m == 1 || m == -3) right(); //-----오른쪽면:m = 1 또는 m = -3
	if (m == 2 || m == -2) behind();//-----뒷면:m = 2 또는 m = -2
	if (m == 3 || m == -1) left();  //-----왼쪽면:m = -1 또는 m = 3
	if (key == 32)
	{
		system("cls");
		again_2 = 0;
	}
	if (key == 'x')
	{
		again_1 = 0;
		again_2 = 0;
	}
}

void snow_move() //----눈 내리는 함수
{
	c1 = (second_1 * 1000) / second_2;
	stay_y();  //y_1~6에 9값 넣어주는 함수
	while (c1 > 0)   
	{
		system("cls");
		front();
		map[y_1][9][x1] = 0;
		map[y_2][9][x2] = 0;
		map[y_3][9][x3] = 0;
		map[y_4][9][x4] = 0;
		map[y_5][9][x5] = 0;
		map[y_6][9][x6] = 0;
		y_1--;
		y_2--;
		y_3--;
		y_4--;
		y_5--;
		y_6--;
		if (y_1 == -1) stay_y();
		printf("%d번남음", c1);
		c1--;
		Sleep(second_2);
	}
	system("cls");
	front();
}

void stay_y()  //y_1~6이 0이 되었을때 눈이 다시 내릴 수 있도록
{
	y_1 = 9;
	y_2 = 9;
	y_3 = 9;
	y_4 = 9;
	y_5 = 9;
	y_6 = 9;
}

void reset()    // 눈 자국 없애기
{
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			for (k = 0; k < 10; k++) map[i][j][k] = 0;
		}
	}
}

void up()   //----윗면
{
	for (j = 0; j < 10; j++)
	{
		for (k = 0; k < 10; k++)
		{
			map[9][y1][x1] = 1;
			map[9][y2][x2] = 1;
			map[9][y3][x3] = 1;
			map[9][y4][x4] = 1;
			map[9][y5][x5] = 1;
			map[9][y6][x6] = 1;
			if (map[9][j][k] == 0)
			{
				printf("■");
			}
			if (map[9][j][k] == 1)
			{
				printf("※");
			}
		}   printf("\n");
	}   reset();
	printf(" [윗면 입니다] \n\n");
}

void right() //---오른쪽면
{
	up();
	b = 1;
	for (i = 9; i >= 0; i--)   
	{
		for (j = 9; j >= 0; j--)
		{
			print();
			if (map[i][j][9] == 0)
			{
				printf("■");
			}
			if (map[i][j][9] == 1)
			{
				printf("♬");
			}
		}   printf("\n");
	}   reset();
	printf("[오른쪽면 입니다]\n");
}

void behind() //--------뒷면
{
	up();
	b = 2;
	for (i = 9; i >= 0; i--)  
	{
		for (k = 9; k >= 0; k--)
		{
			print();
			if (map[i][0][k] == 0)
			{
				printf("■");
			}
			if (map[i][0][k] == 1)
			{
				printf("Ξ");
			}
		}   printf("\n");
	}   reset();
	printf("[뒷면 입니다]\n");
}

void left()//--------왼쪽면
{
	up();
	b = 3;
	for (i = 9; i >= 0; i--)   
	{
		for (j = 0; j < 10; j++)
		{
			print();
			if (map[i][j][0] == 0)
			{
				printf("■");
			}
			if (map[i][j][0] == 1)
			{
				printf("Θ");
			}
		} printf("\n");
	}   reset();
	printf("[왼쪽면 입니다]\n");
}

void front()  //----정면
{
	up();
	b = 4;
	for (i = 9 ; i >= 0; i--)
	{
		for (k = 0; k < 10; k++)
		{
			print();
			if (map[i][9][k] == 0)
			{
				printf("■");
			}
			if (map[i][9][k] == 1)
			{
				printf("ω");
			}
		}   printf("\n");
	}   reset();
	printf("[정면 입니다]\n");
}

void print()  //-------위의 면들을 출력할때 눈 위치값
{
	if (b == 2 || b == 4)
	{
		if (b == 2)b_1 = 0;
		if (b == 4)b_1 = 9;
		map[y_1][b_1][x1] = 1;
		map[y_2][b_1][x2] = 1;
		map[y_3][b_1][x3] = 1;
		map[y_4][b_1][x4] = 1;
		map[y_5][b_1][x5] = 1;
		map[y_6][b_1][x6] = 1;
	}
	if (b == 1 || b == 3)
	{
		if (b == 1)b_1 = 9;
		if (b == 3)b_1 = 0;
		map[y_1][y1][b_1] = 1;
		map[y_2][y2][b_1] = 1;
		map[y_3][y3][b_1] = 1;
		map[y_4][y4][b_1] = 1;
		map[y_5][y5][b_1] = 1;
		map[y_6][y6][b_1] = 1;
	}
}