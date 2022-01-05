#include <iostream>
#include <time.h>

using namespace std;

int main()
{
	int iBingo[5][5];
    srand((unsigned int)time(0));

	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			iBingo[i][j] = i * 5 + j + 1;
		}
	}

	int iTemp, idx1, idx2, idx3, idx4;

	// 100번 섞어줌.
	for (int i = 0; i < 100; ++i)
	{
		idx1 = rand() % 5;
		idx2 = rand() % 5;
		idx3 = rand() % 5;
		idx4 = rand() % 5;

		iTemp = iBingo[idx1][idx2];
		iBingo[idx1][idx2] = iBingo[idx3][idx4];
		iBingo[idx3][idx4] = iTemp;
	}

	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			cout << iBingo[i][j] << "\t";
			if (j == 4 || j == 9 || j == 14 || j == 19)
				cout << endl; 
		}
	}
	cout << endl;

	int iPlayer;

	while (1)
	{
		cout << "숫자를 입력하시오. (1 ~ 25 사이, 0을 입력할 경우 게임 종료) : ";
		cin >> iPlayer;

		// 0을 입력 받았을 경우 게임종료
		if (iPlayer == 0)
			break;

		// 숫자가 25보다 클 경우 다시 선택
		else if (iPlayer > 25)
		{
			cout << "25보다 큰 숫자입니다. 다시 선택하세요." << endl;
			continue;
		}
		
		// iPlayer의 값과 iBingo에 있는 값이 같을 경우 -1로 변경
		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 5; ++j)
			{
				if (iPlayer == iBingo[i][j])
					iBingo[i][j] = -1;
			}
		}

		// iBingo에 값이 -1일 경우 *로 출력
		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 5; ++j)
			{
				if (iBingo[i][j] == -1)
					cout << "*" << "\t";
				else
					cout << iBingo[i][j] << "\t";
				if (j == 4 || j == 9 || j == 14 || j == 19)
					cout << endl;
			}
		}

		// 가로, 세로 빙고 체크
		int iCross1 = 0, iCross2 = 0, iCount = 0;

		for (int i = 0; i < 5; ++i)
		{
			// 반복 될 때마다 가로, 세로 초기화
			int iRow = 0, iCol = 0;

			for (int j = 0; j < 5; ++j)
			{
				if (iBingo[i][j] == -1) // 가로
					++iRow;
				if (iBingo[j][i] == -1) // 세로
					++iCol;
				if (i == j && iBingo[i][j] == -1) // 왼쪽위에서 오른쪽아래 대각선
					++iCross1;
				if ((i + j == 4) && iBingo[i][j] == -1) // 왼쪽 밑에서 오른쪽위 대각선
					++iCross2;
			}
			if (iRow == 5)
				++iCount;
			if (iCol == 5)
				++iCount;
			if (iCross1 == 5)
				++iCount;
			if (iCross2 == 5)
				++iCount;
		}

		cout << endl << iCount << "줄 빙고 !" << endl << endl;

		if (iCount == 5)
		{
			cout << "=================" << endl;
			cout << " 빙고게임 종료 !" << endl;
			break;
		}
	}
    return 0;
}
/*
알고리즘 설명
1. 2차원 배열 생성.
2. 셔플을 통해 숫자를 섞어줌.
3. 5 x 5형태로 출력.
4. Playrer의 input과 랜덤생성된 2차원 배열에 같은 숫자가 있을 경우 -1로 변경
5. 그 후에  -1의 값은 *로 출력
6. 가로, 세로, 대각선, 역대각선의 빙고를 확인하고 빙고일 경우 count의 갯수를 1씩 증가
7. count의 갯수가 5개. 즉 다섯줄 일 경우 빙고게임 종료
*/