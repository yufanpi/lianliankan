#include "stdafx.h"
#include "ClearLianliankan.h"


ClearLianliankan::ClearLianliankan(const LPVOID lpChes)
{
	lpChess = lpChes;
}


ClearLianliankan::~ClearLianliankan()
{
}

BOOL ClearLianliankan::bCheck(int x1, int y1, int x2, int y2, int cTurn, int eDirect)
{
	if (cTurn > 3)
		return FALSE;
	if (x1 == x2 && y1 == y2)
		return TRUE;

	//UP
	if ((chess2[x1 - 1][y1] == 0 || chess2[x1 - 1][y1] == chess2[x2][y2]) && eDirect != DIRECT_DOWN)
	{
		if (eDirect != DIRECT_UP)
		{
			if (bCheck(x1 - 1, y1, x2, y2, cTurn + 1, DIRECT_UP))
				return TRUE;
		}
		else
		{
			if (bCheck(x1 - 1, y1, x2, y2, cTurn, DIRECT_UP))
				return TRUE;
		}
	}
	//DOWN
	if ((chess2[x1 + 1][y1] == 0 || chess2[x1 + 1][y1] == chess2[x2][y2]) && eDirect != DIRECT_UP)
	{
		if (eDirect != DIRECT_DOWN)
		{
			if (bCheck(x1 + 1, y1, x2, y2, cTurn + 1, DIRECT_DOWN))
				return TRUE;
		}
		else
		{
			if (bCheck(x1 + 1, y1, x2, y2, cTurn, DIRECT_DOWN))
				return TRUE;
		}
	}
	//LEFT
	if ((chess2[x1][y1 - 1] == 0 || chess2[x1][y1 - 1] == chess2[x2][y2]) && eDirect != DIRECT_RIGHT)
	{
		if (eDirect != DIRECT_LEFT)
		{
			if (bCheck(x1, y1 - 1, x2, y2, cTurn + 1, DIRECT_LEFT))
				return TRUE;
		}
		else
		{
			if (bCheck(x1, y1 - 1, x2, y2, cTurn, DIRECT_LEFT))
				return TRUE;
		}
	}
	//RIGHT
	if ((chess2[x1][y1 + 1] == 0 || chess2[x1][y1 + 1] == chess2[x2][y2]) && eDirect != DIRECT_LEFT)
	{
		if (eDirect != DIRECT_RIGHT)
		{
			if (bCheck(x1, y1 + 1, x2, y2, cTurn + 1, DIRECT_RIGHT))
				return TRUE;
		}
		else
		{
			if (bCheck(x1, y1 + 1, x2, y2, cTurn, DIRECT_RIGHT))
				return TRUE;
		}
	}
	return FALSE;

}

BOOL ClearLianliankan::Clear()
{
	DWORD pid;
	HWND hWnd;
	HANDLE hGame;

	hWnd = FindWindow(NULL, _T(GAME_CAPTION));
	if (hWnd == NULL)
	{
		_tprintf_s(_T("Cant find window\n"));
		return FALSE;
	}

	GetWindowThreadProcessId(hWnd, &pid);
	hGame = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
	ReadProcessMemory(hGame, lpChess, chess, 11 * 19, NULL);
	CloseHandle(hGame);

	//fill chess
	memset(chess2, -1, sizeof(chess2));
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			chess2[i + 1][j + 1] = chess[i][j];
		}
	}


	int x1, x2, y1, y2;
	for (x1 = 1; x1 <= 11; x1++)
	{
		for (y1 = 1; y1 <= 19; y1++)
		{
			if (chess2[x1][y1] == 0)
				continue;

			for (x2 = 1; x2 <= 11; x2++)
			{
				for (y2 = 1; y2 <= 19; y2++)
				{
					if (!(x1 == x2 && y1 == y2) && chess2[x1][y1] == chess2[x2][y2])
					{
						if (bCheck(x1, y1, x2, y2, 0, DIRECT_BEGIN))
						{
							_tprintf_s(_T("GET:%d,%d and %d,%d\n"), x1, y1, x2, y2);
							PostMessage(hWnd, WM_LBUTTONDOWN, 0, MAKELPARAM(25 + BLOCK_WIDTH*(y1 - 1), 195 + BLOCK_HIGHT*(x1 - 1)));
							PostMessage(hWnd, WM_LBUTTONUP, 0, MAKELPARAM(25 + BLOCK_WIDTH*(y1 - 1), 195 + BLOCK_HIGHT*(x1 - 1)));
							//Sleep(500);
							PostMessage(hWnd, WM_LBUTTONDOWN, 0, MAKELPARAM(25 + BLOCK_WIDTH*(y2 - 1), 195 + BLOCK_HIGHT*(x2 - 1)));
							PostMessage(hWnd, WM_LBUTTONUP, 0, MAKELPARAM(25 + BLOCK_WIDTH*(y2 - 1), 195 + BLOCK_HIGHT*(x2 - 1)));
							CloseHandle(hWnd);
							return TRUE;
						}
					}
				}
			}
		}
	}

	CloseHandle(hWnd);
	return FALSE;
}