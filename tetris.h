#include "cprocessing.h"
#include <stdio.h>
#include <stdlib.h>

struct GameObject
{
	float x;
	float y;
	float size;
	int block[4][4];
	CP_Color color;
	int num;
};

int IsSameColor(CP_Color color1, CP_Color color2);

CP_Color Create_Color();

void Random_Block(struct GameObject obj);

void Straight_Shape(struct GameObject obj);

void R_L_Shape(struct GameObject obj);

void L_Shape(struct GameObject obj);

void Square_Shape(struct GameObject obj);

void S_Shape(struct GameObject obj);

void T_Shape(struct GameObject obj);

void Z_Shape(struct GameObject obj);

void Clock_Spin(struct GameObject obj);

void Counter_Spin(struct GameObject obj);

void Show_Next(struct GameObject obj);

void Hold(struct GameObject obj);

void Set_Block(struct GameObject obj);

void Move_Block(struct GameObject obj);

void game_init(void);

void game_update(void);

void game_exit(void);