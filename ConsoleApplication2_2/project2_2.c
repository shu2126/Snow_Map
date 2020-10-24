#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

void main_map();   //----���θ����� �����Լ��� �ٷ� ������ִ� �Լ�
void mini_map(); //----Ű���޾Ƽ� ȭ�� ��ȯ�Լ�
void random();     //----���� �޴� �Լ�
void reset();      //----�ٲﰪ 0���� �ʱ�ȭ �Լ�

void up();      //----����
void right();   //----�����ʸ�
void left();    //----���ʸ�
void behind();  //----�޸�
void front();   //----����
void print();   //----���� ��� ����ϴ� �Լ� 

void snow_move();   //�� ������ �Լ�
void stay_y();     // ���� �ٴڿ� ������ �ٽ� ������ ���������ϱ�

int map[10][10][10] = { 0 };  //��
int c1, second_1, second_2;    //�ð� ��������
int y_1, y_2, y_3, y_4, y_5, y_6;  // �� ���� �� �ڸ�
int i, j, k, m, a, b, b_1;   //for���� �� ���� ���� m�� ��ȣ���ϱ�����
int x, y, x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6;   //����ġ����
int again_1, again_2, key;   // count_1~3�� Ű�� ���ִ� ����, key�� Ű�� �޴� ����

void main()
{
	srand(time(NULL));
	main_map();
	system("cls");
	printf("\n  [�̥ţҥ� �åǣҥɣӥӥ̥��Ӣۢݢ�]");
	printf("\n        [X-mas]  - END - \n");
}

void main_map()
{
	again_1 = 1;
	while (again_1 > 0)
	{
		m = 0;
		random(); //----�������� ��ġ����
		printf("���ʵ��� ���� �������� �ϳ���? : ");
		scanf_s(" %d", &second_1);
		printf("���ʰ������� �������?\t(Sleep���� �� 100 = 0.1��) : ");
		scanf_s(" %d", &second_2);
		system("cls");
		snow_move();  //----������
		again_2 = 1;
		while (again_2 > 0) mini_map(); //----Ű���޾� �� ��ȯ
	}

}

void random()  //----�� ��ġ ��������
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
	printf("\n              �� ����   ������ ��\n");
	printf(" \nó��ȭ�� : [Space bar] \t ��    �� : [�ҹ��� x]\n");
	key = getch();
	system("cls");
	if (key == 77)   m++;
	if (key == 75)   m--;
	if (m == -4 || m == 4)m = 0;
	if (m == 0) front();            //-----����:m = 0
	if (m == 1 || m == -3) right(); //-----�����ʸ�:m = 1 �Ǵ� m = -3
	if (m == 2 || m == -2) behind();//-----�޸�:m = 2 �Ǵ� m = -2
	if (m == 3 || m == -1) left();  //-----���ʸ�:m = -1 �Ǵ� m = 3
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

void snow_move() //----�� ������ �Լ�
{
	c1 = (second_1 * 1000) / second_2;
	stay_y();  //y_1~6�� 9�� �־��ִ� �Լ�
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
		printf("%d������", c1);
		c1--;
		Sleep(second_2);
	}
	system("cls");
	front();
}

void stay_y()  //y_1~6�� 0�� �Ǿ����� ���� �ٽ� ���� �� �ֵ���
{
	y_1 = 9;
	y_2 = 9;
	y_3 = 9;
	y_4 = 9;
	y_5 = 9;
	y_6 = 9;
}

void reset()    // �� �ڱ� ���ֱ�
{
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			for (k = 0; k < 10; k++) map[i][j][k] = 0;
		}
	}
}

void up()   //----����
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
				printf("��");
			}
			if (map[9][j][k] == 1)
			{
				printf("��");
			}
		}   printf("\n");
	}   reset();
	printf(" [���� �Դϴ�] \n\n");
}

void right() //---�����ʸ�
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
				printf("��");
			}
			if (map[i][j][9] == 1)
			{
				printf("��");
			}
		}   printf("\n");
	}   reset();
	printf("[�����ʸ� �Դϴ�]\n");
}

void behind() //--------�޸�
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
				printf("��");
			}
			if (map[i][0][k] == 1)
			{
				printf("��");
			}
		}   printf("\n");
	}   reset();
	printf("[�޸� �Դϴ�]\n");
}

void left()//--------���ʸ�
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
				printf("��");
			}
			if (map[i][j][0] == 1)
			{
				printf("��");
			}
		} printf("\n");
	}   reset();
	printf("[���ʸ� �Դϴ�]\n");
}

void front()  //----����
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
				printf("��");
			}
			if (map[i][9][k] == 1)
			{
				printf("��");
			}
		}   printf("\n");
	}   reset();
	printf("[���� �Դϴ�]\n");
}

void print()  //-------���� ����� ����Ҷ� �� ��ġ��
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