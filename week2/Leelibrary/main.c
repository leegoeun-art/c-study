// main.c

#include <stdio.h>
#include "library.h"

int main() {
    int choice;

    while (1) {
        printf("�ȳ��ϼ���. LeeLibrary�Դϴ�.\n");
        printf("�������� �ý����� ã���ּż� �����մϴ�.\n");
        printf(" 0. å ��� Ȯ���ϱ�\n 1. å �뿩�ϱ�\n 2. å �ݳ��ϱ�\n 3. ���� ���� ��Ȳ Ȯ���ϱ�\n 4. ���α׷� �����ϱ�\n");
        printf("���Ͻô� �׸��� �������ּ���(0-4): ");

        if (scanf("%d", &choice) != 1) {
            printf("�߸��� �Է��Դϴ�. �ùٸ� ���ڸ� �Է��ϼ���.\n");
            while (getchar() != '\n');  // �Է� ���� ����
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
            printf("�ý����� �����մϴ�.\n LeeLibrary�� ã���ּż� �����մϴ�.\n");
            return 0;
        default:
            printf("�߸��� �����Դϴ�. 0���� 4 ������ �ùٸ� ��ȣ�� �������ּ���.\n");
            break;
        }
    }

    return 0;
}
