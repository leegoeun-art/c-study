#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 함수 선언
void getString(char* str, int size); //사용자로부터 문자열 입력받는 함수
int calculateStringLength(const char* str); // 입력받은 문자열의 길이 계산하는 함수

int main() {
    char input[100];  // 입력문자열을 저장할 배열
    int length;

    // 문자열 입력
    getString(input, sizeof(input));

    // 문자열 길이 계산
    length = calculateStringLength(input);

    // 결과 출력
    printf("The length of the entered string is: %d\n", length);

    return 0;
}

// 문자열 입력 함수
void getString(char* str, int size) {
    printf("Enter a string: ");
    fgets(str, size, stdin);  // 배열의 주소를 통해 문자열 입력
}

// 문자열 길이 계산 함수
int calculateStringLength(const char* str) {
    int length = 0;

    // 포인터를 사용하여 문자열의 끝('\0')까지 반복
    while (*str != '\0' && *str != '\n') {
        length++;
        str++;  // 포인터 이동
    }
    return length;
}