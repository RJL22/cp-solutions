#include <iostream>
#include <string>
#include <vector>


/*
USACO 2015 February Contest, Bronze
Short Summary: DFS on a 2d array
*/

std::string map[15];


void dfs(int currX, int currY, int R, int C, char prev, int& count)
{
	if (currX == C - 1 && currY == R - 1) {
		count++;
		return;
	}

	for (int i = currX; i < C; i++) {
		for (int j = currY; j < R; j++) {
			if (map[i][j] != prev) {
				dfs(i, j, R, C, map[i][j], count);
			}
		}
	}
}

int main()
{
	int R, C;

	std::cin >> R >> C;

	for (int i = 0; i < R; i++)
		std::cin >> map[i];

	int ans = 0;

	char first = map[0][0];

	dfs(0, 0, R, C, first, ans);

	std::cout << ans << std::endl;


}