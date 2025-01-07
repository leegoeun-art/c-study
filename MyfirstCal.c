#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// �Լ� ����
void getInput(float* num1, float* num2, char* operator); //����ڿ��Լ� �� ���ڿ� �����ڸ� �Է� ����.
float calculate(float num1, float num2, char operator, int* status);//status (0:�۵�, 1:����)
void printResult(float result, int status); //����� �����޼��� ���

int main() {
    float num1, num2, result;  // �Է¹��� ����,��� ������ ����
    char operator;             // ������ ���� ����
    int status = 0;            // ���� ���� (0:�۵�, 1:����)

    //�Է¹ޱ� getInput �Լ� ȣ�� - ������ ���� �ּ� �����ؼ� �Լ����� ���� �����ϰԲ�
    getInput(&num1, &num2, &operator);

    //����ϱ� calculate �Լ� ȣ�� - �Էµ� ����, ������ ������� ��� ��� �� ���� ������Ʈ
    result = calculate(num1, num2, operator, &status);

    //��� ��� printresult �Լ� ȣ�� - ��� ��� ���
    printResult(result, status);
    return 0;
}

// ����ڿ��Լ� �Է¹޴� �Լ�
void getInput(float* num1, float* num2, char* operator) {
    printf("Enter the first number: ");
    scanf("%f", num1);  // ù��° ���� �Է¹ޱ�

    printf("Enter the second number: ");
    scanf("%f", num2);  // �ι�° ���� �Է¹ޱ�

    printf("Enter an operator (+, -, *, /): ");
    scanf(" %c", operator);  // ������ �Է¹ޱ� (�������� ���� ����)
}

// ��� �����ϴ� �Լ� , status 0:����, 1:������
// result=��� ����, status=��� ���� ����
float calculate(float num1, float num2, char operator, int* status) {
    float result = 0; //��� ���� ���� �ʱ�ȭ, �ʱⰪ 0 ����

    //operator ��(+,-,/,*)�� ���� ������ ���� ����
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
            *status = 1;  //num2=0�̸� ������ �Ұ�,status=1�� ������ ���� ǥ��
        }
        break;
    default:
        *status = 1;  // operator�� +,-,*,/ �ƴ� ��� status=1�� ������ ǥ��
    }

    return result; //��� ��� ��ȯ
}

// ��� ��� or ���� �޼��� ǥ�� �Լ�
void printResult(float result, int status) {
    if (status == 0) {
        printf("Result: %.2f\n", result);
    } //status=0 ���� ���, ��� ��� 
    else {
        printf("Error: Invalid operation or division by zero.\n");
    } //status=1 ������ ���, ���� �޼��� ��� 
}