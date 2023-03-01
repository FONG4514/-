#include<graphics.h>
#include<iostream>
#include<conio.h>
#include <cstdlib>
#include <ctime>
#include"snake.h"
using namespace std;

int main()
{
	IMAGE img;
	loadimage(&img,_T("E:\\big silly b\\snake\\snack.jpg"));
	init();
	initfood();
	wall_coor();
	draw_snack();
	cleardevice();
	while (1)
	{
		BeginBatchDraw();
		Sleep(50);
		move_snack2();
		move_snack1();
		eatfood();
		eatself();
		hitwall();
		Sleep(1);
		cleardevice();
		putimage(0, 0, &img);
		draw_wall();
		draw_snack();
		drawfood();
		EndBatchDraw();
	}
	system("pause");
	return 0;
}

void init()
{
	initgraph(640, 480);
	setbkcolor(RGB(229, 229, 229));
	le.snackcoor[2].x = 10;
	le.snackcoor[2].y = 10;
	le.snackcoor[1].x = 20;
	le.snackcoor[1].y = 10;
	le.snackcoor[0].x = 30;
	le.snackcoor[0].y = 10;
	cleardevice();
}

void draw_snack()
{
	setlinecolor(BLUE);
	setfillcolor(RED);
	for (int i = 0; i < le.num; i++)
	{
		fillroundrect(le.snackcoor[i].x, le.snackcoor[i].y, le.snackcoor[i].x + 10, le.snackcoor[i].y + 10, 3, 3);
	}
}

void move_snack1()
{
	//可能在这进行躯体链接
	if (_kbhit())
	{
		//可能在这进行躯体链接
		
		char ch = _getch();//这个卡住了
		cout << ch << endl;
		switch (ch)
		{
		case 'w':le.snackcoor[0].y -= 10; le.way = 1; break;
		case 's':le.snackcoor[0].y += 10; le.way = 2; break;
		case 'a':le.snackcoor[0].x -= 10; le.way = 3; break;
		case 'd':le.snackcoor[0].x += 10; le.way = 4; break;
		case't':system("pause"); break;
		}
	}
}
void initfood()
{
	srand(time(NULL));
	food.c1.x = 2+rand() % 58 ;
	food.c1.y = 2+rand() % 42 ;
	food.c1.x *= 10; food.c1.y *= 10;
	if (food.c1.x == le.snackcoor[0].x && food.c1.y == le.snackcoor[0].y)
	{
		srand(time(NULL));
		food.c1.x = 2 + rand() % 58;
		food.c1.y = 2 + rand() % 42;
		food.c1.x *= 10; food.c1.y *= 10;

	}
}
void drawfood()
{
	setlinecolor(RED);
	setfillcolor(BLUE);
	fillroundrect(food.c1.x, food.c1.y, food.c1.x + 10, food.c1.y + 10, 3, 3);

}
void eatfood()
{
	if (food.c1.x == le.snackcoor[0].x && food.c1.y == le.snackcoor[0].y)
	{
		le.num++;
		srand(time(NULL));
		food.c1.x = 2 + rand() % 58;
		food.c1.y = 2 + rand() % 42;
		food.c1.x *= 10; food.c1.y *= 10;


     }

}
void eatself()
{
	for (int i = 3; i <= le.num; i++)//i是自食后最少剩下多少
	{
		if (le.snackcoor[0].x == le.snackcoor[i].x && le.snackcoor[0].y == le.snackcoor[i].y)
		{
			le.num = i;
			Sleep(1000);//发生自食后停顿一下
		}
	}
}
/*void move_snack2()
{
	int temp = 0;
	if (_kbhit())
	{
		temp = 1;
	}
	cout << temp << endl;

	while(temp==1)
  { 
	if (le.way == 1)
	{
		le.snackcoor[0].y -= 5;
		if(_kbhit())
		{
			break;
		}
	}
	if (le.way == 2)
	{
		le.snackcoor[0].y += 5;
		if (_kbhit())
		{
			break;
		}
	}
	if (le.way == 3)
	{
		le.snackcoor[0].x -= 5;
		if (_kbhit())
		{
			break;
		}
	}
	if (le.way == 4)
	{
		le.snackcoor[0].x += 5;
		if (_kbhit())
		{
			break;
		}
	}
   }
}*/
void move_snack2()
{
	for (int i = le.num; i > 0; i--)
	{
		le.snackcoor[i].x = le.snackcoor[i - 1].x;
		le.snackcoor[i].y = le.snackcoor[i - 1].y;
	}
	if (le.way == 1)
	{
		le.snackcoor[0].y -= 10;
	}
	if (le.way == 2)
	{
		le.snackcoor[0].y += 10;
	}
	if (le.way == 3)
	{
		le.snackcoor[0].x -= 10;
	}
	if (le.way == 4)
	{
		le.snackcoor[0].x += 10;
	}
}
void wall_coor()
{
	for (int i = 0; i < 64; i++)
	{
		wal.upwa1[i].x = i * 10;
	}
	for (int i = 0; i < 64; i++)
	{
		wal.upwa[i].y = 470;
		wal.upwa[i].x = i * 10;
	}
	for (int i = 0; i < 48; i++)
	{
		wal.lrwa1[i].y = i * 10;
	}
	for (int i = 0; i < 48; i++)
	{
		wal.lrwa[i].x = 630;
		wal.lrwa[i].y = i * 10;
	}
}
void draw_wall()
{
	setlinecolor(RED);
	setfillcolor(GREEN);
	for (int i = 0; i < 64; i++)
	{
		fillroundrect(wal.upwa[i].x, wal.upwa[i].y, wal.upwa[i].x + 10, wal.upwa[i].y + 10, 3, 3);
	}
	for (int i = 0; i < 64; i++)
	{
		fillroundrect(wal.upwa1[i].x, wal.upwa1[i].y, wal.upwa1[i].x + 10, wal.upwa1[i].y + 10, 3, 3);
	}
	for (int i = 0; i < 48; i++)
	{
		fillroundrect(wal.lrwa[i].x, wal.lrwa[i].y, wal.lrwa[i].x + 10, wal.lrwa[i].y + 10, 3, 3);
	}
	for (int i = 0; i < 48; i++)
	{
		fillroundrect(wal.lrwa1[i].x, wal.lrwa1[i].y, wal.lrwa1[i].x + 10, wal.lrwa1[i].y + 10, 3, 3);
	}

}
void hitwall()
{
	if (le.snackcoor[0].y < 10 || le.snackcoor[0].y>470 || le.snackcoor[0].x < 10 || le.snackcoor[0].x > 630)
	{
		system("pause");
		closegraph();
		cout << "傻逼" << endl;
	}


}
//大饼：自动走(完成)，撞墙死（转跳），反方向优化，头部单独画图，美化界面（积分啥的），开始界面转跳包括选择速度，做出多人游戏
//DEBUG：转弯的转角和初始化只剩一格