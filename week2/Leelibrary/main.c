// main.c

#include <stdio.h>
#include "library.h"

int main() {
    int choice;

    while (1) {
        printf("안녕하세요. LeeLibrary입니다.\n");
        printf("도서관리 시스템을 찾아주셔서 감사합니다.\n");
        printf(" 0. 책 목록 확인하기\n 1. 책 대여하기\n 2. 책 반납하기\n 3. 나의 대출 현황 확인하기\n 4. 프로그램 종료하기\n");
        printf("원하시는 항목을 선택해주세요(0-4): ");

        if (scanf("%d", &choice) != 1) {
            printf("잘못된 입력입니다. 올바른 숫자를 입력하세요.\n");
            while (getchar() != '\n');  // 입력 버퍼 비우기
            continue;
        }

        switch (choice) {
        case 0:
            printBookList();
            break;
        case 1:
            rentBook();
            break;
        case 2:
            returnBook();
            break;
        case 3:
            showRentedBooks();
            break;
        case 4:
            printf("시스템을 종료합니다.\n LeeLibrary를 찾아주셔서 감사합니다.\n");
            return 0;
        default:
            printf("잘못된 선택입니다. 0에서 4 사이의 올바른 번호를 선택해주세요.\n");
            break;
        }
    }

    return 0;
}
