#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 함수 선언
void getInput(float* num1, float* num2, char* operator); //사용자에게서 두 숫자와 연산자를 입력 받음.
float calculate(float num1, float num2, char operator, int* status);//status (0:작동, 1:에러)
void printResult(float result, int status); //결과나 에러메세지 출력

int main() {
    float num1, num2, result;  // 입력받은 숫자,결과 저장할 변수
    char operator;             // 연산자 저장 변수
    int status = 0;            // 상태 저장 (0:작동, 1:에러)

    //입력받기 getInput 함수 호출 - 각각의 값의 주소 전달해서 함수에서 값을 저장하게끔
    getInput(&num1, &num2, &operator);

    //계산하기 calculate 함수 호출 - 입력된 숫자, 연산자 기반으로 결과 계산 후 상태 업데이트
    result = calculate(num1, num2, operator, &status);

    //결과 출력 printresult 함수 호출 - 계산 결과 출력
    printResult(result, status);
    return 0;
}

// 사용자에게서 입력받는 함수
void getInput(float* num1, float* num2, char* operator) {
    printf("Enter the first number: ");
    scanf("%f", num1);  // 첫번째 숫자 입력받기

    printf("Enter the second number: ");
    scanf("%f", num2);  // 두번째 숫자 입력받기

    printf("Enter an operator (+, -, *, /): ");
    scanf(" %c", operator);  // 연산자 입력받기 (공백으로 버퍼 정리)
}

// 계산 수행하는 함수 , status 0:정상, 1:비정상
// result=결과 저장, status=계산 상태 저장
float calculate(float num1, float num2, char operator, int* status) {
    float result = 0; //결과 저장 변수 초기화, 초기값 0 설정

    //operator 값(+,-,/,*)에 따라 실행할 연산 선택
    switch (operator) {
    case '+':
        result = num1 + num2;
        break;
    case '-':
        result = num1 - num2;
        break;
    case '*':
        result = num1 * num2;
        break;
    case '/':
        if (num2 != 0) {
            result = num1 / num2;
        }
        else {
            *status = 1;  //num2=0이면 나눗셈 불가,status=1로 비정상 상태 표시
        }
        break;
    default:
        *status = 1;  // operator가 +,-,*,/ 아닐 경우 status=1로 비정상 표시
    }

    return result; //계산 결과 반환
}

// 결과 출력 or 에러 메세지 표시 함수
void printResult(float result, int status) {
    if (status == 0) {
        printf("Result: %.2f\n", result); //실수를 소수점 두자리까지 출력
    } //status=0 정상 경우, 결과 출력 
    else {
        printf("Error: Invalid operation or division by zero.\n");
    } //status=1 비정상 경우, 에러 메세지 출력 
}
