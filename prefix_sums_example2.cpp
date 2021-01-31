#include <iostream>
#include <string>
#include <vector>

/*
Usaco 2021 January Contest (Silver)
Problem: No time to paint
Summary: Uses prefix sums
*/

int N, Q;

std::string colors;

bool containsColor(std::string colors, char color) {
	for (int i = 0; i < colors.length(); i++) {
		if (colors[i] == color)
			return true;
	}

	return false;
}

bool isLess(std::string colors, char color) {
	for (int i = 0; i < colors.length(); i++) {
		if (colors[i] < color) {
			return false;
		}
	}

	return true;
}

int main()
{
	std::cin >> N >> Q;
	std::cin >> colors;

	std::vector<int> prefix(N, 0);
	std::vector<int> suffix(N, 0);

	std::vector<std::pair<int, int>> segments(Q);

	for (int i = 0; i < Q; i++)
		std::cin >> segments[i].first >> segments[i].second;

	//Calculating prefixes

	prefix[0] = 1;
	suffix[N - 1] = 1;


	for (int i = 1; i < N; i++) {
		if (containsColor(colors.substr(0, i), colors[i]) && isLess(colors.substr(0, i), colors[i])) {
			prefix[i] = prefix[i - 1];
		} else {
			prefix[i] = prefix[i - 1] + 1;
		}

		if (containsColor(colors.substr(N - i, i), colors[i]) && isLess(colors.substr(N - i, i), colors[i])) {
			suffix[N - i - 1] = suffix[N - i];
		} else {
			suffix[N - i - 1] = suffix[N - i] + 1;
		}
	}

	int count = 0;
	
	for (int i = 0; i < Q; i++) {
		count = prefix[segments[i].first - 1] + suffix[segments[i].second - 1];
		std::cout << count << std::endl;
	}


	return 0;
}