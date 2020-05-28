#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

const int MAX = 101;
const int SIZE = 2;
const int DIR = 4;

const int LEFT = 0;
const int UP = 1;
const int RIGHT = 2;
const int DOWN = 3;

const int dx[] = {0, -1, 0, 1};
const int dy[] = {-1, 0, 1, 0};

typedef struct POINT {
    int x, y;
} Point;

typedef struct ROBOT {
    Point p[SIZE];
} Robot;

typedef struct ROUTE {
    Robot robot;
    int d;
} Route;

int n;
bool map[MAX][MAX];
bool flag[MAX][MAX][SIZE];

bool is_arrive (Robot u) {
    for (int i = 0; i < SIZE; ++ i) {
        int x = u.p[i].x;
        int y = u.p[i].y;

        if (x == n - 1 && y == n - 1) return true;
    }
    return false;
}

int get_shape (Robot u) {
    return u.p[1].x - u.p[0].x;
}

bool is_visit (Robot u) {
    int check = 0;
    int shape = get_shape(u);
    shape = u.p[1].x - u.p[0].x;

    for (int i = 0; i < SIZE; ++ i) {
        int x = u.p[i].x;
        int y = u.p[i].y;

        if (flag[x][y][shape]) {
            check ++;
        }
    }

    if (check == SIZE) {
        return true;
    }
    else {
        return false;
    }
}

bool is_in_range (Robot u) {
    for (int i = 0; i < SIZE; ++ i) {
        int x = u.p[i].x;
        int y = u.p[i].y;

        if (x < 0 || x >= n) return false;
        if (y < 0 || y >= n) return false;
    }
    return true;
}

bool is_promising (Robot u) {
    if (!is_in_range(u)) return false;

    for (int i = 0; i < SIZE; ++ i) {
        int x = u.p[i].x;
        int y = u.p[i].y;

        if (map[x][y]) return false;
    }

    return true;
}

void visit (Robot u) {
    int shape = get_shape(u);

    for (int i = 0; i < SIZE; ++ i) {
        int x = u.p[i].x;
        int y = u.p[i].y;

        flag[x][y][shape] = true;
    }
}

Robot move (Robot u, int dir) {
    Robot v;

    for (int i = 0; i < SIZE; ++ i) {
        int x = u.p[i].x;
        int y = u.p[i].y;

        v.p[i].x = x + dx[dir];
        v.p[i].y = y + dy[dir];
    }

    return v;
}

Robot rotation (Robot u, int axis, int clockwise) {
    Robot v;
    int shape = get_shape(u);

    v.p[0].x = -1;

    if (shape) {
        // 세로
        if (axis) {
            if (clockwise) {
                if (!is_promising(move(u, RIGHT))) return v;
                v.p[!axis].x = u.p[axis].x;
                v.p[!axis].y = u.p[axis].y;
                v.p[axis].x = u.p[axis].x + dx[RIGHT];
                v.p[axis].y = u.p[axis].y + dy[RIGHT];
            }
            else {
                if (!is_promising(move(u, LEFT))) return v;
                v.p[!axis].x = u.p[axis].x + dx[LEFT];
                v.p[!axis].y = u.p[axis].y + dy[LEFT];
                v.p[axis].x = u.p[axis].x;
                v.p[axis].y = u.p[axis].y;
            }
        }
        else {
            if (clockwise) {
                if (!is_promising(move(u, LEFT))) return v;
                v.p[!axis].x = u.p[axis].x;
                v.p[!axis].y = u.p[axis].y;
                v.p[axis].x = u.p[axis].x + dx[LEFT];
                v.p[axis].y = u.p[axis].y + dy[LEFT];
            }
            else {
                if (!is_promising(move(u, RIGHT))) return v;
                v.p[!axis].x = u.p[axis].x + dx[RIGHT];
                v.p[!axis].y = u.p[axis].y + dy[RIGHT];
                v.p[axis].x = u.p[axis].x;
                v.p[axis].y = u.p[axis].y;
            }
        }
    }
    else {
        // 가로
        if (axis) {
            if (clockwise) {
                if (!is_promising(move(u, UP))) return v;
                v.p[!axis].x = u.p[axis].x + dx[UP];
                v.p[!axis].y = u.p[axis].y + dy[UP];
                v.p[axis].x = u.p[axis].x;
                v.p[axis].y = u.p[axis].y;
            }
            else {
                if (!is_promising(move(u, DOWN))) return v;
                v.p[!axis].x = u.p[axis].x;
                v.p[!axis].y = u.p[axis].y;
                v.p[axis].x = u.p[axis].x + dx[DOWN];
                v.p[axis].y = u.p[axis].y + dy[DOWN];
            }
        }
        else {
            if (clockwise) {
                if (!is_promising(move(u, DOWN))) return v;
                v.p[!axis].x = u.p[axis].x + dx[DOWN];
                v.p[!axis].y = u.p[axis].y + dy[DOWN];
                v.p[axis].x = u.p[axis].x;
                v.p[axis].y = u.p[axis].y;
            }
            else {
                if (!is_promising(move(u, UP))) return v;
                v.p[axis].x = u.p[axis].x + dx[UP];
                v.p[axis].y = u.p[axis].y + dy[UP];
                v.p[!axis].x = u.p[axis].x;
                v.p[!axis].y = u.p[axis].y;
            }
        }
    }

    return v;
}

int BFS (Robot start) {
    queue<Route> que;

    visit(start);
    que.push({start, 0});

    while (!que.empty()) {
        Robot u = que.front().robot;
        int d = que.front().d;

        if (is_arrive(u)) {
            return d;
        }

        que.pop();

        for (int i = 0; i < DIR; ++ i) {
            Robot v = move(u, i);

            if (is_promising(v) && !is_visit(v)) {
                visit(v);
                que.push({v, d + 1});
            }
        }

        for (int i = 0; i < SIZE; ++ i) {
            for (int clock = 0; clock < SIZE; ++ clock) {
                Robot v = rotation(u, i, clock);

                if (v.p[0].x != -1 && !is_visit(v)) {
                    visit(v);
                    que.push({v, d + 1});
                }
            }
        }
    }

    return 0;
}

void init (vector<vector<int>> board) {
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < n; ++ j) {
            map[i][j] = board[i][j];
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }
}

int solution(vector<vector<int>> board) {
    int answer = 0;

    n = (int)board.size();

    init(board);

    Robot start = {{
        {0, 0},
        {0, 1}
    }};

    answer = BFS(start);

    return answer;
}

