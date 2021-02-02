#include <iostream>
#include <vector>
#include <cmath>

/*
USACO 2020 February Contest, Silver
Swapity Swapity Swap
*/

int a[100001];
int sol[100001];

int N, M, K;

int main()
{
	std::cin >> N >> M >> K;

	for (int i = 1; i <= N; i++) {
		a[i] = i;
	}

	for (int i = 0; i < M; i++) {
		int l, r;
		std::cin >> l >> r;

		for (int j = 0; j < ceil((float)(r-l)/2); j++) {
			int temp = a[l + j];
			a[l + j] = a[r - j];
			a[r - j] = temp;
		}
	}

	for (int i = 1; i <= N; i++) {
		std::vector<int> cycle;
		cycle.push_back(i);

		int start = a[i];
		while (start != i) {
			cycle.push_back(start);
			start = a[start];
			
		}

		int amt = K % cycle.size();

		sol[i] = cycle[amt];
	}


	for (int i = 1; i <= N; i++)
		std::cout << sol[i] << std::endl;

	return 0;
}