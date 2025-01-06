#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 최대 이력 저장 개수
#define MAX_HISTORY 100

// 이력 구조체 정의
typedef struct {
    float num1;
    float num2;
    char operator;
    float result;
} History;

// 함수 선언
void getInput(float* num1, float* num2, char* operator);
int calculate(float num1, float num2, char operator, float* result);
void printResult(int status, float result);
void saveHistory(History historyList[], int* count, float num1, float num2, char operator, float result);
void printHistory(const History historyList[], int count);

int main() {
    float num1, num2, result;
    char operator;
    History historyList[MAX_HISTORY]; // 이력 저장 배열
    int historyCount = 0;            // 저장된 이력 개수

    while (1) {
        // 입력 처리
        getInput(&num1, &num2, &operator);

        // 연산 수행
        int status = calculate(num1, num2, operator, &result);

        // 결과 출력
        printResult(status, result);

        // 연산이 성공적으로 완료된 경우 이력 저장
        if (status == 0) {
            saveHistory(historyList, &historyCount, num1, num2, operator, result);
        }

        // 이력 출력 여부 확인
        printf("\n연산 이력을 출력하시겠습니까? (y/n): ");
        char choice;
        scanf(" %c", &choice);
        if (choice == 'y' || choice == 'Y') {
            printHistory(historyList, historyCount);
        }

        // 계속할지 종료할지 확인
        printf("\n새로운 계산을 시작하시겠습니까? (y/n): ");
        scanf(" %c", &choice);
        if (choice != 'y' && choice != 'Y') {
            break; // 프로그램 종료
        }
    }

    return 0;
}

// 사용자 입력 받기
void getInput(float* num1, float* num2, char* operator) {
    printf("Enter first number: ");
    scanf("%f", num1);

    printf("Enter second number: ");
    scanf("%f", num2);

    printf("Enter an operator (ex: +, -, /, *): ");
    scanf(" %c", operator);
}

// 연산 수행
int calculate(float num1, float num2, char operator, float* result) {
    if (operator != '+' && operator != '-' && operator != '*' && operator != '/') {
        return 2; // 잘못된 연산자
    }
    if (operator == '/' && num2 == 0) {
        return 1; // 0으로 나누기 에러
    }

    switch (operator) {
    case '+': *result = num1 + num2; break;
    case '-': *result = num1 - num2; break;
    case '*': *result = num1 * num2; break;
    case '/': *result = num1 / num2; break;
    }
    return 0; // 정상 상태
}

// 결과 출력
void printResult(int status, float result) {
    if (status == 0) {
        printf("Result: %.2f\n", result);
    }
    else if (status == 1) {
        printf("Error: 0으로 나눌 수 없습니다.\n");
    }
    else {
        printf("Error: 올바른 operator를 입력하세요.\n");
    }
}

// 연산 이력 저장
void saveHistory(History historyList[], int* count, float num1, float num2, char operator, float result) {
    if (*count < MAX_HISTORY) { // 이력 저장 공간 확인
        historyList[*count].num1 = num1;
        historyList[*count].num2 = num2;
        historyList[*count].operator = operator;
        historyList[*count].result = result;
        (*count)++;
    }
    else {
        printf("이력 저장 공간이 가득 찼습니다.\n");
    }
}

// 연산 이력 출력
void printHistory(const History historyList[], int count) {
    printf("\n*********이력*********\n");
    for (int i = 0; i < count; i++) {
        printf("%d: %.2f %c %.2f = %.2f\n", i + 1,
            historyList[i].num1, historyList[i].operator,
            historyList[i].num2, historyList[i].result);
    }
    printf("*********종료*********\n");
}
