#include <iostream>
#include <string>
#include <stdio.h>
#include <set>
#include <vector>
#include <map>

using namespace std;
int main() {

	int n, m;
	scanf("%d %d", &n, &m);
	long long int reward[n][m], br[n][m], tr[n][m], bl[n][m], tl[n][m] ;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%lld", &reward[i][j]);
		}
	}

	//filling top left array
	tl[0][0] = reward[0][0];
	for (int i = 1; i < n; i++) 
		tl[i][0] = tl[i-1][0] + reward[i][0];
	for (int j = 1; j < m; j++)
		tl[0][j] = tl[0][j-1] + reward[0][j];

	for (int i = 1; i < n; i++) 
		for (int j = 1; j < m; j++) 
			tl[i][j] = max(tl[i-1][j], tl[i][j-1]) + reward[i][j];


	//filling bottom left array
	bl[n-1][0] = reward[n-1][0];
	for (int i = n - 2; i >= 0; i--)
		bl[i][0] = bl[i+1][0] + reward[i][0];
	for (int j = 1; j < m; j++)
		bl[n-1][j] = bl[n-1][j-1] + reward[n-1][j];


	for (int i = n - 2; i >= 0; i--)
		for (int j = 1; j < m; j++)
			bl[i][j] = max(bl[i+1][j], bl[i][j-1]) + reward[i][j];


	//filling top right array
	tr[0][m-1] = reward[0][m-1];
	for (int i = 1; i < n; i++)
		tr[i][m-1] = tr[i-1][m-1] + reward[i][m-1];
	for (int j = m-2; j >= 0; j--)
		tr[0][j] = tr[0][j+1] + reward[0][j];

	for (int i = 1; i < n; i++)
		for (int j = m-2; j >= 0; j--)
			tr[i][j] = max(tr[i][j+1], tr[i-1][j]) + reward[i][j];

	//filling bottom right array
	br[n-1][m-1] = reward[n-1][m-1];
	for (int i = n-2; i >= 0; i--)
		br[i][m-1] = br[i+1][m-1] + reward[i][m-1];
	for (int j = m-2; j >= 0; j--)
		br[n-1][j] = br[n-1][j+1] + reward[n-1][j];

	for (int i = n-2; i >= 0; i--)
		for (int j = m-2; j >= 0; j--)
			br[i][j] = max(br[i][j+1], br[i+1][j]) + reward[i][j];

	//calculating max
	long long int max_reward = 0;
	for (int i = 1; i < n-1; i++) {
		for (int j = 1; j < m-1; j++) {
			long long int first, second, total;
			first = bl[i+1][j] + tl[i][j-1] + tr[i-1][j] + br[i][j+1];
			second = bl[i][j-1] + tl[i-1][j] + tr[i][j+1] + br[i+1][j];
			total = max(first, second) + reward[i][j];
			max_reward = max(max_reward, total);
		}
	}

	printf("%lld", max_reward);

	
  	return 0;
}