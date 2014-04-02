#pragma once

//#define CHESS_ADDR (0x129f78)
//#define CHESS_ADDR (0x189f7c)
#define GAME_CAPTION "QQ游戏 - 连连看角色版"

#define DIRECT_BEGIN (0)
#define DIRECT_UP (1)
#define DIRECT_DOWN (2)
#define DIRECT_LEFT (3)
#define DIRECT_RIGHT (4)

#define BLOCK_HIGHT (34)
#define BLOCK_WIDTH (31)



class ClearLianliankan
{
public:
	ClearLianliankan(const LPVOID lpChes);
	~ClearLianliankan();
	BOOL Clear();
	BOOL bCheck(int x1, int y1, int x2, int y2, int cTurn, int eDirect);
private:
	BYTE chess[11][19];
	BYTE chess2[13][21];
	LPVOID lpChess;
};

