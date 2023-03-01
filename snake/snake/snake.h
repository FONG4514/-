#ifndef _SNAKE_H
#define _SNAKE_H
#define MAX 500
struct coor
{
	int x=0;
	int y=0;
};
struct snack
{
	int num = 3;
	coor snackcoor[MAX];
	int way = 0;

}le;
struct food
{
	bool exist = 1;
	coor c1;

}food;
struct wall
{
	coor upwa[MAX];
	coor upwa1[MAX];
	coor lrwa[MAX];
	coor lrwa1[MAX];
}wal;



void init();//≥ı ºªØ
void draw_snack();
void drawfood();
void initfood();
void eatfood();
void eatself();
void move_snack1();
void move_snack2();
void wall_coor();
void draw_wall();
void hitwall();
#endif
