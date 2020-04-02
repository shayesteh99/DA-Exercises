#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>


using namespace std;
int main() {

	const int max_int = 2147483647;
	char bj, ej;
	int begi, begj, endj, endi;
	scanf("%c%d %c%d", &bj, &begi, &ej, &endi);
	begj = bj - 'a';
	endj = ej - 'a';
	begi = 8 - begi;
	endi = 8 - endi;
	int dice[6];
	scanf("%d", &dice[0]);
	scanf("%d", &dice[5]);
	scanf("%d", &dice[1]);
	scanf("%d", &dice[3]);
	scanf("%d", &dice[4]);
	scanf("%d", &dice[2]);

	int cost[8][8], father[8][8], bottom[8][8], right[8][8], left[8][8], near[8][8], far[8][8], top[8][8];
	bool visited[8][8];
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++) {
			visited[i][j] = false;
			if (i == begi && j == begj) {
				cost[i][j] = dice[4];
				father[i][j] = 0;
				bottom[i][j] = 4;
				right[i][j] = 3;
				near[i][j] = 0;
				far[i][j] = 5;
				top[i][j] = 1;
				left[i][j] = 2;
			}
			else {
				cost[i][j] = max_int;
			}
		}

	int mini, minj;
	while (true) {
		mini = -1;
		minj = -1;
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
				if (!visited[i][j] && (mini == -1 || cost[i][j] < cost[mini][minj])) {
					mini = i;
					minj = j;
				}
		printf("%d\n", cost[mini][minj]);
		visited[mini][minj] = true;
		if (mini == endi && minj == endj)
			break;
		if (mini > 0) {
			if (!visited[mini - 1][minj] && cost[mini][minj] + dice[far[mini][minj]] < cost[mini - 1][minj]) {
				cost[mini - 1][minj] = cost[mini][minj] + far[mini][minj];
				father[mini - 1][minj] = 1;
				near[mini - 1][minj] = bottom[mini][minj];
				far[mini - 1][minj] = top[mini][minj];
				bottom[mini - 1][minj] = far[mini][minj];
				top[mini - 1][minj] = near[mini][minj];
				right[mini - 1][minj] = right[mini][minj];
				left[mini - 1][minj] = left[mini][minj];
			}

		}
		if (mini < 7) {
			if (!visited[mini + 1][minj] && cost[mini][minj] + dice[near[mini][minj]] < cost[mini + 1][minj]) {
				cost[mini + 1][minj] = cost[mini][minj] + dice[near[mini][minj]];
				father[mini + 1][minj] = 2;
				near[mini + 1][minj] = top[mini][minj];
				far[mini + 1][minj] = bottom[mini][minj];
				bottom[mini + 1][minj] = near[mini][minj];
				top[mini + 1][minj] = far[mini][minj];
				right[mini + 1][minj] = right[mini][minj];
				left[mini + 1][minj] = left[mini][minj];
			}
		}
		if (minj > 0) {
			if (!visited[mini][minj - 1] && cost[mini][minj] + dice[left[mini][minj]] < cost[mini][minj - 1]) {
				cost[mini][minj - 1] = cost[mini][minj] + dice[left[mini][minj]];
				father[mini][minj - 1] = 3;
				near[mini][minj - 1] = near[mini][minj];
				far[mini][minj - 1] = far[mini][minj];
				top[mini][minj - 1] = right[mini][minj];
				bottom[mini][minj - 1] = left[mini][minj];
				right[mini][minj - 1] = bottom[mini][minj];
				left[mini][minj -1] = top[mini][minj];
			}
		}
		if (minj < 7) {
			if (!visited[mini][minj + 1] && cost[mini][minj] + dice[right[mini][minj]] < cost[mini][minj + 1]) {
				cost[mini][minj + 1] = cost[mini][minj] + dice[right[mini][minj]];
				father[mini][minj + 1] = 4;
				near[mini][minj + 1] = near[mini][minj];
				far[mini][minj + 1] = far[mini][minj];
				top[mini][minj + 1] = left[mini][minj];
				bottom[mini][minj + 1] = right[mini][minj];
				right[mini][minj + 1] = top[mini][minj];
				left[mini][minj + 1] = bottom[mini][minj];
			}
		}

	}

	vector<int> veci, vecj;
	veci.push_back(endi);
	vecj.push_back(endj);
	int childi = endi, childj = endj;
	while(father[childi][childj] != 0) {
		int f = father[childi][childj];
		if (f == 1) 
			childi++;
		else if (f == 2)
			childi--;
		else if (f == 3)
			childj++;
		else if (f == 4)
			childj--;

		veci.push_back(childi);
		vecj.push_back(childj);
	}

	printf("%d ", cost[endi][endj]);
	for(int i = veci.size() - 1; i >= 0; i--) {
		char col = vecj.at(i) + 'a';
		int row = 8 - veci.at(i);
		printf("%c%d ", col, row);
	}




  	return 0;
}