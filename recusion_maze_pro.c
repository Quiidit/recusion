#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 100
#define PATH 1 /* 지나갈 수 있는 위치 */
#define WALL 0 /* 지나갈 수 없는 위치 */
#define VISITED 2 /* 이미 방문한 위치 */
#define BACKTRACKED 3 /* 방문했다가 되돌아 나온 위치 */
int maze[MAX][MAX];
int n; /* 미로의 크기 */
typedef struct pos {
	int x, y;
} Position;
void read_maze();
int rotate(int x, int y, int cnt) {
	if (maze[x][y - 1] != 1 && maze[x - 1][y - 1] != 1 && maze[x - 1][y] != 1 && maze[x - 1][y + 1] != 1 && maze[x][y + 1] != 1 && maze[x + 1][y + 1] != 1 && maze[x + 1][y] != 1 && maze[x + 1][y - 1] != 1 && maze[x][y - 1] != 2 && maze[x - 1][y - 1] != 2 && maze[x - 1][y] != 2 && maze[x - 1][y + 1] != 2 && maze[x][y + 1] != 2 && maze[x + 1][y + 1] != 2 && maze[x + 1][y] != 2 && maze[x + 1][y - 1] != 2)
		return cnt;
	if (maze[x][y - 1] == 1) {
		maze[x][y - 1] = 2;
		rotate(x, y - 1, cnt + 1);
	}
	else if (maze[x - 1][y - 1] == 1) {
		maze[x - 1][y - 1] = 2;
		rotate(x - 1, y - 1, cnt + 1);
	}
	else if (maze[x - 1][y] == 1) {
		maze[x - 1][y] = 2;
		rotate(x - 1, y, cnt + 1);
	}
	else if (maze[x - 1][y + 1] == 1) {
		maze[x - 1][y + 1] = 2;
		rotate(x - 1, y + 1, cnt + 1);
	}
	else if (maze[x][y + 1] == 1) {
		maze[x][y + 1] = 2;
		rotate(x, y + 1, cnt + 1);
	}
	else if (maze[x + 1][y + 1] == 1) {
		maze[x + 1][y + 1] = 2;
		rotate(x + 1, y+1, cnt + 1);
	}
	else if (maze[x + 1][y] == 1) {
		maze[x + 1][y] = 2;
		rotate(x + 1, y, cnt + 1);
	}
	else if (maze[x + 1][y - 1] == 1) {
		maze[x + 1][y - 1] = 2;
		rotate(x + 1, y - 1, cnt + 1);
	}
	else {
		if (maze[x][y - 1] == 2) {
			maze[x][y - 1] = 3;
			rotate(x, y - 1, cnt);
		}
		else if (maze[x - 1][y - 1] == 2) {
			maze[x - 1][y - 1] = 3;
			rotate(x - 1, y - 1, cnt);
		}
		else if (maze[x - 1][y] == 2) {
			maze[x - 1][y] = 3;
			rotate(x - 1, y, cnt);
		}
		else if (maze[x - 1][y + 1] == 2) {
			maze[x - 1][y + 1] = 3;
			rotate(x - 1, y + 1, cnt);
		}
		else if (maze[x][y + 1] == 2) {
			maze[x][y + 1] = 3;
			rotate(x, y + 1, cnt);
		}
		else if (maze[x + 1][y + 1] == 2) {
			maze[x + 1][y + 1] = 3;
			rotate(x + 1, y + 1, cnt);
		}
		else if (maze[x + 1][y] == 2) {
			maze[x + 1][y] = 3;
			rotate(x + 1, y, cnt);
		}
		else if (maze[x + 1][y - 1] == 2) {
			maze[x + 1][y - 1] = 3;
			rotate(x + 1, y - 1, cnt);
		}
	}



}
int main()
{
	read_maze(); /* maze.txt파일로부터 미로의 모양을 배열 maze로 입력받는다. */
	Position cur; /* 항상 현재 위치를 표현 */
	cur.x = 0;
	cur.y = 0;
	int result;
	while (1) {
		if (maze[cur.x][cur.y] != 1) {
			cur.y++;
			if (cur.y >= n) {
				cur.x++;
				cur.y = 0;
			}
			if (cur.x >= n)
				break;
			continue;
		}
		maze[cur.x][cur.y] = 2;
		result = rotate(cur.x, cur.y ,0);
		printf("%d ", result);
	}
	printf("\n");
}
void read_maze() {
	char num[MAX];
	int len;
	int i, j = 0;
	FILE *fin = fopen("maze.txt", "r");
	fscanf(fin, "%d", &n);
	fgetc(fin);
	while (!feof(fin)) {
		fgets(num, MAX, fin);
		for (i = 0; i < n; i++) {
			maze[j][i] = num[i] - '0';
		}
		j++;
	}
}
