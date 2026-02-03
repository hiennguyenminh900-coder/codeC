#include <stdio.h>
#include <string.h>
#include "user.h"
#include "book.h" // Cần để dùng hàm tìm sách

void displayUsers(User users[], int n) {
    printf("\n--- DANH SACH NGUOI DUNG ---\n");
    for (int i = 0; i < n; i++) {
        printf("ID: %s | Ten: %s | Dang muon: %d cuon\n", 
            users[i].id, users[i].name, users[i].borrow_count);
    }
}

void addUser(User users[], int *n) {
    printf("Nhap ID nguoi dung: ");
    scanf("%s", users[*n].id);
    getchar();
    printf("Nhap ten nguoi dung: ");
    fgets(users[*n].name, MAX_NAME, stdin);
    users[*n].name[strcspn(users[*n].name, "\n")] = 0;
    
    users[*n].borrow_count = 0;
    (*n)++;
    printf("Them nguoi dung thanh cong!\n");
}

void borrowBook(User users[], int nUser, Book books[], int nBook) {
    char userId[MAX_ID], bookId[MAX_ID];
    printf("Nhap ID nguoi muon: ");
    scanf("%s", userId);
    
    // Tìm người dùng
    int uIdx = -1;
    for (int i = 0; i < nUser; i++) {
        if (strcmp(users[i].id, userId) == 0) uIdx = i;
    }
    if (uIdx == -1) { printf("Khong tim thay nguoi dung!\n"); return; }
    
    if (users[uIdx].borrow_count >= MAX_BORROW) {
        printf("Nguoi nay da muon qua gioi han!\n");
        return;
    }

    printf("Nhap ID sach muon muon: ");
    scanf("%s", bookId);
    int bIdx = findBookIndexById(books, nBook, bookId);
    
    if (bIdx == -1) { printf("Khong tim thay sach!\n"); return; }
    if (books[bIdx].is_borrowed) { printf("Sach nay da co nguoi muon!\n"); return; }
    
    // Thực hiện mượn
    books[bIdx].is_borrowed = true;
    strcpy(users[uIdx].borrowed_books[users[uIdx].borrow_count], bookId);
    users[uIdx].borrow_count++;
    printf("Muon sach thanh cong!\n");
}

void returnBook(User users[], int nUser, Book books[], int nBook) {
    char userId[MAX_ID], bookId[MAX_ID];
    printf("Nhap ID nguoi tra: ");
    scanf("%s", userId);
    
    int uIdx = -1;
    for (int i = 0; i < nUser; i++) {
        if (strcmp(users[i].id, userId) == 0) uIdx = i;
    }
    if (uIdx == -1) { printf("Khong tim thay nguoi dung!\n"); return; }

    printf("Nhap ID sach muon tra: ");
    scanf("%s", bookId);
    
    // Kiểm tra xem người này có đang mượn sách này không
    int foundInUser = -1;
    for (int i = 0; i < users[uIdx].borrow_count; i++) {
        if (strcmp(users[uIdx].borrowed_books[i], bookId) == 0) {
            foundInUser = i;
            break;
        }
    }
    if (foundInUser == -1) { printf("Nguoi nay khong muon cuon sach do!\n"); return; }
    
    // Cập nhật sách
    int bIdx = findBookIndexById(books, nBook, bookId);
    if (bIdx != -1) books[bIdx].is_borrowed = false;
    
    // Xóa sách khỏi danh sách mượn của user (dồn mảng)
    for (int i = foundInUser; i < users[uIdx].borrow_count - 1; i++) {
        strcpy(users[uIdx].borrowed_books[i], users[uIdx].borrowed_books[i+1]);
    }
    users[uIdx].borrow_count--;
    printf("Tra sach thanh cong!\n");
}
