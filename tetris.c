#include "tetris.h"

struct GameObject game_object[1];

int board[25][12] = {};

void Straight_Shape(struct GameObject obj)
{
	CP_Settings_Fill(obj.color);
	CP_Graphics_DrawRect(obj.x * obj.size - obj.size, obj.y * obj.size, obj.size, obj.size);
	CP_Graphics_DrawRect(obj.x * obj.size, obj.y * obj.size, obj.size, obj.size);
	CP_Graphics_DrawRect(obj.x * obj.size + obj.size, obj.y * obj.size, obj.size, obj.size);
	CP_Graphics_DrawRect(obj.x * obj.size + obj.size * 2, obj.y * obj.size, obj.size, obj.size);
	obj.block[2][0] = 1;
	obj.block[2][1] = 1;
	obj.block[2][2] = 1;
	obj.block[2][3] = 1;
}

void R_L_Shape(struct GameObject obj)
{
	CP_Settings_Fill(obj.color);
	CP_Graphics_DrawRect(obj.x * obj.size, obj.y * obj.size, obj.size, obj.size);
	CP_Graphics_DrawRect(obj.x * obj.size + obj.size, obj.y * obj.size, obj.size, obj.size);
	CP_Graphics_DrawRect(obj.x * obj.size - obj.size, obj.y * obj.size, obj.size, obj.size);
	CP_Graphics_DrawRect(obj.x * obj.size - obj.size, obj.y * obj.size - obj.size, obj.size, obj.size);
	obj.block[1][0] = 1;
	obj.block[2][0] = 1;
	obj.block[2][1] = 1;
	obj.block[2][2] = 1;
}

void L_Shape(struct GameObject obj)
{
	CP_Settings_Fill(obj.color);
	CP_Graphics_DrawRect(obj.x * obj.size, obj.y * obj.size, obj.size, obj.size);
	CP_Graphics_DrawRect(obj.x * obj.size + obj.size, obj.y * obj.size, obj.size, obj.size);
	CP_Graphics_DrawRect(obj.x * obj.size - obj.size, obj.y * obj.size, obj.size, obj.size);
	CP_Graphics_DrawRect(obj.x * obj.size + obj.size, obj.y * obj.size - obj.size, obj.size, obj.size);
	obj.block[2][0] = 1;
	obj.block[2][1] = 1;
	obj.block[2][2] = 1;
	obj.block[1][2] = 1;
}

void Square_Shape(struct GameObject obj)
{
	CP_Settings_Fill(obj.color);
	CP_Graphics_DrawRect(obj.x * obj.size, obj.y * obj.size, obj.size, obj.size);
	CP_Graphics_DrawRect(obj.x * obj.size - obj.size, obj.y * obj.size, obj.size, obj.size);
	CP_Graphics_DrawRect(obj.x * obj.size, obj.y * obj.size - obj.size, obj.size, obj.size);
	CP_Graphics_DrawRect(obj.x * obj.size - obj.size, obj.y * obj.size - obj.size, obj.size, obj.size);
	obj.block[1][1] = 1;
	obj.block[1][2] = 1;
	obj.block[2][1] = 1;
	obj.block[2][2] = 1;
}

void S_Shape(struct GameObject obj)
{
	CP_Settings_Fill(obj.color);
	CP_Graphics_DrawRect(obj.x * obj.size, obj.y * obj.size, obj.size, obj.size);
	CP_Graphics_DrawRect(obj.x * obj.size - obj.size, obj.y * obj.size, obj.size, obj.size);
	CP_Graphics_DrawRect(obj.x * obj.size, obj.y * obj.size - obj.size, obj.size, obj.size);
	CP_Graphics_DrawRect(obj.x * obj.size + obj.size, obj.y * obj.size - obj.size, obj.size, obj.size);
	obj.block[1][1] = 1;
	obj.block[1][2] = 1;
	obj.block[2][0] = 1;
	obj.block[2][1] = 1;
}

void T_Shape(struct GameObject obj)
{
	CP_Settings_Fill(obj.color);
	CP_Graphics_DrawRect(obj.x * obj.size, obj.y * obj.size, obj.size, obj.size);
	CP_Graphics_DrawRect(obj.x * obj.size + obj.size, obj.y * obj.size, obj.size, obj.size);
	CP_Graphics_DrawRect(obj.x * obj.size - obj.size, obj.y * obj.size, obj.size, obj.size);
	CP_Graphics_DrawRect(obj.x * obj.size, obj.y * obj.size - obj.size, obj.size, obj.size);
	obj.block[2][0] = 1;
	obj.block[2][1] = 1;
	obj.block[2][2] = 1;
	obj.block[1][1] = 1;
}

