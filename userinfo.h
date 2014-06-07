#ifndef __USERINFO_H__
#define __USERINFO_H__

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