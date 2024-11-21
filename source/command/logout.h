#include <stdio.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_LEN 100

typedef struct {
    char username[MAX_LEN];
    char password[MAX_LEN];
    int money;
} User;

typedef struct {
    User users[MAX_USERS];
    int count;
} UserList;

UserList userList;
int currentUserIndex = -1;

void logoutUser(char username[MAX_LEN], char password[MAX_LEN]);