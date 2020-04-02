#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include <map>


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
	for (int i = 0; i< 6; i++)
		scanf("%d", &dice[i]);

	multimap<int, vector<int> > pathi, pathj, directs;
	map<int, bool> visited;
	vector<int> fi, fj, fd;
	fi.push_back(begi);
	fj.push_back(begj);
	for (int i = 0; i < 6; i++)
		fd.push_back(i);
	pathi.insert(pair<int, vector<int> >(dice[4], fi));
	pathj.insert(pair<int, vector<int> >(dice[4], fj));
	directs.insert(pair<int, vector<int> >(dice[4], fd));
	visited[begi * 1000 + begj * 100 + fd.at(0) * 10 + fd.at(2)] = true;

	while (!pathi.empty()) {
		int cost = pathi.begin() -> first;
		vector<int> pi = pathi.begin() -> second, pj = pathj.begin() -> second, d = directs.begin() -> second;
		if (pi.back() == endi && pj.back() == endj)
			break;

		visited[pi.back() * 1000 + pj.back() * 100 + d.at(0) * 10 + d.at(2)] = true;

		pathi.erase(pathi.begin());
		pathj.erase(pathj.begin());
		directs.erase(directs.begin());

		vector<int> newi, newj, newd;
		if (pi.back() > 0 && (pi.size() < 2 || pi.at(pi.size() - 2) != pi.back() - 1)) {
			newi = pi, newj = pj, newd = d;
			newd.at(0) = d.at(4);
			newd.at(1) = d.at(2);
			newd.at(2) = d.at(0);
			newd.at(3) = d.at(3);
			newd.at(4) = d.at(1);
			newd.at(5) = d.at(5);
			newi.push_back(pi.back() - 1);
			newj.push_back(pj.back());
			if (visited.count(newi.back() * 1000 + newj.back() * 100 + newd.at(0) * 10 + newd.at(2)) == 0) {
				pathi.insert(pair<int, vector<int> >(cost + dice[newd.at(4)], newi));
				pathj.insert(pair<int, vector<int> >(cost + dice[newd.at(4)], newj));
				directs.insert(pair<int, vector<int> >(cost + dice[newd.at(4)], newd));
			}

		}
		if (pi.back() < 7 && (pi.size() < 2 || pi.at(pi.size() - 2) != pi.back() + 1)) {
			newi = pi, newj = pj, newd = d;
			newd.at(0) = d.at(2);
			newd.at(1) = d.at(4);
			newd.at(2) = d.at(1);
			newd.at(3) = d.at(3);
			newd.at(4) = d.at(0);
			newd.at(5) = d.at(5);
			newi.push_back(pi.back() + 1);
			newj.push_back(pj.back());
			if (visited.count(newi.back() * 1000 + newj.back() * 100 + newd.at(0) * 10 + newd.at(2)) == 0) {
				pathi.insert(pair<int, vector<int> >(cost + dice[newd.at(4)], newi));
				pathj.insert(pair<int, vector<int> >(cost + dice[newd.at(4)], newj));
				directs.insert(pair<int, vector<int> >(cost + dice[newd.at(4)], newd));
			}
		}

		if (pj.back() > 0 && (pj.size() < 2 || pj.at(pj.size() - 2) != pj.back() - 1)) {
			newi = pi, newj = pj, newd = d;
			newd.at(0) = d.at(0);
			newd.at(1) = d.at(1);
			newd.at(2) = d.at(3);
			newd.at(3) = d.at(4);
			newd.at(4) = d.at(5);
			newd.at(5) = d.at(2);
			newi.push_back(pi.back());
			newj.push_back(pj.back() - 1);
			if (visited.count(newi.back() * 1000 + newj.back() * 100 + newd.at(0) * 10 + newd.at(2)) == 0) {
				pathi.insert(pair<int, vector<int> >(cost + dice[newd.at(4)], newi));
				pathj.insert(pair<int, vector<int> >(cost + dice[newd.at(4)], newj));
				directs.insert(pair<int, vector<int> >(cost + dice[newd.at(4)], newd));
			}
		}

		if (pj.back() < 7 && (pj.size() < 2 || pj.at(pj.size() - 2) != pj.back() + 1)) {
			newi = pi, newj = pj, newd = d;
			newd.at(0) = d.at(0);
			newd.at(1) = d.at(1);
			newd.at(2) = d.at(5);
			newd.at(3) = d.at(2);
			newd.at(4) = d.at(3);
			newd.at(5) = d.at(4);
			newi.push_back(pi.back());
			newj.push_back(pj.back() + 1);
			if (visited.count(newi.back() * 1000 + newj.back() * 100 + newd.at(0) * 10 + newd.at(2)) == 0) {
				pathi.insert(pair<int, vector<int> >(cost + dice[newd.at(4)], newi));
				pathj.insert(pair<int, vector<int> >(cost + dice[newd.at(4)], newj));
				directs.insert(pair<int, vector<int> >(cost + dice[newd.at(4)], newd));
			}
		}
	}

	printf("%d ", pathi.begin() -> first);

	for(int i = 0; i < (pathi.begin() -> second).size(); i++) {
		char col = (pathj.begin() -> second).at(i) + 'a';
		int row = 8 - (pathi.begin() -> second).at(i);
		printf("%c%d ", col, row);
	}




  	return 0;
}