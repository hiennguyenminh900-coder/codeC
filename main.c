#include <stdio.h>
#include <stdlib.h>
#include "datatype.h"
#include "book.h"
#include "user.h"

int main() {
    Book books[100];
    User users[100];
    int nBook = 0;
    int nUser = 0;
    int choice;

    while (1) {
        printf("\n=== HE THONG QUAN LY THU VIEN ===\n");
        printf("1. Quan ly SACH (Hien thi/Them/Sua/Xoa/Tim)\n");
        printf("2. Quan ly NGUOI DUNG (Hien thi/Them)\n");
        printf("3. Muon sach\n");
        printf("4. Tra sach\n");
        printf("0. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\n-- MENU SACH --\n");
                printf("1. Hien thi | 2. Them | 3. Sua | 4. Xoa | 5. Tim kiem\n");
                int subChoice;
                scanf("%d", &subChoice);
                if (subChoice == 1) displayBooks(books, nBook);
                else if (subChoice == 2) addBook(books, &nBook);
                else if (subChoice == 3) editBook(books, nBook);
                else if (subChoice == 4) deleteBook(books, &nBook);
                else if (subChoice == 5) searchBook(books, nBook);
                break;
            case 2:
                printf("\n-- MENU NGUOI DUNG --\n");
                printf("1. Hien thi | 2. Them\n");
                int uChoice;
                scanf("%d", &uChoice);
                if (uChoice == 1) displayUsers(users, nUser);
                else if (uChoice == 2) addUser(users, &nUser);
                break;
            case 3:
                borrowBook(users, nUser, books, nBook);
                break;
            case 4:
                returnBook(users, nUser, books, nBook);
                break;
            case 0:
                printf("Tam biet!\n");
                exit(0);
            default:
                printf("Lua chon khong hop le!\n");
        }
    }
    return 0;
}