void Z_Shape(struct GameObject obj)
{
	CP_Settings_Fill(obj.color);
	CP_Graphics_DrawRect(obj.x * obj.size, obj.y * obj.size, obj.size, obj.size);
	CP_Graphics_DrawRect(obj.x * obj.size + obj.size, obj.y * obj.size, obj.size, obj.size);
	CP_Graphics_DrawRect(obj.x * obj.size, obj.y * obj.size - obj.size, obj.size, obj.size);
	CP_Graphics_DrawRect(obj.x * obj.size - obj.size, obj.y * obj.size - obj.size, obj.size, obj.size);
	obj.block[2][1] = 1;
	obj.block[2][2] = 1;
	obj.block[1][0] = 1;
	obj.block[1][1] = 1;
}

void Clock_Spin(struct GameObject obj)
{
	if (CP_Input_KeyTriggered(KEY_X) || CP_Input_KeyTriggered(KEY_UP))
	{
		
	}
}

void Counter_Spin(struct GameObject obj)
{
	if (CP_Input_KeyTriggered(KEY_Z) || CP_Input_KeyTriggered(KEY_LEFT_CONTROL) || CP_Input_KeyTriggered(KEY_RIGHT_CONTROL))
	{
		// turn the block in counterclockwise
	}
}

void Show_Next(struct GameObject obj)
{

}

void Hold(struct GameObject obj)
{
	if (CP_Input_KeyTriggered(KEY_C))
	{

	}
}

void Set_Block(struct GameObject obj)
{
	if (CP_Input_KeyTriggered(KEY_SPACE))
	{

	}
}

void Move_Block(struct GameObject obj)
{
	static int count = 0;

	if (CP_Input_KeyTriggered(KEY_RIGHT))
	{
		game_object[0].x += 1;
		count++;
	}
	if (CP_Input_KeyDown(KEY_RIGHT) && count >= 20)
	{
		game_object[0].x += 1;
	}
	else if (CP_Input_KeyDown(KEY_RIGHT))
	{
		count++;
	}
	if (CP_Input_KeyReleased(KEY_RIGHT))
	{
		count = 0;
	}

	if (CP_Input_KeyTriggered(KEY_LEFT))
	{
		game_object[0].x -= 1;
		count++;
	}
	if (CP_Input_KeyDown(KEY_LEFT) && count >= 20)
	{
		game_object[0].x -= 1;
	}
	else if (CP_Input_KeyDown(KEY_LEFT))
	{
		count++;
	}
	if (CP_Input_KeyReleased(KEY_LEFT))
	{
		count = 0;
	}

	if (CP_Input_KeyTriggered(KEY_DOWN))
	{
		game_object[0].y += 1;
		count++;
	}
	if (CP_Input_KeyDown(KEY_DOWN) && count >= 20)
	{
		game_object[0].y += 1;
	}
	else if (CP_Input_KeyDown(KEY_DOWN))
	{
		count++;
	}
	if (CP_Input_KeyReleased(KEY_DOWN))
	{
		count = 0;
	}
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
	CP_System_SetWindowSize(300, 600);
	game_object[0].x = 4;
	game_object[0].y = 0;
	game_object[0].size = 30;
	game_object[0].color = Create_Color();
	int ran = CP_Random_RangeInt(1, 7);
	game_object[0].num = ran;
	memset(board, 0, sizeof(board));
	for (int row = 0; row < 25; row++)
	{
		board[row][0] = 1;
		board[row][11] = 1;
	}
	for (int col = 0; col < 11; col++)
	{
		board[24][col] = 1;
	}
}

void game_update(void)
{
	CP_Color Black = CP_Color_Create(0, 0, 0, 255);
	CP_Graphics_ClearBackground(Black);

	float frame = CP_System_GetDt();
	static float sec = 0;
	sec += frame;
	float standard_sec = 1;

	memset(game_object[0].block, 0, sizeof(game_object[0].block));

	Set_Block(game_object[0]);
	Move_Block(game_object[0]);

	if (sec >= standard_sec)
	{
		int board_y = (int)game_object[0].y;
		int board_x = (int)game_object[0].x;
		if (board[board_y + 1][board_x] == 1)
		{
			for (int row = 0; row < 4; row++)
			{
				for (int col = 0; col < 4; col++)
				{
					if (game_object[0].block[row][col] == 1)
					{
						board[board_y - 2 + row][board_x - 1 + col] = 1;
					}
				}
			}
		}
		else
		{
			game_object[0].y += 1;
		}
		sec = 0;
	}
	Random_Block(game_object[0]);

	// draw
	// obj.r, obj.c => x, y
	// draw piece (x,y)
}

void game_exit(void)
{

}
