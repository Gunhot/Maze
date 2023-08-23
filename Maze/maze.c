#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
typedef struct _room {
	short down_flag;
	short right_flag;
	int set;
}room;
int WIDTH;
int HEIGHT;
room** maze;

void build_maze() {
	int h = 0;
	int w = 0;

	//���ڹ��̷� �迭�� ��鿡������ �����Ѵ�.
	//�Ʒ����� �νø鼭 ���յ��� ���� ���� �ֽ�ȭ ���� �ʿ� ������ ��� ���� �ʱ�ȭ �Ѵ�.
	int init_set = 0;
	for (h = 0; h < HEIGHT; h++) {
		for (w = 0; w < WIDTH; w++) {
			maze[h][w].set = ++init_set;
			maze[h][w].down_flag = 1;
			maze[h][w].right_flag = 1;
		}
	}

	//���� �࿡�� ù ��° ����� �����Ͽ� ������ ����� 
	for (h = 0; h < HEIGHT; h++) {
		if (h == HEIGHT - 1) {
			for (w = 0; w < WIDTH - 1; w++) {
				//���� ������ �ٸ� ��
				if (maze[h][w].set != maze[h][w + 1].set) {
					//�ʼ� : ���� �㹰�����
					maze[h][w].right_flag = 0;
					//������ ��ģ��.
					int erase = maze[h][w + 1].set;
					for (int i = h; i >= 0; i--) {
						for (int j = 0; j < WIDTH; j++) {
							if (maze[i][j].set == erase)maze[i][j].set = maze[h][w].set;
						}
					}
				}
			}
		}
		else {
			for (w = 0; w < WIDTH - 1; w++) {
				//���� ������ �ٸ� ���� -> cycle ����
				if (maze[h][w].set != maze[h][w + 1].set) {
					//���� ���� ���θ� �����Ѵ� 
					if ((maze[h][w].right_flag = rand() % 2) == 0) {
						//�������� ��� ������ ����
						int erase = maze[h][w + 1].set;
						for (int i = h; i >= 0; i--) {
							for (int j = 0; j < WIDTH; j++) {
								if (maze[i][j].set == erase)maze[i][j].set = maze[h][w].set;
							}
						}
					}
				}
			}
			//check�� 0�� ��� �ش� ������ ���� ���Ǿ� ������ ��Ÿ����.
			int check = 0;
			for (w = 0; w < WIDTH; w++) {
				if ((maze[h][w].down_flag = rand() % 2) == 0) {
					maze[h + 1][w].set = maze[h][w].set;

					//���� ��
					if (h == 0) {
						//�Ʒ��� �շ����� ���
						if (maze[h][w].down_flag == 0) {
							check = 1;
						}
					}
					//���� �Ʒ�
					else if (h == HEIGHT - 1) {
						//������ �շ����� ���
						if (maze[h][w - 1].down_flag == 0) {
							check = 1;
						}
					}
					//�߰�
					else {
						//���Ʒ��� �ϳ��� �շ����� ���
						if (maze[h][w].set == maze[h + 1][w].set || maze[h][w].set == maze[h - 1][w].set) {
							check = 1;
						}
					}
				}
				//set�� �ٲ��µ��� check�� 0�� ��� �ݵ�� �Ʒ����� �����ؾ���
				else {

					if (((w != WIDTH - 1 && maze[h][w].set != maze[h][w + 1].set) || w == WIDTH - 1) && check == 0) {
						maze[h][w].down_flag = 0;
						maze[h + 1][w].set = maze[h][w].set;
					}
				}
				//set�� �ٲ��ٸ� check�� �ʱ�ȭ
				if (maze[h][w].set != maze[h][w + 1].set) check = 0;
			}
		}
	}
}
void print_maze() {
	/*for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			printf("%d ", maze[i][j].set);
		}
		printf("\n");
	}*/
	FILE* out;
	int h, w;
	out = fopen("maze.maz", "w");
	//õ�� ���
	for (w = 0; w < WIDTH; w++) fprintf(out, "+-");
	fprintf(out, "+\n");

	//�� ���� right_flag�� down_flag�� ���� ���

	for (h = 0; h < HEIGHT; h++) {
		fprintf(out, " |");

		for (w = 0; w < WIDTH; w++) {
			//�����
			fprintf(out, "  ");
			//������ �� ���
			if (maze[h][w].right_flag)fprintf(out, "|");
			else fprintf(out, " ");
		}
		fprintf(out, "\n");

		for (w = 0; w < WIDTH; w++){
			fprintf(out, "+");
			//�Ʒ��� �� ���
			if (maze[h][w].down_flag) fprintf(out, "-");
			else fprintf(out, " ");
		}
		fprintf(out, "+\n");
	}
	fclose(out);
}
void main() {
	//N is WIDTH
	scanf("%d", &WIDTH);
	//M is HEIGHT
	scanf("%d", &HEIGHT);


	maze = (room**)malloc(HEIGHT * sizeof(room*));
	for (int i = 0; i < HEIGHT; i++) {
		*(maze + i) = (room*)malloc(WIDTH * sizeof(room));
	}
	srand(time(NULL));

	build_maze();
	print_maze();
	//�޸� ����
	for (int i = 0; i < HEIGHT; i++) {
			free(maze[i]);
	}
	free(maze);
}