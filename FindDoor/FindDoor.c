#include <stdio.h>

// 미로 크기 정의
#define ROWS 5
#define COLS 5

// 미로와 플레이어 위치 초기화
char maze[ROWS][COLS] = {
    {'S', '.', '.', '.', '.'},
    {'#', '#', '.', '#', '.'},
    {'.', '.', '.', '#', '.'},
    {'#', '.', '#', '#', '.'},
    {'.', '.', '.', '.', 'E'} // 'E'는 출구
};

int playerRow = 0; // 플레이어 시작 위치 (행)
int playerCol = 0; // 플레이어 시작 위치 (열)

// 미로 출력 함수
void printMaze() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i == playerRow && j == playerCol) {
                printf("P "); // 플레이어 위치는 'P'로 표시
            } else {
                printf("%c ", maze[i][j]);
            }
        }
        printf("\n");
    }
}

// 이동 함수
void movePlayer(char direction) {
    int newRow = playerRow;
    int newCol = playerCol;

    // 방향에 따라 새 위치 계산
    if (direction == 'w') newRow--; // 위로 이동
    else if (direction == 's') newRow++; // 아래로 이동
    else if (direction == 'a') newCol--; // 왼쪽으로 이동
    else if (direction == 'd') newCol++; // 오른쪽으로 이동

    // 이동 가능 여부 확인
    if (newRow >= 0 && newRow < ROWS && newCol >= 0 && newCol < COLS && maze[newRow][newCol] != '#') {
        playerRow = newRow;
        playerCol = newCol;
    } else {
        printf("이동할 수 없습니다!\n");
    }
}

// 게임 실행 함수
void playGame() {
    char input;

    printf("미로 탈출 게임 시작!\n");
    printf("'W', 'A', 'S', 'D'로 움직이고, 'Q'로 종료합니다.\n");

    while (1) {
        printMaze();

        // 플레이어 입력 받기
        printf("움직일 방향을 입력하세요: ");
        scanf(" %c", &input);

        // 게임 종료 조건
        if (input == 'q') {
            printf("게임을 종료합니다.\n");
            break;
        }

        // 플레이어 이동
        movePlayer(input);

        // 출구 도달 여부 확인
        if (maze[playerRow][playerCol] == 'E') {
            printf("축하합니다! 미로를 탈출했습니다!\n");
            break;
        }
    }
}

int main() {
    playGame();
    return 0;
}
