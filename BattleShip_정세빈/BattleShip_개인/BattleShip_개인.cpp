// BattleShip_����.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>
#include <time.h>
#include <string>


int atoi(const char* str);

int _tmain(int argc, _TCHAR* argv[])
{	
	char* str = "1234";
	int num;
	//num = atoi(str);
	num = atoi(str);
	printf_s("%d\n", num);
	getchar();
	return 0;
}

int atoi(const char* str)
{
	int result = 0;
	int list[256] = { 0, };
	int idx = 0;
	int count = -1;

	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i]<='9'&&str[i]>='0')
		{
			list[idx] = str[i]-48;
			idx++;
			count++;
		}
		else
			break;
	}
	idx = 0;
	for (; count > -1; count--)
	{
		result += list[idx] * pow(10,count);
		idx++;
	}
	return result;
}