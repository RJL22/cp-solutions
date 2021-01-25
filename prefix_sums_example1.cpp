#include <iostream>
#include <vector>

int ans = 0;
int count = 0;



int main()
{
	int N;
	std::cin >> N;

	std::vector<int> ids(N);
	std::vector<int> cumulative(N);

	std::cin >> ids[0];
	cumulative[0] = ids[0];

	for (int i = 1; i < N; i++) {
		std::cin >> ids[i];
		cumulative[i] = cumulative[i - 1] + ids[i];
	}

	for (int i = N - 1; i > 0; i--) {
		for (int j = i - 1; j >= 0; j--) {
			if (cumulative[i] - cumulative[j] > ans && (cumulative[i] - cumulative[j]) % 7 == 0) {
				ans = cumulative[i] - cumulative[j];
				count = i - j;
			}
		}
	}

	std::cout << count << std::endl;


	return 0;
}