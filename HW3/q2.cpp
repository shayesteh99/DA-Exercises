#include <iostream>
#include <string>
#include <stdio.h>


using namespace std;
int main() {

	const int max_int = 2147483647;
	int n, m, k, start;
	scanf("%d %d", &n, &m);

	int mat[n][n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			mat[i][j] = -1;

	for (int i = 0; i < m; i++) {
		int first, second, w;
		scanf("%d %d %d", &first, &second, &w);
		mat[first - 1][second - 1] = w;
		mat[second - 1][first - 1] = w;
	}

	scanf("%d %d", &start, &k);
	start--;
	bool in[n];
	int cost[n];
	int max_cost = 0;
	for (int i = 0; i < n; i++) {
		in[i] = false;
		cost[i] = max_int;
	}
	cost[start] = 0;

	int max_edge;
	for (int i = 0; i < k; i++) {

		max_edge = -1;
		for (int j = 0; j < n; j++) {
			if (!in[j] && (max_edge == -1 || cost[j] < cost[max_edge]))
				max_edge = j;
		}
		in[max_edge] = true;
		max_cost = max(max_cost, cost[max_edge]);
		for (int j = 0; j < n; j++) {
			if (!in[j] && mat[max_edge][j] >= 0 && mat[max_edge][j] < cost[j])
				cost[j] = mat[max_edge][j];
		}
	}
	if (max_cost == max_int)
		printf("-1\n");
	else
		printf("%d\n", max_cost);



  	return 0;
}