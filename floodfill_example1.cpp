#include <iostream>
#include <string>
#include <vector>

std::string graph[1000];
bool visited[1000][1000];

int currentPerimeter = 0;
int currentArea = 0;

int xd[4] = {0, 1, 0, -1};
int yd[4] = {1, 0, -1, 0};


void floodfill(int x, int y, int n)
{
	if (x < 0 || x >= n || y < 0 || y >= n || graph[x][y] == '.') {
		currentPerimeter++;
		return;
	} else if (visited[x][y] == true) {
		return;
	} 

	visited[x][y] = true;
	currentArea++;
	for (int i = 0; i < 4; i++)
		floodfill(x + xd[i], y + yd[i], n);
}

int main()
{
	int N;

	int maximumArea = 0;
	int maximumPerimeter = 0;


	std::cin >> N;

	for (int i = 0; i < N; i++)
		std::cin >> graph[i];


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (graph[i][j] == '#' && visited[i][j] == false) {
				floodfill(i, j, N);
				if (currentArea > maximumArea) {
					maximumArea = currentArea;
					maximumPerimeter = currentPerimeter;
				} else if (currentArea == maximumArea && currentPerimeter < maximumPerimeter) {
					maximumArea = currentArea;
					maximumPerimeter = currentPerimeter;
				}
			}
			currentArea = 0;
			currentPerimeter = 0;
		}
	}

	std::cout << maximumArea << " " << maximumPerimeter << std::endl;

	return 0;
}