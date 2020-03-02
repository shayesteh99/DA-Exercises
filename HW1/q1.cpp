#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include <map>

using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int q, k;
	scanf("%d %d\n", &q, &k);
	vector<int> queue[k];
	multimap<int, int> begin;
	string a;
	for (int i = 0; i < q; i++) {
		getline(cin, a);
		if (a[0] == '+') {
			int p, s;
			p = stoi(a.substr(2, a.find(' ', 2) - 2));
			s = stoi(a.substr(a.find(' ', 2) + 1)) - 1;
			if (queue[s].size() == 0)
				begin.insert(pair<int, int>(p, s));

			queue[s].push_back(p);
		}
		else {
			if (begin.size() == 0)
				printf("all empty\n");
			else {
				int p, s;
				p = begin.rbegin() -> first;
				s = begin.rbegin() -> second;
				begin.erase(--begin.end());
				printf("%d\n", p);
				queue[s].erase(queue[s].begin());
				if (queue[s].size() != 0)
					begin.insert(pair<int, int>(*queue[s].begin(), s));
			}
		}
	}
  	return 0;
}