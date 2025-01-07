#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// �ִ� �̷� ���� ����
#define MAX_HISTORY 100

// �̷� ����ü ����
typedef struct {
    float num1;
    float num2;
    char operator;
    float result;
} History;

// �Լ� ����
void getInput(float* num1, float* num2, char* operator);
int calculate(float num1, float num2, char operator, float* result);
void printResult(int status, float result);
void saveHistory(History historyList[], int* count, float num1, float num2, char operator, float result);
void printHistory(const History historyList[], int count);

int main() {
    float num1, num2, result;
    char operator;
    History historyList[MAX_HISTORY]; // �̷� ���� �迭
    int historyCount = 0;            // ����� �̷� ����

    while (1) {
        // �Է� ó��
        getInput(&num1, &num2, &operator);

        // ���� ����
        int status = calculate(num1, num2, operator, &result);

        // ��� ���
        printResult(status, result);

        // ������ ���������� �Ϸ�� ��� �̷� ����
        if (status == 0) {
            saveHistory(historyList, &historyCount, num1, num2, operator, result);
        }

        // �̷� ��� ���� Ȯ��
        printf("\n���� �̷��� ����Ͻðڽ��ϱ�? (y/n): ");
        char choice;
        scanf(" %c", &choice);
        if (choice == 'y' || choice == 'Y') {
            printHistory(historyList, historyCount);
        }

        // ������� �������� Ȯ��
        printf("\n���ο� ����� �����Ͻðڽ��ϱ�? (y/n): ");
        scanf(" %c", &choice);
        if (choice != 'y' && choice != 'Y') {
            break; // ���α׷� ����
        }
    }

    return 0;
}

// ����� �Է� �ޱ�
void getInput(float* num1, float* num2, char* operator) {
    printf("Enter first number: ");
    scanf("%f", num1);

    printf("Enter second number: ");
    scanf("%f", num2);

    printf("Enter an operator (ex: +, -, /, *): ");
    scanf(" %c", operator);
}

// ���� ����
int calculate(float num1, float num2, char operator, float* result) {
    if (operator != '+' && operator != '-' && operator != '*' && operator != '/') {
        return 2; // �߸��� ������
    }
    if (operator == '/' && num2 == 0) {
        return 1; // 0���� ������ ����
    }

    switch (operator) {
    case '+': *result = num1 + num2; break;
    case '-': *result = num1 - num2; break;
    case '*': *result = num1 * num2; break;
    case '/': *result = num1 / num2; break;
    }
    return 0; // ���� ����
}

// ��� ���
void printResult(int status, float result) {
    if (status == 0) {
        printf("Result: %.2f\n", result);
    }
    else if (status == 1) {
        printf("Error: 0���� ���� �� �����ϴ�.\n");
    }
    else {
        printf("Error: �ùٸ� operator�� �Է��ϼ���.\n");
    }
}

// ���� �̷� ����
void saveHistory(History historyList[], int* count, float num1, float num2, char operator, float result) {
    if (*count < MAX_HISTORY) { // �̷� ���� ���� Ȯ��
        historyList[*count].num1 = num1;
        historyList[*count].num2 = num2;
        historyList[*count].operator = operator;
        historyList[*count].result = result;
        (*count)++;
    }
    else {
        printf("�̷� ���� ������ ���� á���ϴ�.\n");
    }
}

// ���� �̷� ���
void printHistory(const History historyList[], int count) {
    printf("\n*********�̷�*********\n");
    for (int i = 0; i < count; i++) {
        printf("%d: %.2f %c %.2f = %.2f\n", i + 1,
            historyList[i].num1, historyList[i].operator,
            historyList[i].num2, historyList[i].result);
    }
    printf("*********����*********\n");
}
