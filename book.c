#include <stdio.h>
#include <string.h>
#include "book.h"

// Hàm in danh sách sách dạng bảng
void displayBooks(Book books[], int n) {
    printf("\n--- DANH SACH SACH ---\n");
    printf("%-10s %-30s %-20s %-15s\n", "ID", "Tieu de", "Tac gia", "Trang thai");
    for (int i = 0; i < n; i++) {
        printf("%-10s %-30s %-20s %-15s\n", 
            books[i].id, 
            books[i].title, 
            books[i].author, 
            books[i].is_borrowed ;
    }
    printf("----------------------\n");
}

void addBook(Book books[], int *n) {
    printf("Nhap ID sach: ");
    scanf("%s", books[*n].id);
    getchar(); // Xóa bộ nhớ đệm
    printf("Nhap tieu de: ");
    fgets(books[*n].title, MAX_TITLE, stdin);
    books[*n].title[strcspn(books[*n].title, "\n")] = 0;
    printf("Nhap tac gia: ");
    fgets(books[*n].author, MAX_AUTHOR, stdin);
    books[*n].author[strcspn(books[*n].author, "\n")] = 0;
    
    books[*n].is_borrowed = false;
    (*n)++;
    printf("Them sach thanh cong!\n");
}

// Hàm tìm vị trí sách theo ID (Helper function)
int findBookIndexById(Book books[], int n, char *id) {
    for (int i = 0; i < n; i++) {
        if (strcmp(books[i].id, id) == 0) return i;
    }
    return -1;
}

void editBook(Book books[], int n) {
    char id[MAX_ID];
    printf("Nhap ID sach can sua: ");
    scanf("%s", id);
    getchar();
    
    int index = findBookIndexById(books, n, id);
    if (index == -1) {
        printf("Khong tim thay sach!\n");
        return;
    }
    
    printf("Nhap tieu de moi: ");
    fgets(books[index].title, MAX_TITLE, stdin);
    books[index].title[strcspn(books[index].title, "\n")] = 0;
    printf("Nhap tac gia moi: ");
    fgets(books[index].author, MAX_AUTHOR, stdin);
    books[index].author[strcspn(books[index].author, "\n")] = 0;
    printf("Cap nhat thanh cong!\n");
}

void deleteBook(Book books[], int *n) {
    char id[MAX_ID];
    printf("Nhap ID sach can xoa: ");
    scanf("%s", id);
    
    int index = findBookIndexById(books, *n, id);
    if (index == -1) {
        printf("Khong tim thay sach!\n");
        return;
    }
    
    // Dồn mảng để xóa
    for (int i = index; i < *n - 1; i++) {
        books[i] = books[i + 1];
    }
    (*n)--;
    printf("Xoa thanh cong!\n");
}

void searchBook(Book books[], int n) {
    char keyword[MAX_TITLE];
    printf("Nhap ten sach muon tim: ");
    getchar();
    fgets(keyword, MAX_TITLE, stdin);
    keyword[strcspn(keyword, "\n")] = 0;
    
    printf("Ket qua tim kiem:\n");
    for (int i = 0; i < n; i++) {
        if (strstr(books[i].title, keyword) != NULL) {
             printf("%-10s %-30s %-20s\n", books[i].id, books[i].title, books[i].author);
        }
    }
}
