#ifndef USER_H
#define USER_H

#define MAX_LEN 100

typedef struct {
  char name[MAX_LEN];
  char password[MAX_LEN];
  int money;
} User;

User createUser(char *nama, char *pw, int uang);

#endif