#include <iostream>
#include <string>
#include <stdio.h>
#include <set>
#include <vector>
#include <map>

using namespace std;
int main() {

	int n;
	scanf("%d", &n);
	long long int walls[n-1];
	for (int i = 0; i < n-1; i++) {
		scanf("%lld", &walls[i]);
	}

	long long int left_loop[n], right_loop[n], left_best[n];

	//filling left loop
	left_loop[0] = 0;
	for (int i = 1; i < n; i++) {
		if (walls[i-1] < 2)
			left_loop[i] = 0;
		else
			left_loop[i] = left_loop[i-1] + (walls[i-1] - (walls[i-1] % 2));
	}

	

	//filling right loop
	right_loop[n-1] = 0;
	for (int i = n-2; i >= 0; i--) {
		if (walls[i] < 2)
			right_loop[i] = 0;
		else
			right_loop[i] = right_loop[i+1] + (walls[i] - (walls[i] % 2));
	}

	//filling left best
	left_best[0] = 0;
	for (int i = 1; i < n; i++) {
		long long int temp = left_best[i-1] + (walls[i-1] - (1 - walls[i-1] % 2));
		left_best[i] = max(temp, left_loop[i]);
	}
	
	long long int max_time = 0;
	for (int i = 0; i < n; i++)
		max_time = max(max_time, right_loop[i] + left_best[i]);

	printf("%lld", max_time);

	
  	return 0;
}