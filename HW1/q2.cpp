#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include <map>
#include <set>
#include <queue>

using namespace std;
int main() {

	int n;
	long int seed, maxd, factor;
	scanf("%d", &n);
	scanf("%ld\n", &seed);
	vector<long int> dprefix, tprefix;

	string line;
	getline(cin, line);
	line = line.substr(1, line.length() - 2);
	int pos = 0;
	if (line.length() != 0) {
		while (line.find(',', pos) < line.length()) {
		string num = line.substr(pos, line.find(',', pos) - pos);
		dprefix.push_back(stoi(num));
		pos = line.find(',', pos) + 2;
		}
		dprefix.push_back(stoi(line.substr(pos)));
	}

	scanf("%ld\n", &maxd);

	getline(cin, line);
	line = line.substr(1, line.length() - 2);
	pos = 0;
	if (line.length() != 0) {
		while (line.find(',', pos) < line.length()) {
			string num = line.substr(pos, line.find(',', pos) - pos);
			tprefix.push_back(stoi(num));
			pos = line.find(',', pos) + 2;
		}
		tprefix.push_back(stoi(line.substr(pos)));
	}

	scanf("%ld", &factor);

	long int random[2*n], d[n], t[n];
	random[0] = seed;
	for (int i = 0; i < 2*n; i++) {
		random[i] = (random[i-1] * 1103515245 + 12345) % (1 << 31);
	}
	for (int i = 0; i < dprefix.size(); i++) {
		d[i] = dprefix.at(i);
		t[i] = tprefix.at(i);
	}

	for (int i = dprefix.size(); i < n; i++) {
		d[i] = 1 + (random[2*i] % maxd);
		int frac = d[i] / factor;
		long int maxt = max(1, frac);
		t[i] = 1 + (random[2*i + 1] % maxt);
	}

	multimap<long int, long int> exams;
	for (int i = 0; i < n; i++) {
		exams.insert(pair<long int, long int>(d[i], t[i]));
	}
	long int time = 0;
	int count = 0;
	priority_queue<long int> times;

	for (int i = 0; i < n; i++) {
		long int d, t;
		d = exams.begin() -> first;
		t = exams.begin() -> second;
		times.push(t);
		time += t;
		exams.erase(exams.begin());
		if (time <= d) 
			count++;
		else {
			time -= times.top();
			times.pop();
		}
	}

	printf("%d", count);


  	return 0;
}
