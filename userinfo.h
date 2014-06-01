#ifndef __USERINFO_H__
#define __USERINFO_H__

typedef struct user{
	int ID;
	char name[20];
	char address[40];
	char phone[20];
}user_t;

void insertUser();
void printUser();
void saveUser();

#endif
