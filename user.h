#ifndef USER_H
#define USER_H

#include "datatype.h"

// Khai báo hàm
void displayUsers(User users[], int n);
void addUser(User users[], int *n);
void borrowBook(User users[], int nUser, Book books[], int nBook);
void returnBook(User users[], int nUser, Book books[], int nBook);

#endif
