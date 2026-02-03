#ifndef BOOK_H
#define BOOK_H

#include "datatype.h"

// Khai báo các hàm quản lý sách
void showBookMenu(Book books[], int *n);
void displayBooks(Book books[], int n);
void addBook(Book books[], int *n);
void editBook(Book books[], int n);
void deleteBook(Book books[], int *n);
void searchBook(Book books[], int n);
int findBookIndexById(Book books[], int n, char *id);

#endif
