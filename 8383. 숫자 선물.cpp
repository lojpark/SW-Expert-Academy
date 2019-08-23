#include <iostream>
#include <vector>
#include <string>

using namespace std;
string a, answer;
int n, x, y;

struct Data {
	int phase;
	int index;
	bool less;
};
vector<Data> s;

bool dfs()
{
	int index;
	bool less;

	s.clear();
	s.push_back({ 1, 0, false });
	while (!s.empty()) {
		index = s.back().index;
		less = s.back().less;
		if (index == n) {
			return true;
		}

		if (s.back().phase == 1) {
			s.back().phase = 2;
			if (a[index] - '0' >= x || less) {
				answer.push_back(x + '0');
				if (a[index] - '0' > x) {
					s.push_back({ 1, index + 1, true });
					continue;
				}
				else {
					s.push_back({ 1, index + 1, less });
					continue;
				}
			}
		}
		if (s.back().phase == 2) {
			s.back().phase = 3;
			if (a[index] - '0' >= y) {
				if (y == 0 && answer.size() == 0) {
					s.push_back({ 1, index + 1, true });
					continue;
				}
				else {
					answer.push_back(y + '0');
					if (a[index] - '0' > y) {
						s.push_back({ 1, index + 1, true });
						continue;
					}
					else {
						s.push_back({ 1, index + 1, less });
						continue;
					}
				}
			}
		}

		if (s.back().phase == 3) {
			s.back().phase = 4;
			if (answer.size() == 0) {
				s.push_back({ 1, index + 1, true });
				continue;
			}
		}

		answer.pop_back();
		s.pop_back();
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		a.clear();
		answer.clear();
		cin >> a;
		cin >> x >> y;
		if (x < y) {
			n = x;
			x = y;
			y = n;
		}
		n = a.size();

		cout << "#" << t << " ";
		if (!dfs() || answer.size() == 0 || answer[0] == '0') {
			cout << "-1" << endl;
		}
		else {
			cout << answer << endl;
		}
	}

	return 0;
}