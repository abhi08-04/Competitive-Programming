#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

auto suffix_array = [&](const string &s) -> vector<int> {
	int N = s.length(), stp, cnt;
	vector<vector<int>> P(17, vector<int>(N));
	vector<int> suffixArr(N);

	struct entry {
		int nr[2], p;
	};

	vector<entry> L(N);
	for (int i = 0; i < N; i++) P[0][i] = s[i] - 'a';

	for (stp = 1, cnt = 1; cnt < N; stp++, cnt *= 2) {
		for (int i = 0; i < N; i++) {
			L[i].nr[0] = P[stp - 1][i];
			L[i].nr[1] = i + cnt < N ? P[stp - 1][i + cnt] : -1;
			L[i].p = i;
		}

		sort(L.begin(), L.end(), [](entry a, entry b) {
			return a.nr[0] == b.nr[0] ? (a.nr[1] < b.nr[1] ? 1 : 0) : (a.nr[0] < b.nr[0] ? 1 : 0);
		});

		for (int i = 0; i < N; i++)
			P[stp][L[i].p] = i > 0 && L[i].nr[0] == L[i - 1].nr[0] && L[i].nr[1] == L[i - 1].nr[1]
			                 ? P[stp][L[i - 1].p]
			                 : i;
	}
	for (int i = 0; i < N; i++) {
		suffixArr[i] = L[i].p;
	}

	return suffixArr;
};

int main() {
	string s;
	cin >> s;  // Take input string

	vector<int> result = suffix_array(s);

	for (int i : result) {
		cout << i << " ";
	}
	cout << endl;

	return 0;
}
