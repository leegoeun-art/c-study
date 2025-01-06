#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// �Լ� ����
void getString(char* str, int size); //����ڷκ��� ���ڿ� �Է¹޴� �Լ�
int calculateStringLength(const char* str); // �Է¹��� ���ڿ��� ���� ����ϴ� �Լ�

int main() {
    char input[100];  // �Է¹��ڿ��� ������ �迭
    int length;

    // ���ڿ� �Է�
    getString(input, sizeof(input));

    // ���ڿ� ���� ���
    length = calculateStringLength(input);

    // ��� ���
    printf("The length of the entered string is: %d\n", length);

    return 0;
}

// ���ڿ� �Է� �Լ�
void getString(char* str, int size) {
    printf("Enter a string: ");
    fgets(str, size, stdin);  // �迭�� �ּҸ� ���� ���ڿ� �Է�
}

// ���ڿ� ���� ��� �Լ�
int calculateStringLength(const char* str) {
    int length = 0;

    // �����͸� ����Ͽ� ���ڿ��� ��('\0')���� �ݺ�
    while (*str != '\0' && *str != '\n') {
        length++;
        str++;  // ������ �̵�
    }
    return length;
}