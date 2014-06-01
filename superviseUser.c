#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <Windows.h>
#include "userInfo.h"


#define MAX 11
#pragma warning(disable:4996)
user_t user[100];
int count = 0;



int main(void)
{
	int i;
	int ID;
	int select;
	char list[255];
	char *str;
	FILE *fp = fopen("data.txt", "r");

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
		system("cls");
		printf("\n\n1번: 회원 목록보기\n\n2번: 회원 등록하기\n\n3번: 회원 저장하기\n\nESC: 종료하기\n");
		printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tThanks to.덕성킴,남세");
		while (1)
		{
			select = getch();
			switch (select)
			{
			case 49:
				system("cls");
				printUser();
				break;
			case 50:
				system("cls");
				insertUser(ID);
				break;
			case 51:
				system("cls");
				saveUser();
				break;
			}
			if (select == 49 || select == 50 || select == 51)
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
		while (1)
		{
			printf("메뉴로 돌아가시려면 \"Enter\"를 눌러주시기 바랍니다.\n");
			select = getch();

			if (select == 13)
			{
				system("cls");
				break;
			}
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
		printf("메뉴로 돌아가시려면 \"Enter\"를 2번 눌러주시기 바랍니다.  ◀ page:%d ▶",page);
		move = getch();
		if (move == 77)
			page++;
		else if (move == 75)
			page--;
		else if (move == 13)
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

void insertUser(int ID)
{
	int i, result;
	user[count].ID = ++ID;
	printf("ID: %d\n\n", user[count].ID);
	while (1)
	{
		result = 0;
		printf("Name: ");
		gets(user[count].name);
		for (i = 0; i < strlen(user[count].name); i++)
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
		printf("ERROR: Please input only Letters in Name\n\n");
	}
	while (1)
	{
		printf("Address: ");
		gets(user[count].address);
		printf("\n");
		if (strlen(user[count].address) != 0 && (user[count].address)[0] != ' ')
			break;
		printf("ERROR: Address is empty\n\n");
	}
	while (1)
	{
		while (1)
		{
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
				printf("\nError: Phone Number is \"01x - xxxx - xxxx\"\n\n");
		}
		for (i = 0; i < count; i++)
		{
			result = strcmp(user[i].phone, user[count].phone);
			if (result == 0)
				break;
		}
		if (result != 0)
			break;
		printf("\nERROR: This Phone Number already exists!!\n\n");
	}
	system("cls");
	printf("ID: %d\tName: %s\tPhone Number: %s\n\nAddress: %s\t\n\n다음과 같은 정보로 회원이 등록되었습니다.\n\n",
		user[count].ID, user[count].name, user[count].phone, user[count].address);
	count++;
}


void saveUser()
{
	FILE *fp = fopen("data.txt","w");
	int idx;

	fprintf(fp, "ID\tName\tAddress\t\t\tPhone Number");
	for (idx = 0; idx < count; idx++)
	{
		fprintf(fp,"\n%d\t%s\t%-21s\t%s", user[idx].ID, user[idx].name, user[idx].address, user[idx].phone);
	}
	fclose(fp);
	printf("\n\n최신 회원 정보가 성공적으로 저장되었습니다.\n\n");
}

