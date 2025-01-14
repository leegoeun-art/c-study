#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int choice;
    int rentbook;

    // 대출 상태 관리 배열 (0: 대출 안됨, 1: 대출됨)
    int rentedBooks[10] = { 0 }; 

    while (1) {
        printf("\n안녕하세요. LeeLibrary입니다.\n");
        printf("\n도서관리 시스템을 찾아주셔서 감사합니다.\n");
        printf(" 0. 책 목록 확인하기\n 1. 책 대여하기\n 2. 책 반납하기\n 3. 나의 대출 현황 확인하기\n 4. 프로그램 종료하기\n");
        printf("원하시는 항목을 선택해주세요(0-4): ");

        if (scanf("%d", &choice) != 1) {
            printf("잘못된 입력입니다. 올바른 숫자를 입력하세요.\n");
            while (getchar() != '\n'); // 입력 버퍼 비우기
            continue;
        }

        switch (choice) {
        case 0:
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
            break;

        case 1:
            printf("책을 대여합니다.\n");
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
            printf("대여할 책 번호를 선택해주세요. (1-10): ");
            if (scanf("%d", &rentbook) != 1 || rentbook < 1 || rentbook > 10) {
                printf("잘못된 입력입니다. 올바른 책 번호를 입력해주세요.\n");
                while (getchar() != '\n'); // 입력 버퍼 비우기
            }
            else {
                if (rentedBooks[rentbook - 1] == 0) {
                    rentedBooks[rentbook - 1] = 1;
                    printf("책 번호 %d번을 대출하였습니다. 대출이 완료되었습니다.\n", rentbook);
                }
                else {
                    printf("이미 대출된 책입니다. 다른 책을 선택해주세요.\n");
                }
            }
            break;

        case 2:
            printf("책을 반납합니다.\n");
            printf("반납할 책 번호를 입력하세요 (1-10): ");
            if (scanf("%d", &rentbook) != 1 || rentbook < 1 || rentbook > 10) {
                printf("잘못된 입력입니다. 올바른 책 번호를 입력해주세요.\n");
                while (getchar() != '\n'); // 입력 버퍼 비우기
            }
            else {
                if (rentedBooks[rentbook - 1] == 1) {
                    rentedBooks[rentbook - 1] = 0;
                    printf("책 번호 %d번이 반납되었습니다.\n", rentbook);
                }
                else {
                    printf("대출된 책이 아니거나 잘못된 번호입니다.\n");
                }
            }
            break;

        case 3:
            printf("나의 대출 현황을 확인합니다.\n");
            int rentedCount = 0;
            for (int i = 0; i < 10; i++) {
                if (rentedBooks[i] == 1) {
                    printf("%d. 책 번호 %d번: 대출 중\n", i + 1, i + 1);
                    rentedCount++;
                }
            }
            if (rentedCount == 0) {
                printf("현재 대출 중인 책이 없습니다.\n");
            }
            break;

        case 4:
            printf("시스템을 종료합니다.\n LeeLibrary를 찾아주셔서 감사합니다.\n");
            return 0; // 프로그램 종료

        default:
            printf("잘못된 선택입니다. 다시 선택해주세요.\n");
            break;
        }
    }

    return 0;
}
