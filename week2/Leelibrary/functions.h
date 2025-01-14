#include <stdio.h>
#include "library.h"

int rentedBooks[10] = { 0 }; // 0: 대여되지 않음, 1: 대여됨

void printBookList(void) {
    printf("\n책 목록을 확인합니다.\n");
    printf("======================================================\n");
    printf(" 1. The Hidden Forest - Emma Carter\n");
    printf(" 2. Whispers of the Universe - James L.Harper\n");
    printf(" 3. Beneath the Ocean Sky - Clara Thompson\n");
    printf(" 4. Chronicles of the Lost City - Robert H.Fields\n");
    printf(" 5. Echoes of the Past - Victor Daniels\n");
    printf(" 6. The Secret of Silver Lake - Linda Montgomery\n");
    printf(" 7. Shadows of the Forgotten - Samuel Wright\n");
    printf(" 8. Journey to the Edge of Time - Olivia Bennett\n");
    printf(" 9. Legends of the Starry Night - Henry Caldwell\n");
    printf("10. The Timeless Wanderer - Eleanor Grace\n");
    printf("======================================================\n");
}

void rentBook(void) {
    int rentbook;
    printf("책을 대여합니다.\n");
    printBookList();
    printf("대여할 책 번호를 선택해주세요. (1-10): ");
    if (scanf("%d", &rentbook) != 1 || rentbook < 1 || rentbook > 10) {
        printf("잘못된 입력입니다. 올바른 책 번호를 입력해주세요.\n");
        while (getchar() != '\n');  // 입력 버퍼 비우기
    }
    else {
        if (rentedBooks[rentbook - 1] == 0) {
            rentedBooks[rentbook - 1] = 1;
            printf("책 번호 %d번을 대출하였습니다. 대출이 완료되었습니다.\n", rentbook);
        }
        else {
            printf("이미 대여된 책입니다.\n");
        }
    }
}

void returnBook(void) {
    int rentbook;
    printf("책을 반납합니다.\n");
    printf("반납할 책 번호를 입력하세요 (1-10): ");
    scanf("%d", &rentbook);
    if (rentbook >= 1 && rentbook <= 10 && rentedBooks[rentbook - 1] == 1) {
        rentedBooks[rentbook - 1] = 0;
        printf("책 번호 %d번이 반납되었습니다.\n", rentbook);
    }
    else {
        printf("대출된 책이 아니거나 잘못된 번호입니다.\n");
    }
}

void showRentedBooks(void) {
    printf("나의 대출 현황을 확인합니다.\n");
    printf("======================================================\n");
    for (int i = 0; i < 10; i++) {
        if (rentedBooks[i] == 1) {
            printf("책 번호 %d번 대출됨\n", i + 1);
        }
    }
    printf("======================================================\n");
}
