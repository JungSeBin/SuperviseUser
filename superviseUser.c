#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <Windows.h>
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
	//char password[30];
	//char answer[30] = "1";
	char list[255];
	char *str;
	FILE *fp = fopen("data.txt", "r");
	if (fp == NULL)
	{
		printf("\n\n\n\t\t\tERROR: ������ �������� �ʽ��ϴ�.\n\n\n");
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
	//while (1)
	//{
	//	printf("\n\n\n\t\t\t��Ʈ�� ���ð� ������ \"��Ʈ\"�� �����ʽÿ�");
	//	if (!strcmp(password, "��Ʈ"))
	//		printf("\n\n\n\t\t\t��Ʈ: �ۡۡ� ������ ����մϴ�");
	//	printf("\n\n\n\n\n\n\n\n\t��й�ȣ�� �Է��Ͻʽÿ�: ");
	//	gets(password);
	//	if (!strcmp(password, answer))
	//		break;
	//	else
	//		system("cls");
	//}
	while (1)
	{
		system("cls");
		printf("\n\n1��: ȸ�� ��Ϻ���\n\n2��: ȸ�� ����ϱ�\n\n3��: ȸ�� �����ϱ�\n\n4��: ȸ�� �����ϱ�\n\n6��: ȸ�� �˻��ϱ�\n\nESC: �����ϱ�");
		printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tThanks to.����Ŵ,����");

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
	printf("\n\nȸ�� ���� ���α׷��� ����Ǿ����ϴ�.\n\n");

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
		printf("�޴��� ���ư��÷��� \"ESC\"�� �����ֽñ� �ٶ��ϴ�.  �� page:%d ��",page);
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
		printf("\n\nID: %d\n\n", user[count].ID);
		printf("Name: ");
		if (result == 1)
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\tERROR: �̸��� ���ڳ� ������ �� �� �����ϴ�.");
		else if (result == 2)
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\tERROR: �̸��� �ѱ�10�� ����20�ڱ��� �����մϴ�.");
		gotoxy(7, 5);
		result = 0;
		fgets(buffer,BUF,stdin);
		buffer[(int)strlen(buffer) - 1] = '\0';

		if (strlen(buffer) == 0)
			result = 1;
		else if (strlen(buffer) > 20)
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
		printf("\n\nID: %d", user[count].ID);
		printf("\n\nName: %s\n\n", user[count].name);
		printf("Address: ");
		if (result == -1)
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\tERROR: �ּҸ� �Է��� �ֽʽÿ�.");
		else if (result == -2)
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\tERROR: �ּҰ� �ʹ� ��ϴ�.");
		gotoxy(10, 7);
		fgets(buffer, BUF, stdin);
		buffer[(int)strlen(buffer) - 1] = '\0';
		
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
			printf("\n\nID: %d", user[count].ID);
			printf("\n\nName: %s\n\n", user[count].name);
			printf("Address: %s\n\n", user[count].address);
			printf("Phone Number: ");
			if (result == 1)
				printf("\n\n\n\n\n\n\n\n\n\n\n\t\t��ȭ��ȣ�� ������ \"01x-xxxx-xxxx\" �Դϴ�.");
			else if (result == 0)
				printf("\n\n\n\n\n\n\n\n\n\n\n\t\t    ERROR: �̹� �����ϴ� ��ȭ��ȣ �Դϴ�.\n\n");
			gotoxy(15, 9);
			fgets(buffer, BUF, stdin);
			buffer[(int)strlen(buffer) - 1] = '\0';
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
	printf("\n\nID: %d\tName: %s\tPhone Number: %s\n\nAddress: %s\t\n\n������ ���� ������ ȸ���� ��ϵǾ����ϴ�.\n\n",
		user[count].ID, user[count].name, user[count].phone, user[count].address);
	count++;
	while (1)
	{
		printf("\n\n\n\t\t�޴��� ���ư��÷��� \"ESC\"�� �����ֽñ� �ٶ��ϴ�.");
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
	printf("\n\n�ֽ� ȸ�� ������ ���������� ����Ǿ����ϴ�.\n\n");
	while (1)
	{
		printf("\n\n\n\t\t�޴��� ���ư��÷��� \"ESC\"�� �����ֽñ� �ٶ��ϴ�.");
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
	int idx, result = 0;
	char ID[15];
	char choice[40];

	while (1)
	{
		printf("\n\n1��: ID�� �˻��ϱ�\n\n2��: �̸����� �˻��ϱ�\n\n3��: ��ȭ��ȣ�� �˻��ϱ�\n\nESC: �޴��� ���ư���");
		if (result == 1)
			printf("\n\n\n\n\n\n\n\n\n\n\n\t\tERROR: �ش� ID�� ȸ���� �������� �ʽ��ϴ�.");
		else if (result == 2)
			printf("\n\n\n\n\n\n\n\n\n\n\n\t\tERROR: �ش� �̸��� ȸ���� �������� �ʽ��ϴ�.");
		else if (result == 3)
			printf("\n\n\n\n\n\n\n\n\n\n\n\t\tERROR: �ش� ��ȭ��ȣ�� ȸ���� �������� �ʽ��ϴ�.");

		select = getch();
		system("cls");
		switch (select)
		{
		case '1':
			printf("\n\nID�Է�: ");
			gets(ID);
			num = atoi(ID);
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
			system("cls");
			printf("\n\n�̸��Է�: ");
			gets(choice);
			for (i = 0; i < count; i++)
			{
				if (!strcmp(user[i].name, choice))
					break;
			}
			system("cls");
			if (i == count)
				result = 2;
			break;
		case '3':
			system("cls");
			printf("\n\n��ȭ��ȣ�Է�: ");
			gets(choice);
			for (i = 0; i < count; i++)
			{
				if (!strcmp(user[i].phone, choice))
					break;
			}
			system("cls");
			if (i == count)
				result = 3;
			break;
		}
		if (i != count)
			break;
		if (select == 27)
			return;
		
	}
	system("cls");
	result = 0;
	while (1)
	{
		printf("\n\n������ ȸ��:\n\nID: %d\tName: %s\tPhone Number: %s\n\nAddress: %s\n\n",
			user[i].ID, user[i].name, user[i].phone, user[i].address);
		printf("\n1��: �̸� �����ϱ�\n\n2��: �ּ� �����ϱ�\n\n3��: ��ȭ��ȣ �����ϱ�\n\nESC: ���� ������");
		select = getch();
		system("cls");
		if (select == '1')
		{
			while (1)
			{
				printf("\n\n\n������ �̸� �Է�: ");
				if (result == 1)
					printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\tERROR: �̸��� ���ڳ� ������ �� �� �����ϴ�.");
				else if (result == 2)
					printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\tERROR: �̸��� �ѱ�10�� ����20�ڱ��� �����մϴ�.");
				gotoxy(19, 4);
				result = 0;
				fgets(buffer, BUF, stdin);
				buffer[(int)strlen(buffer) - 1] = '\0';
				
				if (strlen(buffer) == 0)
					result = 1;
				else if (strlen(buffer)>20)
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
				printf("\n\n\n������ �ּ� �Է�: ");
				if (result == -1)
					printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\tERROR: �ּҸ� �ۼ��� �ֽʽÿ�.");
				else if (result == -2)
					printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\tERROR: �ּҰ� �ʹ� ��ϴ�.");
				gotoxy(19, 4);
				fgets(buffer, BUF, stdin);
				buffer[(int)strlen(buffer) - 1] = '\0';
				if (strlen(buffer) > 50)
					result = -2;
				else if (strlen(buffer) == 0 || buffer[0] == ' ')
					result = -1;
				else
				{
					strcpy(user[i].address, buffer);
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
					system("cls");
					printf("\n\n\n������ ��ȭ��ȣ �Է�: ");
					if (result == 1)
						printf("\n\n\n\n\n\n\n\n\n\n\n\t\t��ȭ��ȣ�� ������ \"01x-xxxx-xxxx\" �Դϴ�.");
					else if (result == 0)
						printf("\n\n\n\n\n\n\n\n\n\n\n\t\t    ERROR: �̹� �����ϴ� ��ȭ��ȣ �Դϴ�.\n\n");
					gotoxy(22, 4);
					fgets(buffer, BUF, stdin);
					buffer[(int)strlen(buffer) - 1] = '\0';
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
			break;
	}
}

void searchUser()
{
	int select;
	int i = count, num;
	char choice[40];
	int result = 0;

	while (1)
	{
		if (i != count)
			printf("\n\nã���� ȸ��:\n\nID: %d\tName: %s\tPhone Number: %s\n\nAddress: %s\n\n",
			user[i].ID, user[i].name, user[i].phone, user[i].address);

		printf("\n\n1��: ID�� �˻��ϱ�\n\n2��: �̸����� �˻��ϱ�\n\n3��: ��ȭ��ȣ�� �˻��ϱ�\n\nESC: �޴��� ���ư���");
		if (result == 1)
			printf("\n\n\n\n\n\n\n\n\n\n\n\t\tERROR: �ش� ID�� ȸ���� �������� �ʽ��ϴ�.");
		else if (result == 2)
			printf("\n\n\n\n\n\n\n\n\n\n\n\t\tERROR: �ش� �̸��� ȸ���� �������� �ʽ��ϴ�.");
		else if (result == 3)
			printf("\n\n\n\n\n\n\n\n\n\n\n\t\tERROR: �ش� ��ȭ��ȣ�� ȸ���� �������� �ʽ��ϴ�.");
		select = getch();
		system("cls");
		switch (select)
		{
		case '1':
			system("cls");
			printf("\n\nID�Է�: ");
			scanf("%d", &num);
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
			system("cls");
			printf("\n\n�̸��Է�: ");
			gets(choice);
			for (i = 0; i < count; i++)
			{
				if (!strcmp(user[i].name, choice))
				{
					result = 0;
					break;
				}
			}
			if (i == count)
				result = 1;
			system("cls");
				
			break;
		case '3':
			system("cls");
			printf("\n\n��ȭ��ȣ�Է�: ");
			gets(choice);
			for (i = 0; i < count; i++)
			{
				if (!strcmp(user[i].phone, choice))
				{
					result = 0;
					break;
				}
			}
			if (i == count)
				result = 1;
			system("cls");
			break;
		}
		if (select == 27)
			break;
	}
}
