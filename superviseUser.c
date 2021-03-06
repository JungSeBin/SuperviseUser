#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <Windows.h>
#include <time.h>
#include "userInfo.h"

#pragma warning(disable:4996)

#define MAX 11
#define BUF 255
user_t user[100];
char buffer[BUF];
int count = 0;
int ID;

void gotoxy(int x, int y)
{
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

int main(void)
{
	int i;
	int select;
	char password[30];
	char hint[30];
	char answer[30] = "박은종 교수님 감사합니다";
	char list[255];
	char *str;
	FILE *fp = fopen("data.txt", "r");
	if (fp == NULL)
	{
		RED; printf("\n\n\n\t\t\tERROR: ");
		WHITE; printf("파일이 존재하지 않습니다.\n\n\n");
		return -1;
	}

	fgets(list, sizeof(list), fp);
	while (feof(fp) == 0)
	{
		fgets(list, sizeof(list), fp);
		str = strtok(list, "\t");
		user[count].ID = atoi(str);

		str = strtok(NULL, "\t");
		strcpy(user[count].name, str);

		str = strtok(NULL, "\t");
		strcpy(user[count].address, str);

		str = strtok(NULL, "\n");
		strcpy(user[count].phone, str);

		count++;
	}
	fclose(fp);
	ID = user[0].ID;
	for (i = 0; i < count; i++)
	{
		ID = ID>user[i].ID ? ID : user[i].ID;
	}
	while (1)
	{
		printf("\n\n\n\t\t     힌트을 보시고 싶으면 \"");
		YELLOW; printf("힌트");
		WHITE; printf("\" 를 적으십시오");
		if (!strcmp(password, "힌트") || !strcmp(hint, "힌트"))
		{
			if (!strcmp(password, "힌트"))
			{
				strcpy(hint, password);
			}
			printf("\n\n\n\t\t\t힌트: ○○○ 교수님 감사합니다");
		}
		gotoxy(23, 9);
		printf("\n\n\t●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○");
		printf("\n\t○●                                                        ○●");
		printf("\n\t●○            비밀번호:                                   ●○");
		printf("\n\t○●                                                        ○●");
		printf("\n\t●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○");
		gotoxy(35, 13);
		gets(password);
		if (!strcmp(password, answer))
			break;
		else
			system("cls");
	}
	
	while (1)
	{
		WHITE;
		system("cls");
		printf("  \t      ○●○●○●○●○●○●○●○●○●○●○●○●○●");
		printf("\n\t      ●○                                            ●○");
		printf("\n\t      ○●                                            ○●");
		printf("\n\t      ●○                                            ●○");
		printf("\n\t      ○●                                            ○●");
		printf("\n\t      ●○                                            ●○");
		printf("\n\t      ○●                                            ○●");
		printf("\n\t      ●○                                            ●○");
		printf("\n\t      ○●                                            ○●");
		printf("\n\t      ●○                                            ●○");
		printf("\n\t      ○●                                            ○●");
		printf("\n\t      ●○                                            ●○");
		printf("\n\t      ○●                                            ○●");
		printf("\n\t      ●○                                            ●○");
		printf("\n\t      ○●                                            ○●");
		printf("\n\t      ●○                                            ●○");
		printf("\n\t      ○●                                            ○●");
		printf("\n\t      ●○                                            ●○");
		printf("\n\t      ○●                                            ○●");
		printf("\n\t      ●○                                            ●○");
		printf("\n\t      ○●                                            ○●");
		printf("\n\t      ●○                                            ●○");
		printf("\n\t      ○●○●○●○●○●○●○●○●○●○●○●○●○●");
		gotoxy(32, 3);
		VIOLET; printf("1번: 회원 목록보기");
		gotoxy(32, 6);
		YELLOW; printf("2번: 회원 등록하기");
		gotoxy(32, 9);
		SKY; printf("3번: 회원 저장하기");
		gotoxy(32, 12);
		YELGREEN; printf("4번: 회원 편집하기");
		gotoxy(32, 15);
		RED; printf("5번: 회원 삭제하기");
		gotoxy(32, 18);
		FLUORESCENT; printf("6번: 회원 검색하기");
		gotoxy(32, 21);
		WHITE; printf("ESC: 종료하기");
		gotoxy(64, 25);
		WHITE; printf("Thanks to.덕성킴");
		
	
		
		while (1)
		{
			select = getch();
			switch (select)
			{
			case '1':
				system("cls");
				printUser();
				break;
			case '2':
				system("cls");
				insertUser();
				break;
			case '3':
				system("cls");
				saveUser();
				break;
			case '4':
				system("cls");
				editUser();
				break;
			case '5':
				system("cls");
				deleteUser();
				break;
			case '6':
				system("cls");
				searchUser();
				break;
			}
			if (select == '1' || select == '2' || select == '3' || select == '4'
				|| select=='5'|| select == '6')
				break;
			else if (select == 27)
			{
				while (1)
				{
					system("cls");
					printf("\n\n\n\n\n\n\n\n\t\t\t저장하시겠습니까? (Y/N)");
					i = getch();
					switch (i)
					{
					case 121:
						saveUser();
						break;
					case 110:
						break;
					}
					if (i == 110 || i == 121)
						break;
				}
				system("cls");
				break;
			}
		}
		if (select == 27)
		{
			system("cls");
			break;
		}
	}
	for (i = 0; i < 10; i++)
	{
		system("cls");
		gotoxy(20, 12);
		WHITE;
		printf("\n\n\t○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●");
		printf("\n\t●○                                                        ●○");
		printf("\n\t○●                                                        ○●");
		printf("\n\t●○                                                        ●○");
		printf("\n\t○●                                                        ○●");
		printf("\n\t●○                                                        ●○");
		printf("\n\t○●                                                        ○●");
		printf("\n\t●○                                                        ●○");
		printf("\n\t○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●");
		gotoxy(20, 16);
		printf("박은종 교수님 감사합니다.");
		gotoxy(20, 20);
		printf("\t\t\t\tMade By: 정 세 빈");
		gotoxy(20, 3);
		printf("\n\n\t●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○");
		printf("\n\t○●                                                        ○●");
		printf("\n\t●○                   프로그램 종료                        ●○");
		printf("\n\t○●                                                        ○●");
		printf("\n\t●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○");
		Sleep(50);
		system("cls");
		gotoxy(20, 12);
		printf("\n\n\t○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●");
		printf("\n\t●○                                                        ●○");
		printf("\n\t○●                                                        ○●");
		printf("\n\t●○                                                        ●○");
		printf("\n\t○●                                                        ○●");
		printf("\n\t●○                                                        ●○");
		printf("\n\t○●                                                        ○●");
		printf("\n\t●○                                                        ●○");
		printf("\n\t○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●");
		gotoxy(20, 16);
		printf("박은종 교수님 감사합니다.");
		gotoxy(20, 20);
		printf("\t\t\t\tMade By: 정 세 빈");
		gotoxy(20, 3);
		printf("\n\n\t○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●");
		printf("\n\t●○                                                        ●○");
		printf("\n\t○●                   프로그램 종료                        ○●");
		printf("\n\t●○                                                        ●○");
		printf("\n\t○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●");
		Sleep(50);
	}
	while (1)
	{
		WHITE;
		system("cls");
		gotoxy(20, 12);
		printf("\n\n\t○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●");
		printf("\n\t●○                                                        ●○");
		printf("\n\t○●                                                        ○●");
		printf("\n\t●○                                                        ●○");
		printf("\n\t○●                                                        ○●");
		printf("\n\t●○                                                        ●○");
		printf("\n\t○●                                                        ○●");
		printf("\n\t●○                                                        ●○");
		printf("\n\t○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●");
		gotoxy(20, 16);
		printf("박은종 교수님 감사합니다.");
		gotoxy(20, 20);
		printf("\t\t\t\tMade By: 정 세 빈");
		gotoxy(20, 3);
		printf("\n\n\t●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○");
		printf("\n\t○●                                                        ○●");
		printf("\n\t●○                    프로그램 종료                       ●○");
		printf("\n\t○●                                                        ○●");
		printf("\n\t●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○");
		break;
	}
	gotoxy(40, 25);
}

void printUser()
{
	int idx;
	int page = 0;
	int move;

	while (1)
	{
		idx = page * MAX;
		WHITE;
		printf("ID\t");
		printf("이름\t");
		printf("주소\t\t\t");
		printf("전화번호\n");
		VIOLET;
		for (; idx < (page + 1) * MAX; idx++)
		{
			if (user[idx].ID == 0 && idx >= count)
				printf(" \t%s\t%-21s\t%s\n\n", user[idx].name, user[idx].address, user[idx].phone);
			else if (user[idx].ID == -1)
				printf("\"Delete\"\n\n");
			else
				printf("%d\t%s\t%-21s\t%s\n\n", user[idx].ID, user[idx].name, user[idx].address, user[idx].phone);
		}
		WHITE;
		printf("메뉴로 돌아가시려면 \"ESC\"를 눌러주시기 바랍니다.  ◀ page:%d ▶",page);
		move = getch();
		if (move == 77)
			page++;
		else if (move == 75)
			page--;
		else if (move == 27)
		{
			system("cls");
			break;
		}
		if (page < 0)
			page = 0;
		if (count - page * MAX < 0)
			page--;
		system("cls");
	}

}

void insertUser()
{
	int i, result = 0;
	int select;
	user[count].ID = ++ID;

	while (1)
	{
		YELLOW;
		printf("\n\n\t○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●");
		printf("\n\t●○                                                        ●○");
		printf("\n\t○●                      회원 등록                         ○●");
		printf("\n\t●○                                                        ●○");
		printf("\n\t○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●");
		printf("\n\n\n\t\t\tID: %d\n\n", user[count].ID);
		printf("\t\t\t이름: ");
		RED;
		if (result == 1)
		{
			printf("\n\n\n\n\n\n\n\n\n\n\n\t\tERROR: ");
			WHITE; printf("이름에 숫자나 공백은 들어갈 수 없습니다.");
		}
		else if (result == 2)
		{
			printf("\n\n\n\n\n\n\n\n\n\n\n\t\tERROR: ");
			WHITE; printf("이름은 한글4자 영문8자까지 가능합니다.");
		}
		YELLOW;
		gotoxy(31, 12);
		result = 0;
		fgets(buffer,BUF,stdin);
		buffer[(int)strlen(buffer) - 1] = '\0';
		fflush(stdin);

		if (strlen(buffer) == 0)
			result = 1;
		else if (strlen(buffer) > 8)
			result = 2;

		for (i = 0; i < (int)strlen(buffer); i++)
		{
			if (buffer[i] >= '0' && buffer[i] <= '9' || buffer[i] == ' ')
			{
				result = 1;
				break;
			}
		}

		if (result == 0)
		{
			strcpy(user[count].name, buffer);
			break;
		}
		system("cls");
	}
	system("cls");
	while (1)
	{
		YELLOW;
		printf("\n\n\t○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●");
		printf("\n\t●○                                                        ●○");
		printf("\n\t○●                      회원 등록                         ○●");
		printf("\n\t●○                                                        ●○");
		printf("\n\t○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●");
		printf("\n\n\n\t\t\tID: %d", user[count].ID);
		printf("\n\n\t\t\t이름: %s\n\n", user[count].name);
		printf("\t\t\t주소: ");
		RED;
		if (result == -1)
		{
			printf("\n\n\n\n\n\n\n\n\t\t\tERROR: ");
			WHITE; printf("주소를 입력해 주십시오.");
		}
		else if (result == -2)
		{
			printf("\n\n\n\n\n\n\n\n\t\t\tERROR: ");
			WHITE; printf(" 주소가 너무 깁니다.");
		}
		YELLOW;
		gotoxy(31, 14);
		fgets(buffer, BUF, stdin);
		buffer[(int)strlen(buffer) - 1] = '\0';
		fflush(stdin);
		
		if (strlen(buffer) > 50)
			result = -2;
		else if (strlen(buffer) == 0 || buffer[0] == ' ')
			result = -1;
		else
		{
			strcpy(user[count].address, buffer);
			break;
		}
		system("cls");
	}
	system("cls");
	result = -1;
	while (1)
	{
		while (1)
		{
			YELLOW
			printf("\n\n\t○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●");
			printf("\n\t●○                                                        ●○");
			printf("\n\t○●                      회원 등록                         ○●");
			printf("\n\t●○                                                        ●○");
			printf("\n\t○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●");
			printf("\n\n\n\t\t\tID: %d", user[count].ID);
			printf("\n\n\t\t\t이름: %s\n\n", user[count].name);
			printf("\t\t\t주소: %s\n\n", user[count].address);
			printf("\t\t\t전화번호: ");
			RED
			if (result == 1)
			{
				printf("\n\n\n\n\n\t\tERROR: ");
				WHITE
				printf("전화번호의 형식은 \"01x-xxxx-xxxx\" 입니다.");
			}
			else if (result == 0)
			{
				printf("\n\n\n\n\n\t\t    ERROR: ");
				WHITE
				printf("이미 존재하는 전화번호 입니다.\n\n");
			}
			YELLOW;
			gotoxy(35, 16);
			fgets(buffer, BUF, stdin);
			buffer[(int)strlen(buffer) - 1] = '\0';
			fflush(stdin);
			if (buffer[3] == '-' && buffer[8] == '-' &&strlen(buffer) == 13
				&& buffer[0] == 48 && buffer[1] == 49
				&& buffer[4] > 47 && buffer[4]<58
				&& buffer[5]>47 && buffer[5]<58
				&& buffer[6]>47 && buffer[6]<58
				&& buffer[7]>47 && buffer[7]<58
				&& buffer[9]>47 && buffer[9]<58
				&& buffer[10]>47 && buffer[10]<58
				&& buffer[11]>47 && buffer[11]<58
				&& buffer[12]>47 && buffer[12] < 58
				)
				break;
			else
				result = 1;
				system("cls");
		}
		for (i = 0; i < count; i++)
		{
			result = strcmp(user[i].phone, buffer);
			if (result == 0)
				break;
		}
		if (result != 0)
		{
			strcpy(user[count].phone, buffer);
			(user[count].phone)[strlen(buffer)] = '\0';
			break;
		}
		system("cls");
	}
	system("cls");
	for (i = 0; i < 10; i++)
	{
		system("cls");
		gotoxy(20, 12);
		YELLOW;
		printf("\n\n\t○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●");
		printf("\n\t●○                                                        ●○");
		printf("\n\t○●                                                        ○●");
		printf("\n\t●○                                                        ●○");
		printf("\n\t○●                                                        ○●");
		printf("\n\t●○                                                        ●○");
		printf("\n\t○●                                                        ○●");
		printf("\n\t●○                                                        ●○");
		printf("\n\t○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●");
		gotoxy(20, 16);
		printf("ID: %d\t이름: %s",
			user[count].ID, user[count].name);
		gotoxy(20, 18);
		printf("전화번호: %s\n", user[count].phone);
		gotoxy(20, 20);
		printf("주소: %s\n\n", user[count].address);
		gotoxy(20, 3);
		printf("\n\n\t●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○");
		printf("\n\t○●                                                        ○●");
		printf("\n\t●○                   회원 등록 완료                       ●○");
		printf("\n\t○●                                                        ○●");
		printf("\n\t●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○");
		Sleep(50);
		system("cls");
		gotoxy(20, 12);
		printf("\n\n\t○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●");
		printf("\n\t●○                                                        ●○");
		printf("\n\t○●                                                        ○●");
		printf("\n\t●○                                                        ●○");
		printf("\n\t○●                                                        ○●");
		printf("\n\t●○                                                        ●○");
		printf("\n\t○●                                                        ○●");
		printf("\n\t●○                                                        ●○");
		printf("\n\t○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●");
		gotoxy(20, 16);
		printf("ID: %d\t이름: %s",
			user[count].ID, user[count].name);
		gotoxy(20, 18);
		printf("전화번호: %s\n", user[count].phone);
		gotoxy(20, 20);
		printf("주소: %s\n\n", user[count].address);
		gotoxy(20, 3);
		GOLD;
		printf("\n\n\t○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●");
		printf("\n\t●○                                                        ●○");
		printf("\n\t○●                   회원 등록 완료                       ○●");
		printf("\n\t●○                                                        ●○");
		printf("\n\t○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●");
		Sleep(50);
	}
	while (1)
	{
		YELLOW;
		system("cls");
		gotoxy(20, 12);
		printf("\n\n\t○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●");
		printf("\n\t●○                                                        ●○");
		printf("\n\t○●                                                        ○●");
		printf("\n\t●○                                                        ●○");
		printf("\n\t○●                                                        ○●");
		printf("\n\t●○                                                        ●○");
		printf("\n\t○●                                                        ○●");
		printf("\n\t●○                                                        ●○");
		printf("\n\t○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●");
		gotoxy(20, 16);
		printf("ID: %d\t이름: %s",
			user[count].ID, user[count].name);
		gotoxy(20, 18);
		printf("전화번호: %s\n", user[count].phone);
		gotoxy(20, 20);
		printf("주소: %s\n\n", user[count].address);
		gotoxy(20, 3);
		printf("\n\n\t●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○");
		printf("\n\t○●                                                        ○●");
		printf("\n\t●○                   회원 등록 완료                       ●○");
		printf("\n\t○●                                                        ○●");
		printf("\n\t●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○");
		WHITE;
		printf("\n\n\n\t\t회원 등록하기를 종료합니다. \"ESC\"를 눌러주시기 바랍니다.");
		select = getch();
		if (select == 27)
			break;
		system("cls");
	}
	count++;
}


void saveUser()
{
	FILE *fp = fopen("data.txt","w");
	int idx;
	int select;

	fprintf(fp, "ID\t이름\t주소\t\t\t전화번호");
	for (idx = 0; idx < count; idx++)
	{
		if (user[idx].ID == -1)
			continue;
		fprintf(fp,"\n%d\t%s\t%-21s\t%s", user[idx].ID, user[idx].name, user[idx].address, user[idx].phone);
	}
	fclose(fp);
	for (idx = 0; idx < 10; idx++)
	{
		system("cls");
		BLUE;
		printf("\n\n\t●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○");
		printf("\n\t○●                                                        ○●");
		printf("\n\t●○                   회원 저장 완료                       ●○");
		printf("\n\t○●                                                        ○●");
		printf("\n\t●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○");
		Sleep(50);
		system("cls");
		SKY;
		printf("\n\n\t○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●");
		printf("\n\t●○                                                        ●○");
		printf("\n\t○●                   회원 저장 완료                       ○●");
		printf("\n\t●○                                                        ●○");
		printf("\n\t○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●");
		Sleep(50);
	}
	system("cls");
	while (1)
	{
		SKY
		printf("\n\n\t○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●");
		printf("\n\t●○                                                        ●○");
		printf("\n\t○●                   회원 저장 완료                       ○●");
		printf("\n\t●○                                                        ●○");
		printf("\n\t○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●");
		WHITE
		printf("\n\n\n\t\t회원 저장하기를 종료합니다. \"ESC\"를 눌러주시기 바랍니다.");
		select = getch();
		if (select == 27)
			break;
		system("cls");
	}
}

void editUser()
{
	int select;
	int i = count, num;
	int idx = 0, result = 4;
	int n;
	char piece[40] ;
	char ID[15];
	char choice[40];

	while (1)
	{
		YELGREEN;
		printf("\n\n\t○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●");
		printf("\n\t●○                                                        ●○");
		printf("\n\t○●                   회원 편집하기                        ○●");
		printf("\n\t●○                                                        ●○");
		printf("\n\t○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●");
		printf("\n\n\n\n\t\t\t1번: ID로 검색하기\n\n\t\t\t2번: 이름으로 검색하기\n\n\t\t\t3번: 전화번호로 검색하기\n\n\t\t\tESC: 메뉴로 돌아가기");
		WHITE;
		if (result == 1)
		{
			gotoxy(20, 23);
			RED; printf("ERROR: ");
			WHITE; printf("해당 ID의 회원은 존재하지 않습니다.");
		}
		else if (result == 2)
		{
			gotoxy(20, 23);
			RED; printf("ERROR: ");
			WHITE; printf("해당 이름의 회원은 존재하지 않습니다.");
		}
		else if (result == 3)
		{
			gotoxy(20, 23);
			RED; printf("ERROR: ");
			WHITE; printf("해당 전화번호의 회원은 존재하지 않습니다.");
		}
		WHITE;
		select = getch();
		system("cls");
		switch (select)
		{
		case '1':
			YELGREEN;
			gotoxy(15, 7);
			printf("\n\n\t●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○");
			printf("\n\t○●                                                        ○●");
			printf("\n\t●○                  ID입력:                               ●○");
			printf("\n\t○●                                                        ○●");
			printf("\n\t●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○");
			gotoxy(39, 11);
			WHITE;
			fgets(ID,15,stdin);
			ID[(int)strlen(ID) - 1] = '\0';
			num = atoi(ID);
			fflush(stdin);
			for (i = 0; i < count; i++)
			{
				if (user[i].ID == num) 
					break;
			}
			if (i == count)
				result = 1;
			system("cls");
			break;
		case '2':
			idx = 0;
			system("cls");
			YELGREEN;
			gotoxy(15, 7);
			printf("\n\n\t●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○");
			printf("\n\t○●                                                        ○●");
			printf("\n\t●○                이름입력:                               ●○");
			printf("\n\t○●                                                        ○●");
			printf("\n\t●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○");
			gotoxy(39, 11);
			WHITE;
			fgets(choice,40,stdin);
			choice[(int)strlen(choice) - 1] = '\0';
			fflush(stdin);
			for (i = 0; i < count; i++)
			{
				if (strcmp(user[i].name, choice) == 0)
					piece[idx++] = i;
			}
			system("cls");
			if (idx == 0)
				result = 2;
			else
			{
				result = 0;
				idx = 0;
				while (1)
				{
					system("cls");
						n = 0;
						printf("\n");
						while (!strcmp(user[piece[n]].name, choice))
						{
							if (idx == n)
							{
								YELGREEN;
									printf("\n\t%d\t%s\t%-21s\t%s\n\n", user[piece[n]].ID, user[piece[n]].name, user[piece[n]].address, user[piece[n]].phone);
								WHITE;
							}
							else
							{
								WHITE;
								printf("\n\t%d\t%s\t%-21s\t%s\n\n", user[piece[n]].ID, user[piece[n]].name, user[piece[n]].address, user[piece[n]].phone);
							}
							n++;
						}
					gotoxy(20, 23);
					YELGREEN;
					printf("편집할 회원을 골라주십시오.");
					printf(" (Enter)");
					gotoxy(4, idx * 3 + 3);
					printf("▶");
					WHITE;
					n = getch();
					if (n == 80)
					{
						idx++;
						if (strcmp(user[piece[idx]].name, choice))
							idx--;
					}
					else if (n == 72)
					{
						idx--;
						if (idx < 0)
							idx = 0;
					}
					else if (n == 13)
					{
						i = piece[idx];
						break;
					}
				}
			}
			break;
		case '3':
			system("cls");
			YELGREEN;
			gotoxy(15, 7);
			printf("\n\n\t●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○");
			printf("\n\t○●                                                        ○●");
			printf("\n\t●○            전화번호입력:                               ●○");
			printf("\n\t○●                                                        ○●");
			printf("\n\t●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○");
			gotoxy(39, 11);
			WHITE;
			fgets(choice,40,stdin);
			choice[(int)strlen(choice) - 1] = '\0';
			fflush(stdin);
			for (i = 0; i < count; i++)
			{
				if (!strcmp(user[i].phone, choice))
					break;
			}
			system("cls");
			if (i == count)
				result = 3;
			break;
		case 27:
			return;
		}
		if (i != count)
			break;
		else if (i == count && result == 0)
			break;
	}
	system("cls");
	result = 0;
	while (1)
	{
		GREEN;
		printf("\n\n\t○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●");
		printf("\n\t●○                                                        ●○");
		printf("\n\t○●                                                        ○●");
		printf("\n\t●○                                                        ●○");
		printf("\n\t○●                                                        ○●");
		printf("\n\t●○                                                        ●○");
		printf("\n\t○●                                                        ○●");
		printf("\n\t●○                                                        ●○");
		printf("\n\t○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●");
		YELGREEN;
		gotoxy(20, 5);
		printf("ID: %d\t이름: %s",
			user[i].ID, user[i].name);
		gotoxy(20, 7);
		printf("전화번호: %s\n", user[i].phone);
		gotoxy(20, 9);
		printf("주소: %s\n\n", user[i].address);
		printf("\n\n\n\t\t\t1번: 이름 편집하기\n\n\t\t\t2번: 주소 편집하기\n\n\t\t\t3번: 전화번호 편집하기\n\n\t\t\tESC: 편집 끝내기");
		WHITE;
		select = getch();
		system("cls");
		if (select == '1')
		{
			while (1)
			{
				GREEN;
				printf("\n\n\t○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●");
				printf("\n\t●○                                                        ●○");
				printf("\n\t○●                                                        ○●");
				printf("\n\t●○                                                        ●○");
				printf("\n\t○●                                                        ○●");
				printf("\n\t●○                                                        ●○");
				printf("\n\t○●                                                        ○●");
				printf("\n\t●○                                                        ●○");
				printf("\n\t○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●");
				YELGREEN;
				gotoxy(20, 5);
				printf("ID: %d\t이름: %s",
					user[i].ID, user[i].name);
				gotoxy(20, 7);
				printf("전화번호: %s\n", user[i].phone);
				gotoxy(20, 9);
				printf("주소: %s\n\n", user[i].address);
				YELLOW;
				printf("\n\n\n\t\t\t편집할 이름 입력: ");
				WHITE;
				if (result == 1)
				{
					gotoxy(20, 23);
					RED;
					printf("ERROR: ");
					WHITE;
					printf("이름에 숫자나 공백은 들어갈 수 없습니다.");
				}
				else if (result == 2)
				{
					gotoxy(20, 23);
					RED;
					printf("ERROR: ");
					WHITE;
					printf("이름은 한글4자 영문8자까지 가능합니다.");
				}
				result = 0;
				gotoxy(43, 14);
				fgets(buffer, BUF, stdin);
				buffer[(int)strlen(buffer) - 1] = '\0';
				fflush(stdin);
				
				if (strlen(buffer) == 0)
					result = 1;
				else if (strlen(buffer)>8)
					result = 2;

				for (idx = 0; idx < (int)strlen(buffer); idx++)
				{
					if (buffer[idx] >= '0' && buffer[idx] <= '9' || buffer[idx] == ' ')
						result = 1;
				}

				system("cls");
				if (result == 0)
				{
					strcpy(user[i].name, buffer);
					break;
				}
			}
		}
		else if (select == '2')
		{
			while (1)
			{
				GREEN;
				printf("\n\n\t○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●");
				printf("\n\t●○                                                        ●○");
				printf("\n\t○●                                                        ○●");
				printf("\n\t●○                                                        ●○");
				printf("\n\t○●                                                        ○●");
				printf("\n\t●○                                                        ●○");
				printf("\n\t○●                                                        ○●");
				printf("\n\t●○                                                        ●○");
				printf("\n\t○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●");
				YELGREEN;
				gotoxy(20, 5);
				printf("ID: %d\t이름: %s",
					user[i].ID, user[i].name);
				gotoxy(20, 7);
				printf("전화번호: %s\n", user[i].phone);
				gotoxy(20, 9);
				printf("주소: %s\n\n", user[i].address);
				YELLOW;
				printf("\n\n\n\n\n\t\t\t편집할 주소 입력: ");
				if (result == -1)
				{
					gotoxy(20, 23);
					RED; printf("ERROR: ");
					WHITE; printf("주소를 작성해 주십시오.");
				}
				else if (result == -2)
				{
					gotoxy(20, 23);
					RED; printf("ERROR: ");
					WHITE; printf("주소가 너무 깁니다.");
				}
				gotoxy(43, 16);
				fgets(buffer, BUF, stdin);
				buffer[(int)strlen(buffer) - 1] = '\0';
				fflush(stdin);
				if (strlen(buffer) > 50)
					result = -2;
				else if (strlen(buffer) == 0 || buffer[0] == ' ')
					result = -1;
				else
				{
					strcpy(user[i].address, buffer);
					system("cls");
					break;
				}
				system("cls");
			}
		}
		else if (select == '3')
		{
			result = -1;
			while (1)
			{
				while (1)
				{
					GREEN;
					printf("\n\n\t○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●");
					printf("\n\t●○                                                        ●○");
					printf("\n\t○●                                                        ○●");
					printf("\n\t●○                                                        ●○");
					printf("\n\t○●                                                        ○●");
					printf("\n\t●○                                                        ●○");
					printf("\n\t○●                                                        ○●");
					printf("\n\t●○                                                        ●○");
					printf("\n\t○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●");
					YELGREEN;
					gotoxy(20, 5);
					printf("ID: %d\t이름: %s",
						user[i].ID, user[i].name);
					gotoxy(20, 7);
					printf("전화번호: %s\n", user[i].phone);
					gotoxy(20, 9);
					printf("주소: %s\n\n", user[i].address);
					YELLOW;
					printf("\n\n\n\n\n\n\n\t\t\t편집할 전화번호 입력: ");
					if (result == 1)
					{
						gotoxy(20, 23);
						RED; printf("ERROR: ");
						WHITE;	printf("전화번호의 형식은 \"01x-xxxx-xxxx\" 입니다.");
					}
					else if (result == 0)
					{
						gotoxy(20, 23);
						RED; printf("ERROR: ");
						WHITE; printf("이미 존재하는 전화번호 입니다.");
					}
					gotoxy(47, 18);
					fgets(buffer, BUF, stdin);
					buffer[(int)strlen(buffer) - 1] = '\0';
					fflush(stdin);
					system("cls");
					if (buffer[3] == '-' && buffer[8] == '-' &&strlen(buffer) == 13
						&& buffer[0] == 48 && buffer[1] == 49
						&& buffer[4] > 47 && buffer[4]<58
						&& buffer[5]>47 && buffer[5]<58
						&& buffer[6]>47 && buffer[6]<58
						&& buffer[7]>47 && buffer[7]<58
						&& buffer[9]>47 && buffer[9]<58
						&& buffer[10]>47 && buffer[10]<58
						&& buffer[11]>47 && buffer[11]<58
						&& buffer[12]>47 && buffer[12] < 58
						)
						break;
					else
						result = 1;
				}
				for (idx = 0; idx < count; idx++)
				{
					result = strcmp(user[idx].phone, buffer);
					if (result == 0)
						break;
				}
				system("cls");
				if (result != 0)
				{
					strcpy(user[i].phone, buffer);
					break;
				}
			}
		}
		if (select == 27)
		{
			for (idx = 0; idx < 10; idx++)
			{
				system("cls");
				gotoxy(20, 12);
				YELGREEN;
				printf("\n\n\t○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●");
				printf("\n\t●○                                                        ●○");
				printf("\n\t○●                                                        ○●");
				printf("\n\t●○                                                        ●○");
				printf("\n\t○●                                                        ○●");
				printf("\n\t●○                                                        ●○");
				printf("\n\t○●                                                        ○●");
				printf("\n\t●○                                                        ●○");
				printf("\n\t○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●");
				gotoxy(20, 16);
				printf("ID: %d\t이름: %s",
					user[i].ID, user[i].name);
				gotoxy(20, 18);
				printf("전화번호: %s\n", user[i].phone);
				gotoxy(20, 20);
				printf("주소: %s\n\n", user[i].address);
				gotoxy(20, 3);
				printf("\n\n\t●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○");
				printf("\n\t○●                                                        ○●");
				printf("\n\t●○                   회원 편집 완료                       ●○");
				printf("\n\t○●                                                        ○●");
				printf("\n\t●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○");
				Sleep(50);
				system("cls");
				gotoxy(20, 12);
				printf("\n\n\t○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●");
				printf("\n\t●○                                                        ●○");
				printf("\n\t○●                                                        ○●");
				printf("\n\t●○                                                        ●○");
				printf("\n\t○●                                                        ○●");
				printf("\n\t●○                                                        ●○");
				printf("\n\t○●                                                        ○●");
				printf("\n\t●○                                                        ●○");
				printf("\n\t○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●");
				gotoxy(20, 16);
				printf("ID: %d\t이름: %s",
					user[i].ID, user[i].name);
				gotoxy(20, 18);
				printf("전화번호: %s\n", user[i].phone);
				gotoxy(20, 20);
				printf("주소: %s\n\n", user[i].address);
				GREEN;
				gotoxy(20, 3);
				printf("\n\n\t○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●");
				printf("\n\t●○                                                        ●○");
				printf("\n\t○●                   회원 편집 완료                       ○●");
				printf("\n\t●○                                                        ●○");
				printf("\n\t○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●");
				Sleep(50);
			}
			while (1)
			{
				YELGREEN;
				system("cls");
				gotoxy(20, 12);
				printf("\n\n\t○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●");
				printf("\n\t●○                                                        ●○");
				printf("\n\t○●                                                        ○●");
				printf("\n\t●○                                                        ●○");
				printf("\n\t○●                                                        ○●");
				printf("\n\t●○                                                        ●○");
				printf("\n\t○●                                                        ○●");
				printf("\n\t●○                                                        ●○");
				printf("\n\t○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●");
				gotoxy(20, 16);
				printf("ID: %d\t이름: %s",
					user[i].ID, user[i].name);
				gotoxy(20, 18);
				printf("전화번호: %s\n", user[i].phone);
				gotoxy(20, 20);
				printf("주소: %s\n\n", user[i].address);
				gotoxy(20, 3);
				printf("\n\n\t○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●");
				printf("\n\t●○                                                        ●○");
				printf("\n\t○●                   회원 편집 완료                       ○●");
				printf("\n\t●○                                                        ●○");
				printf("\n\t○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●");
				WHITE;
				printf("\n\n\n\t\t회원 편집하기를 종료합니다. \"ESC\"를 눌러주시기 바랍니다.");
				select = getch();
				if (select == 27)
					break;
			}
			break;
		}
	}
}

void deleteUser()
{
	int select;
	int i = count, num;
	int idx = 0, result = 0;
	int n;
	char piece[40];
	char ID[15];
	char choice[40];

	while (1)
	{
		RED;
		printf("\n\n\t○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●");
		printf("\n\t●○                                                        ●○");
		printf("\n\t○●                   회원 삭제하기                        ○●");
		printf("\n\t●○                                                        ●○");
		printf("\n\t○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●");
		printf("\n\n\n\n\t\t\t1번: ID로 검색하기\n\n\t\t\t2번: 이름으로 검색하기\n\n\t\t\t3번: 전화번호로 검색하기\n\n\t\t\tESC: 메뉴로 돌아가기");
		WHITE;
		if (result == 1)
		{
			gotoxy(20, 23);
			RED; printf("ERROR: ");
			WHITE; printf("해당 ID의 회원은 존재하지 않습니다.");
		}
		else if (result == 2)
		{
			gotoxy(20, 23);
			RED; printf("ERROR: ");
			WHITE; printf("해당 이름의 회원은 존재하지 않습니다.");
		}
		else if (result == 3)
		{
			gotoxy(20, 23);
			RED; printf("ERROR: ");
			WHITE; printf("해당 전화번호의 회원은 존재하지 않습니다.");
		}
		RED;
		select = getch();
		system("cls");
		switch (select)
		{
		case '1':
			gotoxy(15, 7);
			printf("\n\n\t●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○");
			printf("\n\t○●                                                        ○●");
			printf("\n\t●○                  ID입력:                               ●○");
			printf("\n\t○●                                                        ○●");
			printf("\n\t●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○");
			WHITE;
			gotoxy(39, 11);
			fgets(ID, 15, stdin);
			ID[(int)strlen(ID) - 1] = '\0';
			num = atoi(ID);
			fflush(stdin);
			for (i = 0; i < count; i++)
			{
				if (user[i].ID == num)
					break;
			}
			if (i == count)
				result = 1;
			system("cls");
			break;
		case '2':
			idx = 0;
			system("cls");
			gotoxy(15, 7);
			printf("\n\n\t●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○");
			printf("\n\t○●                                                        ○●");
			printf("\n\t●○                이름입력:                               ●○");
			printf("\n\t○●                                                        ○●");
			printf("\n\t●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○");
			WHITE;
			gotoxy(39, 11);
			fgets(choice, 40, stdin);
			choice[(int)strlen(choice) - 1] = '\0';
			fflush(stdin);
			for (i = 0; i < count; i++)
			{
				if (strcmp(user[i].name, choice) == 0)
					piece[idx++] = i;
			}
			system("cls");
			if (idx == 0)
				result = 2;
			else
			{
				result = 0;
				idx = 0;
				while (1)
				{
					system("cls");
					n = 0;
					printf("\n");
					while (!strcmp(user[piece[n]].name, choice))
					{
						if (idx == n)
						{
							RED;
							printf("\n\t%d\t%s\t%-21s\t%s\n\n", user[piece[n]].ID, user[piece[n]].name, user[piece[n]].address, user[piece[n]].phone);
							WHITE;
						}
						else
						{
							WHITE;
							printf("\n\t%d\t%s\t%-21s\t%s\n\n", user[piece[n]].ID, user[piece[n]].name, user[piece[n]].address, user[piece[n]].phone);
						}
						n++;
					}
					gotoxy(20, 23);
					RED;
					printf("편집할 회원을 골라주십시오.");
					printf(" (Enter)");
					gotoxy(4, idx * 3 + 3);
					printf("▶");
					WHITE;
					n = getch();
					if (n == 80)
					{
						idx++;
						if (strcmp(user[piece[idx]].name, choice))
							idx--;
					}
					else if (n == 72)
					{
						idx--;
						if (idx < 0)
							idx = 0;
					}
					else if (n == 13)
					{
						i = piece[idx];
						break;
					}
				}
			}
				break;
		case '3':
			system("cls");
			gotoxy(15, 7);
			printf("\n\n\t●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○");
			printf("\n\t○●                                                        ○●");
			printf("\n\t●○            전화번호입력:                               ●○");
			printf("\n\t○●                                                        ○●");
			printf("\n\t●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○");
			gotoxy(39, 11);
			WHITE;
			fgets(choice, 40, stdin);
			choice[(int)strlen(choice) - 1] = '\0';
			fflush(stdin);
			for (i = 0; i < count; i++)
			{
				if (!strcmp(user[i].phone, choice))
					break;
			}
			system("cls");
			if (i == count)
				result = 3;
			break;
		case 27:
			return;
		default:
			result = 4;
			break;
			}
			if (i != count)
				break;
			else if (i == count && result == 0)
				break;
		}
		for (idx = 0; idx < 10; idx++)
		{
			system("cls");
			gotoxy(20, 12);
			RED;
			printf("\n\n\t○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●");
			printf("\n\t●○                                                        ●○");
			printf("\n\t○●                                                        ○●");
			printf("\n\t●○                                                        ●○");
			printf("\n\t○●                                                        ○●");
			printf("\n\t●○                                                        ●○");
			printf("\n\t○●                                                        ○●");
			printf("\n\t●○                                                        ●○");
			printf("\n\t○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●");
			gotoxy(20, 16);
			printf("ID: %d\t이름: %s",
				user[i].ID, user[i].name);
			gotoxy(20, 18);
			printf("전화번호: %s\n", user[i].phone);
			gotoxy(20, 20);
			printf("주소: %s\n\n", user[i].address);
			gotoxy(20, 3);
			printf("\n\n\t●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○");
			printf("\n\t○●                                                        ○●");
			printf("\n\t●○                   회원 삭제 완료                       ●○");
			printf("\n\t○●                                                        ○●");
			printf("\n\t●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○");
			Sleep(50);
			system("cls");
			gotoxy(20, 12);
			printf("\n\n\t○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●");
			printf("\n\t●○                                                        ●○");
			printf("\n\t○●                                                        ○●");
			printf("\n\t●○                                                        ●○");
			printf("\n\t○●                                                        ○●");
			printf("\n\t●○                                                        ●○");
			printf("\n\t○●                                                        ○●");
			printf("\n\t●○                                                        ●○");
			printf("\n\t○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●");
			gotoxy(20, 16);
			printf("ID: %d\t이름: %s",
				user[i].ID, user[i].name);
			gotoxy(20, 18);
			printf("전화번호: %s\n", user[i].phone);
			gotoxy(20, 20);
			printf("주소: %s\n\n", user[i].address);
			BLOOD;
			gotoxy(20, 3);
			printf("\n\n\t○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●");
			printf("\n\t●○                                                        ●○");
			printf("\n\t○●                   회원 삭제 완료                       ○●");
			printf("\n\t●○                                                        ●○");
			printf("\n\t○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●");
			Sleep(50);
		}
		while (1)
		{
			RED;
			system("cls");
			gotoxy(20, 12);
			printf("\n\n\t○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●");
			printf("\n\t●○                                                        ●○");
			printf("\n\t○●                                                        ○●");
			printf("\n\t●○                                                        ●○");
			printf("\n\t○●                                                        ○●");
			printf("\n\t●○                                                        ●○");
			printf("\n\t○●                                                        ○●");
			printf("\n\t●○                                                        ●○");
			printf("\n\t○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●");
			gotoxy(20, 16);
			printf("ID: %d\t이름: %s",
				user[i].ID, user[i].name);
			gotoxy(20, 18);
			printf("전화번호: %s\n", user[i].phone);
			gotoxy(20, 20);
			printf("주소: %s\n\n", user[i].address);
			gotoxy(20, 3);
			printf("\n\n\t○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●");
			printf("\n\t●○                                                        ●○");
			printf("\n\t○●                   회원 삭제 완료                       ○●");
			printf("\n\t●○                                                        ●○");
			printf("\n\t○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●");
			WHITE;
			printf("\n\n\n\t\t회원 삭제하기를 종료합니다. \"ESC\"를 눌러주시기 바랍니다.");
			if (getch() == 27)
				break;
		}
		user[i].ID = -1;
		strcpy(user[i].name, "*");
		strcpy(user[i].address, "*");
		strcpy(user[i].phone, "*");
	}

void searchUser()
{
	int select;
	int i = count, num, n;
	char piece[40];
	int idx = 0;
	char ID[15];
	char choice[40];
	int result = 4;

	while (1)
	{
		FLUORESCENT;
		printf("\n\n\t○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●");
		printf("\n\t●○                                                        ●○");
		printf("\n\t○●                   회원 검색하기                        ○●");
		printf("\n\t●○                                                        ●○");
		printf("\n\t○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●");
		printf("\n\n\n\n\t\t\t1번: ID로 검색하기\n\n\t\t\t2번: 이름으로 검색하기\n\n\t\t\t3번: 전화번호로 검색하기\n\n\t\t\tESC: 메뉴로 돌아가기");
		WHITE;
		if (result == 1)
		{
			gotoxy(20, 23);
			RED; printf("ERROR: ");
			WHITE; printf("해당 ID의 회원은 존재하지 않습니다.");
		}
		else if (result == 2)
		{
			gotoxy(20, 23);
			RED; printf("ERROR: ");
			WHITE; printf("해당 이름의 회원은 존재하지 않습니다.");
		}
		else if (result == 3)
		{
			gotoxy(20, 23);
			RED; printf("ERROR: ");
			WHITE; printf("해당 전화번호의 회원은 존재하지 않습니다.");
		}
		select = getch();
		system("cls");
		FLUORESCENT;
		switch (select)
		{
		case '1':
			system("cls");
			gotoxy(15, 7);
			printf("\n\n\t●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○");
			printf("\n\t○●                                                        ○●");
			printf("\n\t●○                  ID입력:                               ●○");
			printf("\n\t○●                                                        ○●");
			printf("\n\t●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○");
			WHITE;
			gotoxy(39, 11);
			fgets(ID, 15, stdin);
			ID[(int)strlen(ID) - 1] = '\0';
			num = atoi(ID);
			fflush(stdin);
			for (i = 0; i < count; i++)
			{
				if (user[i].ID == num)
				{
					result = 0;
					break;
				}
			}
			if (i == count)
				result = 1;
			system("cls");

			break;
		case '2':
			idx = 0;
			system("cls");
			gotoxy(15, 7);
			printf("\n\n\t●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○");
			printf("\n\t○●                                                        ○●");
			printf("\n\t●○                이름입력:                               ●○");
			printf("\n\t○●                                                        ○●");
			printf("\n\t●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○");
			WHITE;
			gotoxy(39, 11);
			fgets(choice, 40, stdin);
			choice[(int)strlen(choice) - 1] = '\0';
			fflush(stdin);
			for (i = 0; i < count; i++)
			{
				if (!strcmp(user[i].name, choice))
				{
					result = 4;
					piece[idx] = i;
					idx++;
				}
			}
			if (idx == 0)
				result = 2;
			else
			{
				result = 0;
				idx = 0;
				while (1)
				{
					system("cls");
					n = 0;
					printf("\n");
					while (!strcmp(user[piece[n]].name, choice))
					{
						if (idx == n)
						{
							FLUORESCENT;
							printf("\n\t%d\t%s\t%-21s\t%s\n\n", user[piece[n]].ID, user[piece[n]].name, user[piece[n]].address, user[piece[n]].phone);
							WHITE;
						}
						else
						{
							WHITE;
							printf("\n\t%d\t%s\t%-21s\t%s\n\n", user[piece[n]].ID, user[piece[n]].name, user[piece[n]].address, user[piece[n]].phone);
						}
						n++;
					}
					gotoxy(20, 23);
					FLUORESCENT;
					printf("검색할 회원을 골라주십시오.");
					printf(" (Enter)");
					gotoxy(4, idx * 3 + 3);
					printf("▶");
					WHITE;
					n = getch();
					if (n == 80)
					{
						idx++;
						if (strcmp(user[piece[idx]].name, choice))
							idx--;
					}
					else if (n == 72)
					{
						idx--;
						if (idx < 0)
							idx = 0;
					}
					else if (n == 13)
					{
						i = piece[idx];
						break;
					}
				}
			}
			system("cls");
			break;
		case '3':
			system("cls");
			gotoxy(15, 7);
			printf("\n\n\t●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○");
			printf("\n\t○●                                                        ○●");
			printf("\n\t●○            전화번호입력:                               ●○");
			printf("\n\t○●                                                        ○●");
			printf("\n\t●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○");
			gotoxy(39, 11);
			WHITE;
			fgets(choice, 40, stdin);
			choice[(int)strlen(choice) - 1] = '\0';
			fflush(stdin);
			for (i = 0; i < count; i++)
			{
				if (!strcmp(user[i].phone, choice))
				{
					result = 0;
					break;
				}
			}
			if (i == count)
				result = 3;
			system("cls");
			break;
		}
		if (result == 0)
			break;
		else if (select == 27)
			return;
	}
	for (idx = 0; idx < 10; idx++)
	{
		system("cls");
		gotoxy(20, 12);
		FLUORESCENT;
		printf("\n\n\t○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●");
		printf("\n\t●○                                                        ●○");
		printf("\n\t○●                                                        ○●");
		printf("\n\t●○                                                        ●○");
		printf("\n\t○●                                                        ○●");
		printf("\n\t●○                                                        ●○");
		printf("\n\t○●                                                        ○●");
		printf("\n\t●○                                                        ●○");
		printf("\n\t○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●");
		gotoxy(20, 16);
		printf("ID: %d\t이름: %s",
			user[i].ID, user[i].name);
		gotoxy(20, 18);
		printf("전화번호: %s\n", user[i].phone);
		gotoxy(20, 20);
		printf("주소: %s\n\n", user[i].address);
		gotoxy(20, 3);
		printf("\n\n\t●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○");
		printf("\n\t○●                                                        ○●");
		printf("\n\t●○                   회원 검색 완료                       ●○");
		printf("\n\t○●                                                        ○●");
		printf("\n\t●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○");
		Sleep(50);
		system("cls");
		gotoxy(20, 12);
		printf("\n\n\t○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●");
		printf("\n\t●○                                                        ●○");
		printf("\n\t○●                                                        ○●");
		printf("\n\t●○                                                        ●○");
		printf("\n\t○●                                                        ○●");
		printf("\n\t●○                                                        ●○");
		printf("\n\t○●                                                        ○●");
		printf("\n\t●○                                                        ●○");
		printf("\n\t○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●");
		gotoxy(20, 16);
		printf("ID: %d\t이름: %s",
			user[i].ID, user[i].name);
		gotoxy(20, 18);
		printf("전화번호: %s\n", user[i].phone);
		gotoxy(20, 20);
		printf("주소: %s\n\n", user[i].address);
		WINE;
		gotoxy(20, 3);
		printf("\n\n\t○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●");
		printf("\n\t●○                                                        ●○");
		printf("\n\t○●                   회원 검색 완료                       ○●");
		printf("\n\t●○                                                        ●○");
		printf("\n\t○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●");
		Sleep(50);
	}
	while (1)
	{
		FLUORESCENT;
		system("cls");
		gotoxy(20, 12);
		printf("\n\n\t○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●");
		printf("\n\t●○                                                        ●○");
		printf("\n\t○●                                                        ○●");
		printf("\n\t●○                                                        ●○");
		printf("\n\t○●                                                        ○●");
		printf("\n\t●○                                                        ●○");
		printf("\n\t○●                                                        ○●");
		printf("\n\t●○                                                        ●○");
		printf("\n\t○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●");
		gotoxy(20, 16);
		printf("ID: %d\t이름: %s",
			user[i].ID, user[i].name);
		gotoxy(20, 18);
		printf("전화번호: %s\n", user[i].phone);
		gotoxy(20, 20);
		printf("주소: %s\n\n", user[i].address);
		gotoxy(20, 3);
		printf("\n\n\t○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●");
		printf("\n\t●○                                                        ●○");
		printf("\n\t○●                   회원 검색 완료                       ○●");
		printf("\n\t●○                                                        ●○");
		printf("\n\t○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●○●");
		WHITE;
		printf("\n\n\n\t\t회원 검색하기를 종료합니다. \"ESC\"를 눌러주시기 바랍니다.");
		if (getch() == 27)
			break;
	}
}