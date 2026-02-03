#ifndef DATATYPE_H
#define DATATYPE_H

#include <stdbool.h>

#define MAX_TITLE 100
#define MAX_AUTHOR 100
#define MAX_NAME 100
#define MAX_ID 20

// Cấu trúc Sách
typedef struct {
    char id[MAX_ID];
    char title[MAX_TITLE];
    char author[MAX_AUTHOR];
    bool is_borrowed; // true: đã mượn, false: còn trong kho
} Book;

// Cấu trúc Người dùng
typedef struct {
    char id[MAX_ID];
    char name[MAX_NAME];
    char borrowed_books[MAX_BORROW][MAX_ID]; // Danh sách ID sách đang mượn
    int borrow_count; // Số lượng sách đang mượn
} User;

#endif
