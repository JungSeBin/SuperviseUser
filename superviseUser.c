#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <Windows.h>
#include "userInfo.h"
#pragma warning(disable:4996)

#define MAX 11
user_t user[100];
int count = 0;
int ID;

int main(void)
{
	int i;
	int select;
	char password[30];
	char answer[30] = "1";
	char list[255];
	char *str;
	FILE *fp = fopen("data.txt", "r");
	if (fp == NULL) return -1;
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
	//while (1)
	//{
	//	printf("\n\n\n\t\t\t힌트을 보시고 싶으면 \"힌트\"을 적으십시오");
	//	if (!strcmp(password, "힌트"))
	//		printf("\n\n\n\t\t\t힌트: ○○○ 교수님 사랑합니다");
	//	printf("\n\n\n\n\n\n\n\n\t비밀번호를 입력하십시오: ");
	//	gets(password);
	//	if (!strcmp(password, answer))
	//		break;
	//	else
	//		system("cls");
	//}
	while (1)
	{
		system("cls");
		printf("\n\n1번: 회원 목록보기\n\n2번: 회원 등록하기\n\n3번: 회원 저장하기\n\n4번: 회원 수정하기\n\n6번: 회원 검색하기\n\nESC: 종료하기");
		printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tThanks to.덕성킴,남세");
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
			case '6':
				system("cls");
				searchUser();
				break;
			}
			if (select == '1' || select == '2' || select == '3' || select == '4'
				||select == '6')
				break;
			else if (select == 27)
			{
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
	printf("\n\n회원 관리 프로그램이 종료되었습니다.\n\n");
}

void printUser()
{
	int idx;
	int page = 0;
	int move;

	while (1)
	{
		idx = page * MAX;
		printf("ID\t");
		printf("Name\t");
		printf("Address\t\t\t");
		printf("Phone Number\n");
		for (; idx < (page + 1) * MAX; idx++)
		{
			if (user[idx].ID == 0)
				printf(" \t%s\t%-21s\t%s\n\n",user[idx].name, user[idx].address, user[idx].phone);
			else
				printf("%d\t%s\t%-21s\t%s\n\n", user[idx].ID, user[idx].name, user[idx].address, user[idx].phone);
		}
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
	int i, result;
	int select;
	user[count].ID = ++ID;
	printf("\n\nID: %d\n\n", user[count].ID);
	system("cls");
	while (1)
	{
		printf("\n\nID: %d\n\n", user[count].ID);
		result = 0;
		printf("Name: ");
		gets(user[count].name);
		for (i = 0; i < (int)strlen(user[count].name); i++)
		{
			if ((user[count].name)[i] >= '0' && (user[count].name)[i] <= '9' || (user[count].name)[i] == ' ')
			{
				result++;
			}
		}
		if (strlen(user[count].name) == 0)
			result++;
		printf("\n");
		if (result == 0)
			break;
		system("cls");
		printf("\n\nERROR: Please input only Letters in Name");
	}
	system("cls");
	while (1)
	{
		printf("\n\nID: %d", user[count].ID);
		printf("\n\nName: %s\n\n", user[count].name);
		printf("Address: ");
		gets(user[count].address);
		printf("\n");
		if (strlen(user[count].address) != 0 && (user[count].address)[0] != ' ')
			break;
		system("cls");
		printf("\n\nERROR: Address is empty");
	}
	system("cls");
	while (1)
	{
		while (1)
		{
			printf("\n\nID: %d", user[count].ID);
			printf("\n\nName: %s\n\n", user[count].name);
			printf("Address: %s\n\n", user[count].address);
			printf("Phone Number: ");
			gets(user[count].phone);
			if ((user[count].phone)[3] == '-' && (user[count].phone)[8] == '-' &&strlen(user[count].phone) == 13
				&& (user[count].phone)[0] == 48 && (user[count].phone)[1] == 49
				&& (user[count].phone)[4] > 47 && (user[count].phone)[4]<58
				&& (user[count].phone)[5]>47 && (user[count].phone)[5]<58
				&& (user[count].phone)[6]>47 && (user[count].phone)[6]<58
				&& (user[count].phone)[7]>47 && (user[count].phone)[7]<58
				&& (user[count].phone)[9]>47 && (user[count].phone)[9]<586
				&& (user[count].phone)[10]>47 && (user[count].phone)[10]<58
				&& (user[count].phone)[11]>47 && (user[count].phone)[11]<58
				&& (user[count].phone)[12]>47 && (user[count].phone)[12] < 58
				)
				break;
			else
			{
				system("cls");
				printf("\nError: Phone Number is \"01x-xxxx-xxxx\"\n\n");
			}
		}
		for (i = 0; i < count; i++)
		{
			result = strcmp(user[i].phone, user[count].phone);
			if (result == 0)
				break;
		}
		if (result != 0)
			break;
		system("cls");
		printf("\nERROR: This Phone Number already exists!!\n\n");
	}
	system("cls");
	printf("\n\nID: %d\tName: %s\tPhone Number: %s\n\nAddress: %s\t\n\n다음과 같은 정보로 회원이 등록되었습니다.\n\n",
		user[count].ID, user[count].name, user[count].phone, user[count].address);
	count++;
	while (1)
	{
		printf("\n\n\n\t\t메뉴로 돌아가시려면 \"ESC\"를 눌러주시기 바랍니다.");
		select = getch();
		if (select == 27)
			break;
		system("cls");
	}
}


void saveUser()
{
	FILE *fp = fopen("data.txt","w");
	int idx;
	int select;

	fprintf(fp, "ID\tName\tAddress\t\t\tPhone Number");
	for (idx = 0; idx < count; idx++)
	{
		fprintf(fp,"\n%d\t%s\t%-21s\t%s", user[idx].ID, user[idx].name, user[idx].address, user[idx].phone);
	}
	fclose(fp);
	printf("\n\n최신 회원 정보가 성공적으로 저장되었습니다.\n\n");
	while (1)
	{
		printf("\n\n\n\t\t메뉴로 돌아가시려면 \"ESC\"를 눌러주시기 바랍니다.");
		select = getch();
		if (select == 27)
			break;
		system("cls");
	}
}

void editUser()
{

}

void searchUser()
{
	int select;
	int i, num;
	char choice[20];

	while (1)
	{
		printf("\n\n1번: ID로 검색하기\n\n2번: 이름으로 검색하기\n\n3번: 전화번호로 검색하기\n\nESC: 메뉴로 돌아가기");
		select = getch();
		system("cls");
		switch (select)
		{
		case '1':
			system("cls");
			printf("\n\nID입력: ");
			scanf("%d", &num);
			for (i = 0; i < count; i++)
			{
				if (user[i].ID == num)
					break;
			}
			system("cls");
			if (i != count)
				printf("\n\n찾으신 회원:\n\nID: %d\tName: %s\tPhone Number: %s\n\nAddress: %s\n\n",
				user[i].ID, user[i].name, user[i].phone, user[i].address);
			else
				printf("\n\n\n\t\t해당 ID의 회원은 존재하지 않습니다.");
			break;
		case '2':
			system("cls");
			printf("\n\n이름입력: ");
			gets(choice);
			for (i = 0; i < count; i++)
			{
				if (!strcmp(user[i].name, choice))
					break;
			}
			system("cls");
			if (i != count)
				printf("\n\n찾으신 회원:\n\nID: %d\tName: %s\tPhone Number: %s\n\nAddress: %s\n\n",
				user[i].ID, user[i].name, user[i].phone, user[i].address);
			else
				printf("\n\n\n\t\t해당 이름의 회원은 존재하지 않습니다.");
			break;
		case '3':
			system("cls");
			printf("\n\n전화번호입력: ");
			gets(choice);
			for (i = 0; i < count; i++)
			{
				if (!strcmp(user[i].phone, choice))
					break;
			}
			system("cls");
			if (i != count)
				printf("\n\n찾으신 회원:\n\nID: %d\tName: %s\tPhone Number: %s\n\nAddress: %s\n\n",
				user[i].ID, user[i].name, user[i].phone, user[i].address);
			else
				printf("\n\n\n\t\t해당 전화번호의 회원은 존재하지 않습니다.");
			break;
		}
		if (select == 27)
			break;
	}
}

