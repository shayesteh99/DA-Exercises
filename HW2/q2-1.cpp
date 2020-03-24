#include <iostream>
#include <string>
#include <stdio.h>
#include <set>
#include <queue>

using namespace std;
int main() {

	int n, k;
	scanf("%d %d", &n, &k);
	int coconut[n], hazelnut[n], costs[n];
	int min_cost, total_cost = 0, total_coconut = 0, total_hazel = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &coconut[i]);
		total_coconut += coconut[i];
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &hazelnut[i]);
		total_hazel += hazelnut[i];
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &costs[i]);
		total_cost += costs[i];
	}
	min_cost = total_cost;

	if (total_coconut <= k && total_hazel <= k && total_hazel + total_coconut <= 2*k - 2) {
		printf("-1");
		return 0;
	}

	int coconutarr[k+1][n+1];
	for (int i = 0; i < k+1; i++)
		coconutarr[i][0] = total_cost;
	for (int j = 0; j < n+1; j++)
		coconutarr[k][j] = 0;
	for (int j = 1; j < n+1; j++)
		for (int i = 0; i < k; i++) {
			if (i + coconut[j-1] - 1 <= k) {
				coconutarr[i][j] = min(coconutarr[i][j-1], coconutarr[i + coconut[j-1] - 1][j-1] + costs[j-1]);
			}
			else {
				coconutarr[i][j] = min(coconutarr[i][j-1], coconutarr[k][j-1] + costs[j-1]);
			}
		}

	int hazelnutarr[k+1][n+1];
	for (int i = 0; i < k+1; i++)
		hazelnutarr[i][0] = total_cost;
	for (int j = 0; j < n+1; j++)
		hazelnutarr[k][j] = 0;
	for (int j = 1; j < n+1; j++)
		for (int i = 0; i < k; i++) {
			if (i + hazelnut[j-1] - 1 <= k) {
				hazelnutarr[i][j] = min(hazelnutarr[i][j-1], hazelnutarr[i + hazelnut[j-1] - 1][j-1] + costs[j-1]);
			}
			else {
				hazelnutarr[i][j] = min(hazelnutarr[i][j-1], hazelnutarr[k][j-1] + costs[j-1]);
			}
		}

	int botharr[2*k][n+1];
	for (int i = 0; i < 2*k; i++)
		botharr[i][0] = total_cost;
	for (int j = 0; j < n+1; j++)
		botharr[2*k - 1][j] = 0;
	for (int j = 1; j < n+1; j++)
		for (int i = 0; i < 2*k - 1; i++) {
			if (i + hazelnut[j-1] + coconut[j-1] <= 2 * k - 1) {
				botharr[i][j] = min(botharr[i][j-1], botharr[i + hazelnut[j-1] + coconut[j-1]][j-1] + costs[j-1]);
			}
			else {
				botharr[i][j] = min(botharr[i][j-1], botharr[2*k - 1][j-1] + costs[j-1]);
			}
		}


	min_cost = min(min(coconutarr[0][n], hazelnutarr[0][n]), botharr[0][n]);
	printf("%d\n", min_cost);

  	return 0;
}