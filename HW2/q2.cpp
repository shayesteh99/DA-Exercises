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
	int min_cost = 0, total_coconut = 0, total_hazel = 0;
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
		min_cost += costs[i];
	}

	if (total_coconut <= k && total_hazel <= k && total_hazel + total_coconut <= 2*k - 2) {
		printf("-1");
		return 0;
	}

	int arr[n+3];
	queue<int> subs[n+3];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j)
				arr[j] = 1;
			else
				arr[j] = 0;
		}
		arr[n] = coconut[i];
		arr[n+1] = hazelnut[i];
		arr[n+2] = costs[i];

		if (arr[n] > k || arr[n+1] > k || arr[n] + arr[n+1] > 2*k - 2)
			min_cost = arr[n+2];
		else
			for (int j = 0; j < n+3; j++)
				subs[j].push(arr[j]);
	}
	while (subs[0].size() > 0) {
		int max = 0;
		for (int i = 0; i < n+3; i++) {
			arr[i] = subs[i].front();
			subs[i].pop();
			if (i < n && arr[i] == 1)
				max = i;
			// printf("%d ", arr[i]);
		}
		// printf("\n");
		
		for (int i = max + 1; i < n; i++) {
			if (arr[i] == 0 && arr[n+2] + costs[i] < min_cost) {
				if (arr[n] + coconut[i] > k || arr[n+1] + hazelnut[i] > k || arr[n] + coconut[i]+arr[n+1] + hazelnut[i] > 2*k - 2)
					min_cost = arr[n+2] + costs[i];
				else {
					int a[n+3];
					for (int j = 0; j < n; j++) {
						if (j == i)
							subs[j].push(1);
						else
							subs[j].push(arr[j]);

					}
					subs[n].push(arr[n] + coconut[i]);
					subs[n+1].push(arr[n+1] + hazelnut[i]);
					subs[n+2].push(arr[n+2] + costs[i]);
				}
			}
		}
	}
	printf("%d", min_cost);


  	return 0;
}