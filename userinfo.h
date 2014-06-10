#ifndef __USERINFO_H__
#define __USERINFO_H__

#define col GetStdHandle(STD_OUTPUT_HANDLE)
#define RED SetConsoleTextAttribute(col,0x000c);
#define BLUE SetConsoleTextAttribute(col,0x001 | 0x0008);
#define YELGREEN SetConsoleTextAttribute(col,0x00a);
#define WHITE SetConsoleTextAttribute(col,0x000f);
#define SKY SetConsoleTextAttribute(col,0x000b);
#define YELLOW SetConsoleTextAttribute(col,0x000e);
#define FLUORESCENT SetConsoleTextAttribute(col,0x000d);
#define GOLD SetConsoleTextAttribute(col,0x0006);
#define WINE SetConsoleTextAttribute(col,0x0005);
#define BLOOD SetConsoleTextAttribute(col,0x0004);
#define GREEN SetConsoleTextAttribute(col,0x0002);
#define VIOLET SetConsoleTextAttribute(col,0x0001 | 0x0008 | 0x000c);

typedef struct user{
	int ID;
	char name[21];
	char address[51];
	char phone[14];
}user_t;

void insertUser();
void printUser();
void saveUser();
void editUser();
void deleteUser();
void searchUser();

#endif