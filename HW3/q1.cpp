#include <iostream>
#include <string>
#include <stdio.h>


using namespace std;
int main() {

	const int max_int = 2147483647;
	int n, m;
	scanf("%d %d", &n, &m);
	int dist[n][n], next[n+1][n+1];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (i == j) {
				dist[i][j] = 0;
				next[i][j] = 0;
			}
			else {
				dist[i][j] = max_int;
				next[i][j] = max_int;
			}
		}
	for (int i = 0; i < n; i++) {
		next[i][n] = max_int;
	}
	for (int j = 0; j < n+1; j++) {
		next[n][j] = 0;
	}
	for (int i = 0; i < m; i++) {
		int first, second, w;
		scanf("%d %d %d", &second, &first, &w);
		dist[first - 1][second - 1] = w;
		next[first - 1][second - 1] = w;
	}

	for (int k = 0; k < n ; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (dist[i][k] != max_int && dist[k][j] != max_int && dist[i][k] + dist[k][j] < dist[i][j])
					dist[i][j] = dist[i][k] + dist[k][j];
	for (int i = 0; i < n; i++)
		if (dist[i][i] < 0) {
			printf("NO\n");
			return 0;
	}


	for (int k = 0; k < n+1; k++)
		for (int i = 0; i < n+1; i++)
			for (int j = 0; j < n+1; j++)
				if (next[i][k] != max_int && next[k][j] != max_int && next[i][k] + next[k][j] < next[i][j])
					next[i][j] = next[i][k] + next[k][j];


	printf("YES\n");
	for (int i = 0; i < n; i++)
		printf("%d ", next[n][i]);


  	return 0;
}