#include <cstdio>
#define MAX 21
#define _DICE 6

typedef struct POINT {
    int x;
    int y;
} Point;

typedef struct DICE {
    Point location;
    int index[_DICE] = {1, 5, 3, 2, 4, 6};
    int num[_DICE] = {0, };
} Dice;

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

int n, m;
Dice dice;
int map[MAX][MAX];

bool is_in_range (int x, int y) {
    bool promising = true;

    if (x < 0 || x >= n) promising = false;
    if (y < 0 || y >= m) promising = false;

    return promising;
}

void change_dice_index (int direction) {
    int tmp = dice.index[0];

    switch (direction) {
        case 1: {
            dice.index[0] = dice.index[4];
            dice.index[4] = dice.index[5];
            dice.index[5] = dice.index[2];
            dice.index[2] = tmp;
            break;
        }
        case 2: {
            dice.index[0] = dice.index[2];
            dice.index[2] = dice.index[5];
            dice.index[5] = dice.index[4];
            dice.index[4] = tmp;
            break;
        }
        case 3: {
            dice.index[0] = dice.index[1];
            dice.index[1] = dice.index[5];
            dice.index[5] = dice.index[3];
            dice.index[3] = tmp;
            break;
        }
        case 4: {
            dice.index[0] = dice.index[3];
            dice.index[3] = dice.index[5];
            dice.index[5] = dice.index[1];
            dice.index[1] = tmp;
            break;
        }
    }
}

int main (int argc, const char* argv[]) {
    int dir;
    int instruction;

    scanf("%d %d", &n, &m);

    scanf("%d %d", &dice.location.x, &dice.location.y);

    scanf("%d", &instruction);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &map[i][j]);
        }
    }

    for (int k = 0; k < instruction; ++k) {
        scanf("%d", &dir);

        int nx = dice.location.x + dx[dir - 1];
        int ny = dice.location.y + dy[dir - 1];

        if (!is_in_range(nx, ny)) continue;

        change_dice_index(dir);

        if (map[nx][ny] == 0) {
            map[nx][ny] = dice.num[dice.index[_DICE - 1] - 1];
        }
        else {
            dice.num[dice.index[_DICE - 1] - 1] = map[nx][ny];
            map[nx][ny] = 0;
        }

        dice.location.x = nx;
        dice.location.y = ny;

        printf("%d\n", dice.num[dice.index[0] - 1]);
    }

    return 0;
}