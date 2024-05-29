#include "tetris.h"

int st = 50;

struct GameObject game_object[1];


void Straight_Shape(struct GameObject obj)
{
	CP_Settings_Fill(obj.color);
	CP_Graphics_DrawRect(obj.x / 2 - st, obj.y, obj.size, obj.size);
	CP_Graphics_DrawRect(obj.x / 2, obj.y, obj.size, obj.size);
	CP_Graphics_DrawRect(obj.x / 2 + st, obj.y, obj.size, obj.size);
	CP_Graphics_DrawRect(obj.x / 2 + st * 2, obj.y, obj.size, obj.size);
}

void R_L_Shape(struct GameObject obj)
{
	CP_Settings_Fill(obj.color);
	CP_Graphics_DrawRect(obj.x / 2, obj.y, obj.size, obj.size);
	CP_Graphics_DrawRect(obj.x / 2, obj.y + st, obj.size, obj.size);
	CP_Graphics_DrawRect(obj.x / 2 + st, obj.y + st, obj.size, obj.size);
	CP_Graphics_DrawRect(obj.x / 2 + st * 2, obj.y + st, obj.size, obj.size);
}

void L_Shape(struct GameObject obj)
{
	CP_Settings_Fill(obj.color);
	CP_Graphics_DrawRect(obj.x / 2, obj.y, obj.size, obj.size);
	CP_Graphics_DrawRect(obj.x / 2, obj.y + st, obj.size, obj.size);
	CP_Graphics_DrawRect(obj.x / 2 - st, obj.y + st, obj.size, obj.size);
	CP_Graphics_DrawRect(obj.x / 2 - st * 2, obj.y + st, obj.size, obj.size);
}

void Square_Shape(struct GameObject obj)
{
	CP_Settings_Fill(obj.color);
	CP_Graphics_DrawRect(obj.x / 2, obj.y, obj.size, obj.size);
	CP_Graphics_DrawRect(obj.x / 2 + st, obj.y, obj.size, obj.size);
	CP_Graphics_DrawRect(obj.x / 2, obj.y + st, obj.size, obj.size);
	CP_Graphics_DrawRect(obj.x / 2 + st, obj.y + st, obj.size, obj.size);
}

void S_Shape(struct GameObject obj)
{
	CP_Settings_Fill(obj.color);
	CP_Graphics_DrawRect(obj.x / 2, obj.y, obj.size, obj.size);
	CP_Graphics_DrawRect(obj.x / 2 + st, obj.y, obj.size, obj.size);
	CP_Graphics_DrawRect(obj.x / 2, obj.y + st, obj.size, obj.size);
	CP_Graphics_DrawRect(obj.x / 2 - st, obj.y + st, obj.size, obj.size);
}

void T_Shape(struct GameObject obj)
{
	CP_Settings_Fill(obj.color);
	CP_Graphics_DrawRect(obj.x / 2, obj.y, obj.size, obj.size);
	CP_Graphics_DrawRect(obj.x / 2 + st, obj.y + st, obj.size, obj.size);
	CP_Graphics_DrawRect(obj.x / 2, obj.y + st, obj.size, obj.size);
	CP_Graphics_DrawRect(obj.x / 2 - st, obj.y + st, obj.size, obj.size);
}

void Z_Shape(struct GameObject obj)
{
	CP_Settings_Fill(obj.color);
	CP_Graphics_DrawRect(obj.x / 2, obj.y, obj.size, obj.size);
	CP_Graphics_DrawRect(obj.x / 2 - st, obj.y, obj.size, obj.size);
	CP_Graphics_DrawRect(obj.x / 2, obj.y + st, obj.size, obj.size);
	CP_Graphics_DrawRect(obj.x / 2 + st, obj.y + st, obj.size, obj.size);
}

int IsSameColor(CP_Color color1, CP_Color color2)
{
	if (color1.r == color2.r && color1.g == color2.g && color1.b == color2.b && color1.a == color2.a)
	{
		return 1;
	}
	else
	{
		return 0;
	}

}

CP_Color Create_Color()
{
	int r = CP_Random_RangeInt(0, 255);
	int g = CP_Random_RangeInt(0, 255);
	int b = CP_Random_RangeInt(0, 255);
	int a = 255;
	CP_Color Block_Color = CP_Color_Create(r, g, b, a);
	return Block_Color;
}

void Random_Block(struct GameObject obj)
{
	switch (obj.num) {
	case 1:
		Straight_Shape(obj);
		break;
	case 2:
		R_L_Shape(obj);
		break;
	case 3:
		L_Shape(obj);
		break;
	case 4:
		Square_Shape(obj);
		break;
	case 5:
		S_Shape(obj);
		break;
	case 6 :
		T_Shape(obj);
		break;
	case 7:
		Z_Shape(obj);
		break;
	}
}

void game_init(void)
{
	CP_System_SetWindowSize(500, 500);
	game_object[0].x = 500;
	game_object[0].y = 0;
	game_object[0].size = 50;
	game_object[0].color = Create_Color();
	int ran = CP_Random_RangeInt(1, 7);
	game_object[0].num = ran;
}

void game_update(void)
{
	CP_Color Black = CP_Color_Create(0, 0, 0, 255);
	CP_Graphics_ClearBackground(Black);
	CP_Settings_RectMode(CP_POSITION_CENTER);

	static float dx = 100;
	static float dy = 100;

	float frame = CP_System_GetDt();
	static float sec = 0;
	sec += frame;
	float standard_sec = 1;

	if (CP_Input_KeyTriggered(KEY_SPACE))
	{
		// put down the block
	}

	if (CP_Input_KeyTriggered(KEY_RIGHT))
	{
		game_object[0].x += dx;
	}

	if (CP_Input_KeyTriggered(KEY_LEFT))
	{
		game_object[0].x -= dx;
	}

	if (CP_Input_KeyTriggered(KEY_X) || CP_Input_KeyTriggered(KEY_UP))
	{
		// turn the block in clockwise
	}

	if (CP_Input_KeyTriggered(KEY_Z) || CP_Input_KeyTriggered(KEY_LEFT_CONTROL) || CP_Input_KeyTriggered(KEY_RIGHT_CONTROL))
	{
		// turn the block in counterclockwise
	}

	if (sec >= standard_sec)
	{
		game_object[0].y += dy;

		if (CP_Input_KeyDown(KEY_DOWN))
		{
			game_object[0].y += dy;
		}
		sec = 0;
	}
	Random_Block(game_object[0]);
}

void game_exit(void)
{

}
